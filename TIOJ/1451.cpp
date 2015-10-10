#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v1[maxn],v2[maxn] ;
int topo[maxn],t,scnt,scc[maxn] ;
bool vis[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i])
        dfs1(i) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    scc[x]=scnt ;
    vis[x]=1 ;
    for(auto i : v2[x]) if(!vis[i])
        dfs2(i) ;
}

bool in[maxn] ;
main()
{
    int n,m ;
    scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
    }

    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    scnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]])
        scnt++ , dfs2(topo[i]) ;

    for(int i=1;i<=n;i++) for(auto j : v1[i])
        if(scc[i]!=scc[j]) in[scc[j]]=1 ;

    int ans=0 ;
    for(int i=1;i<=scnt;i++) if(!in[i]) ans++ ;
    printf("%d\n",ans) ;
}
