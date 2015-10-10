#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=100+10 ;

int dx[]={1,0,-1,0} , dy[]={0,1,0,-1} ;
char G[maxn][maxn] ;
int d[maxn][maxn][4] ;
int n,m ;
queue<int> q ;

bool check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return 0;
    if(G[x][y]=='#') return 0 ;
    return 1 ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        for(int k=0;k<4;k++) d[i][j][k]=INF ;

    q.push(0) ; q.push(0) ; q.push(0) ;
    d[0][0][0]=0 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        int dir=q.front() ; q.pop() ;
        int nx=x+dx[dir] , ny=y+dy[dir] ;
        if(check(x+2*dx[dir],y+2*dy[dir]) &&
            d[nx][ny][dir] > d[x][y][dir]+1)
            d[nx][ny][dir] = d[x][y][dir]+1 ,
            q.push(nx) , q.push(ny) , q.push(dir) ;
        for(int i=0;i<2;i++)
        {
            int nd=(dir+2*i+1)%4 ;
            if(!check(x+dx[nd],y+dy[nd]) ||
               !check(x+dx[nd]+dx[dir],y+dy[nd]+dy[dir]))
                continue ;

            nx=x , ny=y ;
            if(d[nx][ny][nd] > d[x][y][dir]+1)
                d[nx][ny][nd]=d[x][y][dir]+1 ,
                q.push(nx) , q.push(ny) , q.push(nd) ;

            nx=x+dx[dir]+dx[nd] ;
            ny=y+dy[dir]+dy[nd] ;
            nd=(nd+2)%4 ;
            if(d[nx][ny][nd] > d[x][y][dir]+1)
                d[nx][ny][nd]=d[x][y][dir]+1 ,
                q.push(nx) , q.push(ny) , q.push(nd) ;
        }
    }
    int ans=d[n-2][m-1][0] ;
    if(ans==INF) printf("No Way!\n") ;
    else printf("%d\n",ans) ;
}
