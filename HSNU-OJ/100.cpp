#include<bits/stdc++.h>
using namespace std;
const int maxn=100010 ;
vector<int> v0[maxn],v1[maxn],v2[maxn] ;
vector<int> havee[maxn] ;
bool vis[maxn] ;
int n,ccnt,id,gp[maxn] ;
int scnt,t,topo[maxn],scc[maxn] ;
bool in[maxn] ;

void dfs0(int x)
{
    gp[x]=ccnt ; vis[x]=1 ;
    for(;id<=n&&vis[id];id++) ;
    int j=0 ; for(;j<havee[x].size() && havee[x][j]<id;j++) ;

    for(int i=id;i<=n;i= max(i+1,id)) if(!vis[i])
    {
        for(;j<havee[x].size() && havee[x][j]<i;j++) ;
        if(j<havee[x].size() && i==havee[x][j]) { j++ ;  continue ; }
        for(;id<=n&&vis[id];id++) ;
        dfs0(i) ;
        for(;id<=n&&vis[id];id++) ;
    }
}

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

vector<int> ANS ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int t ; scanf("%d",&t) ;
        while(t--)
        {
            int x ; scanf("%d",&x) ;
            v0[i].push_back(x) ;
            havee[i].push_back(x) ;
            havee[x].push_back(i) ;
        }
    }
    for(int i=1;i<=n;i++) sort(havee[i].begin(),havee[i].end()) ;
    memset(vis,0,sizeof(vis)) ;
    ccnt=0 ; id=1 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        ccnt++ , dfs0(i) ;
    for(int i=1;i<=n;i++) havee[i].clear() ;

    for(int i=1;i<=n;i++) for(int j=0;j<v0[i].size();j++)
        if(gp[i] != gp[v0[i][j]])
        v1[gp[i]].push_back(gp[v0[i][j]]) ,
        v2[gp[v0[i][j]]].push_back(gp[i]) ;
    for(int i=1;i<=n;i++) v0[i].clear() ;

    for(int i=1;i<=ccnt;i++)
    {
        sort(v1[i].begin(),v1[i].end()) ;
        v1[i].resize(unique(v1[i].begin(),v1[i].end())-v1[i].begin()) ;
        sort(v2[i].begin(),v2[i].end()) ;
        v2[i].resize(unique(v2[i].begin(),v2[i].end())-v2[i].begin()) ;
    }

    memset(vis,0,sizeof(vis)) ;
    t=ccnt+1 ;
    for(int i=1;i<=ccnt;i++) if(!vis[i]) dfs1(i) ;
    scnt=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=ccnt;i++) if(!vis[topo[i]]) scnt++ , dfs2(topo[i]) ;

    memset(in,0,sizeof(in)) ;
    for(int i=1;i<=ccnt;i++) for(int j=0;j<v1[i].size();j++)
        in[scc[v1[i][j]]]=1 ;
    int ans ;
    for(ans=1;ans<=scnt && in[ans];ans++) ;
    for(int i=1;i<=n;i++) if(scc[gp[i]]==ans) ANS.push_back(i) ;
    printf("%d",ANS.size()) ;
    for(int i=0;i<ANS.size();i++) printf(" %d",ANS[i]) ;
    printf("\n") ;
}
