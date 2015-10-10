/**********************************************************************************/
/*  Problem: a593 "F. 畫蚯蚓" from 2012 NPSC 高中組初賽                   */
/*  Language: CPP (1233 Bytes)                                                    */
/*  Result: AC(552ms, 44MB) judge by this@ZeroJudge                               */
/*  Author: liouzhou_101 at 2013-02-02 19:08:03                                   */
/**********************************************************************************/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=1000010;

int n;
char s[MaxN];
int p[MaxN];
vector<int> v[MaxN];
int u[MaxN];

void init()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=0;i<=n;++i)
	{
		v[i].clear();
		u[i]=0;
	}
	for (int i=2;i<=n;++i)
	{
		int j=p[i-1];
		while (j)
		{
			if (s[j+1]==s[i]) break;
			j=p[j];
		}
		p[i]=j+(s[j+1]==s[i]);
	}
	for (int i=n;i;i=p[i])
		u[i]=1;
}

int F[MaxN];

int father(int x)
{
	return (F[x]==x)?x:F[x]=father(F[x]);
}

void work()
{
	for (int i=n;i>=1;--i)
		F[i]=(u[i])?i:p[i];
	for (int i=1;i<=n;++i)
		v[father(i)].push_back(i);
	for (int i=1;i<=n;++i)
		F[i]=i-1;
	for (int i=1;i<=n;++i)
		if (u[i])
			for (int j=0;j<v[i].size();++j)
				F[v[i][j]]=v[i][j];
	int ans=n;
	for (int i=1;i<=n;++i)
	{
		if (!u[i]) continue;
		int t=1,x=i;
		while (x!=n)
		{
			int y=father(min(x+i,n));
			if (x>=y) break;
			++t;
			x=y;
		}
		if (x==n) ans=max(ans,i*t);
		for (int j=0;j<v[i].size();++j)
			F[v[i][j]]=father(v[i][j]-1);
	}
	cout<<ans<<endl;
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		init();
		work();
	}
	return 0;
}
