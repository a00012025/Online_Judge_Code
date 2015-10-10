#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

vector<int> v1[maxn],v2[maxn],v[maxn] ;
bool vis[maxn] ;
int t,topo[maxn],scnt,scc[maxn] ;
int sz[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i])
        dfs1(i) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ;
    sz[scnt]++ ;
    for(auto i : v2[x]) if(!vis[i])
        dfs2(i) ;
}

int d[maxn] ;
int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    int &ans=d[x] ; ans=sz[x] ;
    for(auto i : v[x]) ans=max(ans,sz[x]+dp(i)) ;
    return ans ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++)
            v1[i].clear() , v2[i].clear() , v[i].clear() ;
        memset(sz,0,sizeof(sz)) ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v1[x].push_back(y) ;
            v2[y].push_back(x) ;
        }

        t=n+1 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++) if(!vis[i])
            dfs1(i) ;

        scnt=0 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++) if(!vis[topo[i]])
            scnt++ , dfs2(topo[i]) ;

        for(int i=1;i<=n;i++) for(auto j : v1[i])
            if(scc[i]!=scc[j]) v[scc[i]].push_back(scc[j]) ;

        for(int i=1;i<=scnt;i++)
            sort(v[i].begin(),v[i].end()) ,
            v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin()) ;

        int ans=0 ;
        memset(d,-1,sizeof(d)) ;
        for(int i=1;i<=scnt;i++) ans=max(ans,dp(i)) ;
        printf("%d\n",ans) ;
    }
}
