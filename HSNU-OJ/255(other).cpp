#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1100010

using namespace std;
typedef pair<int, int> pii;

int n, val[MAXN], l[MAXN], r[MAXN];

void inline input()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", val + i), l[i] = 0, r[i] = n + 1;
}

stack<int> st;

void inline FindLR() // l[i] : 左邊第一個比val[i]大 , r[i] : 右邊第一個比val[i]小
{
	st.push(n);
	for(int i = n - 1; i > 0; i--)
	{
		while(st.size() && val[i] > val[st.top()])
		{
			l[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size())
	{
		l[st.top()] = 0;
		st.pop();
	}

	st.push(1);
	for(int i = 2; i <= n; i++)
	{
		while(st.size() && val[i] < val[st.top()])
		{
			r[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(st.size())
	{
		r[st.top()] = n + 1;
		st.pop();
	}
}

vector<int> part[MAXN << 1];
vector<pii> interval;

void inline GetInterval(vector<int> a)
{
	while(st.size())
		st.pop();
	st.push(a[a.size() - 1]);
	for(int i = a.size() - 2; i >= 0; i--)
	{
		while(st.size() && l[st.top()] >= a[i])
			st.pop();
		if(st.size() && r[a[i]] > st.top())
		{
			interval.push_back(pii(a[i], st.top()));
			//printf("[%d, %d]\n", a[i], st.top());
		}
		st.push(a[i]);
	}
}

void inline FindInterval()
{
	for(int i = 1; i <= n; i++)
		part[val[i] - i + n].push_back(i);
	for(int i = 0; i <= 2*n; i++)
		if(part[i].size())
			GetInterval(part[i]);
}

vector<pii> ac;

void inline ProcessInterval()
{
	sort(interval.begin(), interval.end());
	for(int i = 0; i < interval.size() - 1; i++)
		if(interval[i].second >= interval[i + 1].second)
			continue;
		else
			ac.push_back(interval[i]);
	if(interval.size())
		ac.push_back(interval[interval.size() - 1]);
	printf("%d\n", ac.size());
	for(int i = 0; i < ac.size(); i++)
		printf("%d %d\n", ac[i].first, ac[i].second);
}

void inline solve()
{
	FindLR();
	FindInterval();
	ProcessInterval();
}

int main()
{
	input();
	solve();
}
