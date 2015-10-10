#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=500001 ;

vector<int> v1[maxn],v2[maxn],v[maxn] ;
int n ;
int scc[maxn],scnt,topo[maxn],t ;
int num1[maxn],num[maxn] ;
bool bar[maxn],vis[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v1[x].size();i++) if(!vis[v1[x][i]])
        dfs1(v1[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

void SCC()
{
    memset(vis,0,sizeof(vis)) ;
    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    scnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]])
        scnt++ , dfs2(topo[i]) ;

    for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
        if(scc[i]!=scc[v1[i][j]])
        v[scc[i]].push_back(scc[v1[i][j]]) ;
    for(int i=1;i<=scnt;i++)
    {
        sort(v[i].begin(),v[i].end()) ;
        v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin()) ;
    }

    for(int i=1;i<=n;i++) num[scc[i]]+=num1[i] ;
}

int d[maxn] ;
int dp(int x)
{
    if(d[x]!=-1) return d[x] ;

    int &ans=d[x] ; ans= bar[x] ? num[x] : -INF ;
    for(int i=0;i<v[x].size();i++)
        ans=max(ans,num[x]+dp(v[x][i])) ;
    return ans ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
    }
    for(int i=1;i<=n;i++) scanf("%d",&num1[i]) ;
    SCC() ;

    int st,p ; scanf("%d%d",&st,&p) ;
    while(p--)
    {
        int x ; scanf("%d",&x) ;
        bar[scc[x]]=1 ;
    }

    memset(d,-1,sizeof(d)) ;
    printf("%d\n",dp(scc[st])) ;
}
