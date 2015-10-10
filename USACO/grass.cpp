#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=100000+10 ;

vector<int> v1[maxn],v2[maxn],v[maxn] ;
bool vis[maxn] ;
int topo[maxn],t ;
int scnt,scc[maxn],size[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i])
        dfs1(i) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ; size[scnt]++ ;
    for(auto i : v2[x]) if(!vis[i])
        dfs2(i) ;
}

int d1[maxn],d2[maxn] ;
int dp(int x,int *d)
{
    if(d[x]!=-INF) return d[x] ;
    if(x==scc[1]) return d[x]=size[scc[1]] ;

    for(auto i : v[x]) d[x]=max(d[x],size[x]+dp(i,d)) ;
    return d[x] ;
}

main()
{
    if(fopen("grass.in","r"))
    {
        freopen("grass.in","r",stdin) ;
        freopen("grass.out","w",stdout) ;
    }
    int n,m ; scanf("%d%d",&n,&m) ;
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
        if(scc[i]!=scc[j]) v[scc[i]].push_back(scc[j]) ;
    fill(d1+1,d1+n+1,-INF) ;
    for(int i=1;i<=scnt;i++) dp(i,d1) ;

    for(int i=1;i<=scnt;i++) v[i].clear() ;
    for(int i=1;i<=n;i++) for(auto j : v1[i])
        if(scc[i]!=scc[j]) v[scc[j]].push_back(scc[i]) ;
    fill(d2+1,d2+n+1,-INF) ;
    for(int i=1;i<=scnt;i++) dp(i,d2) ;

    int ans=0 ;
    for(int i=1;i<=n;i++) for(auto j : v1[i])
        ans=max(ans,d1[scc[i]]+d2[scc[j]]-size[scc[1]]) ;
    printf("%d\n",ans) ;
}
