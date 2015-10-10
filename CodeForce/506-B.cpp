#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v1[maxn],v2[maxn],v[maxn] ;
vector<int> SCC[maxn] ;
int t,topo[maxn] ;
int scc[maxn],scnt=0 ;
bool vis[maxn] ;
int cnt ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v1[x].size();i++) if(!vis[v1[x][i]])
        dfs1(v1[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ; SCC[scnt].push_back(x) ; cnt++ ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

void dfs3(int x)
{
    vis[x]=1 ; cnt++ ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs3(v[x][i]) ;
}

vector<int> tmp ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
    }

    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        dfs1(i) ;

    memset(vis,0,sizeof(vis)) ;
    int ans=0 , cnt2=0 ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]])
    {
        cnt=0 , scnt++ ;
        dfs2(topo[i]) ;
        if(cnt>1) ans+=cnt , tmp.push_back(scnt) ;
        else cnt2++ ;
    }

    if(!tmp.empty())
    {
        int id=tmp[0] ;
        for(int i=1;i<=n;i++) if(SCC[scc[i]].size()>1)
            scc[i]=id ;
    }

    for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
    {
        int i2=v1[i][j] ;
        if(scc[i]!=scc[i2])
            v[scc[i]].push_back(scc[i2]) ,
            v[scc[i2]].push_back(scc[i]) ;
    }

    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=scnt;i++) if(!vis[i])
    {
        cnt=0 ;
        dfs3(i) ;
        ans+=cnt-1 ;
    }
    printf("%d\n",min(ans,min(n,m))) ;
}
