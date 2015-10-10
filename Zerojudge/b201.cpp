#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v1[101000],v2[101000] ;
int topo[101000],ans[101000],t,scc ;
bool vis[101000] ;

void dfs1(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    for(int i=0;i<v1[n].size();i++) dfs1(v1[n][i]) ;
    topo[--t]=n ;
}

void dfs2(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    ans[scc]++ ;
    for(int i=0;i<v2[n].size();i++) dfs2(v2[n][i]) ;
}

main()
{
    int m,n ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++) {v1[i].clear() ; v2[i].clear() ;}
        memset(ans,0,sizeof(ans)) ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            v1[a].push_back(b) ;
            v2[b].push_back(a) ;
        }
        memset(vis,0,sizeof(vis)) ;
        t=n+1 ;
        for(int i=1;i<=n;i++) dfs1(i) ;
        memset(vis,0,sizeof(vis)) ;
        scc=0 ;
        for(int i=1;i<=n;i++)
        {
            if(vis[topo[i]]) continue ;
            scc++ ;
            dfs2(topo[i]) ;
        }
        sort(ans+1,ans+scc+1) ;
        for(int i=1;i<=scc;i++) printf("%d ",ans[i]) ;
        printf("\n") ;
    }
}

