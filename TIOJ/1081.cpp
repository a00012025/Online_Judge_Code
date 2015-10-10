#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
int dx[]={1,1,0,-1,-1,-1,0,1} ;
int dy[]={0,1,1,1,0,-1,-1,-1} ;
bool vis[maxn][maxn] ;
char G[maxn][maxn] ;
int n,m ;
void dfs(int x,int y)
{
    vis[x][y]=1 ;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(G[nx][ny]!='1' || vis[nx][ny]) continue ;
        dfs(nx,ny) ;
    }
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        memset(vis,0,sizeof(vis)) ;
        int cnt=0 ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(G[i][j]=='1' && !vis[i][j])
        {
            dfs(i,j) ;
            cnt++ ;
        }
        printf("%d\n",cnt) ;
    }
}
