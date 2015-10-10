#include<bits/stdc++.h>
using namespace std;

bool vis[10][10],vis2[8][8] ;
int dx[]={1,-1,0,0} ;
int dy[]={0,0,1,-1} ;
int n,ex,ey,cnt ;

void dfs0(int x,int y)
{
    vis2[x][y]=1 ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<1||nx>n||ny<1||ny>n||vis[nx][ny]) continue ;
        if(vis2[nx][ny]) continue ;
        dfs0(nx,ny) ;
    }
}

bool check(int x,int y)
{
    memset(vis2,0,sizeof(vis2)) ;
    dfs0(x,y) ;
    return vis2[ex][ey] ;
}

int dfs(int x,int y,int dir)
{
    if(x==ex&&y==ey&&cnt==n*n) return 1 ;
    if(x==ex&&y==ey) return 0 ;
    if(!check(x,y)) return 0 ;
    int ret=0 ;
    for(int i=0;i<4;i++) if(i!=(dir^1))
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<1||nx>n||ny<1||ny>n||vis[nx][ny]) continue ;
        cnt++ ; vis[nx][ny]=1 ;
        ret+=dfs(nx,ny,i) ;
        cnt-- ; vis[nx][ny]=0 ;
    }
    return ret ;
}

main()
{
    int sx,sy ;
    while(scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey)!=EOF)
    {
        memset(vis,0,sizeof(vis)) ;
        vis[sx][sy]=1 ;
        cnt=1 ;
        printf("%d\n",dfs(sx,sy,-1)) ;
    }
}
