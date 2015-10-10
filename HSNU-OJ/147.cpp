#include<bits/stdc++.h>
using namespace std;
const int maxn=32000+10 ;

vector<int> v[maxn],v2[maxn],gp[maxn] ;
int n ;
bool vis[maxn] ;
int topo[maxn],scc[maxn],t,scnt ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs1(v[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ; gp[scnt].push_back(x) ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

void SCC()
{
    for(int i=1;i<=4*n;i++) for(int j=0;j<v[i].size();j++)
        v2[v[i][j]].push_back(i) ;
    memset(vis,0,sizeof(vis)) ;
    t=4*n+1 ;
    for(int i=1;i<=4*n;i++) if(!vis[i]) dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    scnt=0 ;
    for(int i=1;i<=4*n;i++) if(!vis[topo[i]])
    {
        scnt++ ;
        dfs2(topo[i]) ;
    }
    /// point : 1 ~ 4*n
}

inline int adj(int x)
{
    if(x<=2*n) return x+2*n ;
    else return x-2*n ;
}

int ans[maxn] ;

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) /// i : i yes , i+2n : i no
    {
        v[2*i].push_back(2*i-1+2*n) ;
        v[2*i+2*n].push_back(2*i-1) ;
        v[2*i-1].push_back(2*i+2*n) ;
        v[2*i-1+2*n].push_back(2*i) ;
    }
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y+2*n) ;
        v[y].push_back(x+2*n) ;
    }
    SCC() ;
    for(int i=1;i<=2*n;i++) if(scc[i]==scc[i+2*n]){ printf("-1\n") ; return 0 ; }
    memset(ans,-1,sizeof(ans)) ;
    for(int i=scnt;i>=1;i--)
    {
        bool ok=1 ;
        for(int j=0;j<gp[i].size();j++) if(ans[adj(gp[i][j])]==1) { ok=0 ; break ; }
        for(int j=0;j<gp[i].size();j++) ans[gp[i][j]]=ok ;
    }
    for(int i=1;i<=2*n;i++) if(ans[i]) printf("%d\n",i) ;
}
