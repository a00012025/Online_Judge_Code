#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int G[105][105],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n,m ;

queue<int> q ;
bool vis[105][105],can[105][105] ;
int height[105][105] ;

int BFS(int x0,int y0)
{
    memset(vis,0,sizeof(vis)) ;
    while(!q.empty()) q.pop() ;
    q.push(x0) ; q.push(y0) ; vis[x0][y0]=1 ;
    int h=G[x0][y0] , minh=10001 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        if(x==1 || x==n || y==1 || y==m) { height[x0][y0]=h ; return 0 ; }
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m || vis[nx][ny]) continue ;
            if(G[nx][ny]>h) { minh=min(minh,height[nx][ny]) ; continue ; }
            vis[nx][ny]=1 ; q.push(nx) ; q.push(ny) ;
        }
    }
    height[x0][y0]=minh ;
    return minh-h ;
}

pii p[10010] ;
main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&G[i][j]) , p[m*(i-1)+(j-1)]={i,j} ;

    int M=0 ;
    for(int i=1;i<=n;i++) q.push(i) , q.push(1) , q.push(i) , q.push(m) ;
    for(int i=2;i<m;i++) q.push(1) , q.push(i) , q.push(n) , q.push(i) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        can[x][y]=1 ; vis[x][y]=1 ; height[x][y]=G[x][y] ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m || G[nx][ny]<G[x][y]) continue ;
            if(can[nx][ny]) continue ;
            can[nx][ny]=1 ; q.push(nx) ; q.push(ny) ;
        }
    }

    sort(p,p+m*n,
         [](const pii &x,const pii &y){ return G[x.F][x.S]>G[y.F][y.S] ; }
         ) ;

    int ans=0 ;
    for(int i=0;i<n*m;i++) if(!can[p[i].F][p[i].S])
        ans+=BFS(p[i].F,p[i].S) ;
    printf("%d\n",ans) ;
}
