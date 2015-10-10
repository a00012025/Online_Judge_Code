#include<bits/stdc++.h>
using namespace std;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n,m ;
int G[10][10],ans,num=0 ;
bool vis[2][7][7],vis2[2][7][7] ;

int num2 ;
void dfs2(int x,int y,int t)
{
    vis2[t][x][y]=1 ; num2+=G[x][y] ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(G[nx][ny]==-1 || vis[t][nx][ny]) continue ;
        if(vis2[t][nx][ny]) continue ;
        dfs2(nx,ny,t) ;
    }
}

bool check(int x,int y,int t)
{
    memset(vis2[t],0,sizeof(vis2[t])) ;
    num2=0 ;
    dfs2(x,y,t) ;
    return vis2[t][n-1][m-1] && (t==0 || num2+num > ans) ;
}

void dfs(int x,int y,int t)
{
    if(!check(x,y,t)) return ;
    if(t==1 && x==n-1 && y==m-1) { ans=max(ans,num) ; return ; }
    if(x==n-1 && y==m-1) { dfs(0,0,1) ; return ; }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(G[nx][ny]==-1 || vis[t][nx][ny]) continue ;
        int tmp=G[nx][ny] ;
        G[nx][ny]=0 ; vis[t][nx][ny]=1 ; num+=tmp ;
        dfs(nx,ny,t) ;
        G[nx][ny]=tmp ; vis[t][nx][ny]=0 ; num-=tmp ;
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        char s[5] ; scanf("%s",s) ;
        if(s[0]=='x') G[i][j]=-1 ;
        else G[i][j]=s[0]-'0' ;
    }
    ans=0 ;
    vis[0][0][0]=1 ;
    num=G[0][0] ; G[0][0]=0 ;
    dfs(0,0,0) ;
    printf("%d\n",ans) ;
}
