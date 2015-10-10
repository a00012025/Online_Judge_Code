#include<bits/stdc++.h>
using namespace std;

int G[3001][3001],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
bool vis[3001][3001] ;
int n,m ;

int dfs(int x,int y)
{
    int ret=1 ;
    vis[x][y]=1 ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<1 || nx>n || ny<1 || ny>m) continue ;
        if(vis[nx][ny] || G[nx][ny]!=G[x][y]) continue ;
        ret+=dfs(nx,ny) ;
    }
    return ret ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&G[i][j]) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(!vis[i][j]) ans=max(ans,dfs(i,j)) ;
    printf("%d\n",ans) ;
}
