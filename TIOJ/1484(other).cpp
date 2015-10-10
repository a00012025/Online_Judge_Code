#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<int> v[200000];
int vi[200000];

bool OK;
bool visit[200000];
bool in[200000];

stack<int> stk;

int T;
int N, M;

int cnt;

void DFS(int O)
{
    visit[O] = true;

    for(int vi = 0; vi < v[O].size(); vi++)
        if( !visit[v[O][vi] ] ) DFS(v[O][vi] );
}

void process(int O)
{
    visit[O] = true;
    in[O] = true;
    stk.push(O);
    cnt++;

    for(; vi[O] < v[O].size(); )
    {
        int t = v[O][vi[O] ];

        if( !visit[t] ) process(t);
        else if( in[t] )
        {
            while( stk.top() != t ) stk.pop();
        }
        else OK = false;

        vi[O]++;

        if( stk.top() != O )
        {
            in[O] = false;
            cnt--;
            return;
        }
    }

    in[O] = false;
    stk.pop();
    cnt--;

    if( cnt ) OK = false;
}

int main()
{
    scanf("%d", &T);

    while( T-- )
    {
        scanf("%d %d", &N, &M);

        OK = true;

        while( !stk.empty() ) stk.pop();

        for(int Ni = 0; Ni < N; Ni++)
            v[Ni].clear(), vi[Ni] = 0;

        for(int Mi = 0; Mi < M; Mi++)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            v[x].push_back(y);
        }

        fill(visit, visit+N, false);
        DFS(0);

        for(int Ni = 0; Ni < N; Ni++)
            if( !visit[Ni] ) OK = false;

        fill(visit, visit+N, false);
        fill(in, in+N, false);

        cnt = 0;

        for(int Ni = 0; Ni < N; Ni++)
            while( vi[Ni] != v[Ni].size() ) process(Ni);

        if( OK ) puts("YES");
        else puts("NO");
    }
}
