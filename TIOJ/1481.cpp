#include<bits/stdc++.h>
#include"lib1481.h"
using namespace std;
const int maxn=5000+10 , maxm=1000000+10 ;

struct P{int from,to;};

bool vis[maxn] ;
int ans[maxm],cnt=0 ;
vector<int> v[maxn] ;
vector<P> edge ;

void dfs(int x)
{
    for(auto i : v[x]) if(!vis[i])
    {
        int to= edge[i].from==x ? edge[i].to : edge[i].from ;
        vis[i]=1 ; ans[i]=++cnt ;
        dfs(to) ;
    }
}

main()
{
    Init() ;
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=0;i<k;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        edge.push_back((P){x,y}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    Possible() ;
    dfs(1) ;
    for(int i=0;i<k;i++) Number(ans[i]) ;
    Finish() ;
}
