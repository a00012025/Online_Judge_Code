#include<bits/stdc++.h>
using namespace std;
const int maxn=50+10 ;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n,m ;
char G[maxn][maxn] ;
bool vis[maxn][maxn] ;
bool dfs(int x,int y,int fx,int fy)
{
    vis[x][y]=1 ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if((nx==fx&&ny==fy)||G[x][y]!=G[nx][ny]) continue ;
        if(vis[nx][ny]||!dfs(nx,ny,x,y)) return 0 ;
    }
    return 1 ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(!vis[i][j] && !dfs(i,j,-1,-1)){printf("Yes\n") ; return 0 ;}
    printf("No\n") ;
}
