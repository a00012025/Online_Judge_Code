#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> v[10101] ;
int ans[10101],vis[10101],z ;

void dfs(int n)
{
    vis[n]=1 ; ans[z]++ ;
    for(int i=0;i<v[n].size();i++)
        if(!vis[v[n][i]]) dfs(v[n][i]) ;
}

void dfs2(int n)
{
    vis[n]=2 ; ans[n]=ans[z] ;
    for(int i=0;i<v[n].size();i++)
        if(vis[v[n][i]]==1) dfs2(v[n][i]) ;
}

main()
{
    int T,tc=0 ;
    scanf("%d",&T) ;
    while(++tc && T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        memset(ans,0,sizeof(ans)) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        for(z=1;z<=n;z++)
        {
            if(vis[z]) continue ;
            ans[z]-- ;
            dfs(z) ;
            dfs2(z) ;
        }
        printf("Case #%d:\n%d",tc,ans[1]);
        for(int i=2;i<=n;i++)printf(" %d",ans[i]) ;
        printf("\n") ;
    }
}
