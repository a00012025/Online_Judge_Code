#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
bool vis[101] ;
vector<int> v1[101],v2[101] ;
int win,lose ;

void dfs1(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v1[n].size();i++)
    {
        if(vis[v1[n][i]]) continue ;
        win++ ; dfs1(v1[n][i]) ;
    }
}

void dfs2(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v2[n].size();i++)
    {
        if(vis[v2[n][i]]) continue ;
        lose++ ; dfs2(v2[n][i]) ;
    }
}

main()
{
    int n,m ;
    scanf("%d %d",&n,&m) ;
    for(int i=0;i<=n;i++) {v1[i].clear(); v2[i].clear();}
    for(int i=1;i<=m;i++)
    {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        v1[a].push_back(b) ;
        v2[b].push_back(a) ;
    }
    int cnt=0,ans[101] ;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis)) ;
        win=0 ;
        dfs1(i) ;
        memset(vis,0,sizeof(vis)) ;
        lose=0 ;
        dfs2(i) ;
        if(win+lose==n-1) ans[++cnt]=i ;
    }
    if(cnt) for(int i=1;i<=cnt;i++) printf("%d ",ans[i]) ;
    else printf("non") ;
    printf("\n") ;
}
