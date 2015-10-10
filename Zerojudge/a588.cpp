#include<stdio.h>
#include<string.h>
int edge[2][11][11],n1,n2,ans[11] ;
bool vis[11] ;

bool check(int n)
{
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(edge[1][i][j]!=edge[0][ans[i]][ans[j]]) return false ;
    return true ;
}

bool dfs(int n)
{
    if(n==n2) return true ;
    for(int i=0;i<n1;i++)
    {
        if(vis[i]) continue ;
        ans[n+1]=i ;
        if(check(n+1))
        {
            vis[i]=1 ;
            if(dfs(n+1)) return true ;
            vis[i]=0 ;
        }
    }
    return false ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        memset(edge,0,sizeof(edge)) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<2;i++)
        {
            int m ;
            if(!i) scanf("%d %d",&n1,&m) ;
            else scanf("%d %d",&n2,&m) ;
            for(int j=1;j<=m;j++)
            {
                int a,b ;
                scanf("%d %d",&a,&b) ;
                edge[i][a][b]++ ; edge[i][b][a]++ ;
            }
        }
        ans[0]=-1 ;
        if(dfs(0)) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
