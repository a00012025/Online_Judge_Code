#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=50+3 ;

int G[maxn][maxn][maxn] ;
int d[maxn][maxn][maxn],type[maxn][maxn][maxn] ;
int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1} ;

void print_ans(int x,int y,int z)
{
    if(!x && !y && !z) { printf("(1,1,1)") ; return ; }
    int t=type[x][y][z] ;
    print_ans(x-dx[t],y-dy[t],z-dz[t]) ;
    printf("->(%d,%d,%d)",x+1,y+1,z+1) ;
}

queue<int> q ;
main()
{
    int n,m,p ; scanf("%d%d%d",&n,&m,&p) ;
//    swap(n,m) ;
    for(int i=0;i<p;i++) for(int j=0;j<m;j++)
        for(int k=0;k<n;k++)
            scanf("%d",&G[k][j][i]) , d[k][j][i]=INF ;

    d[0][0][0]=1 ;
    if(!G[0][0][0]) for(int i=0;i<3;i++) q.push(0) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        int z=q.front() ; q.pop() ;
        for(int i=0;i<6;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] , nz=z+dz[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=p) continue ;
            if(G[nx][ny][nz] || d[nx][ny][nz]!=INF) continue ;
            d[nx][ny][nz]=d[x][y][z]+1 ;
            type[nx][ny][nz]=i ;
            q.push(nx) ; q.push(ny) ; q.push(nz) ;
        }
    }
    if(d[n-1][m-1][p-1]==INF) printf("no route") ;
    else print_ans(n-1,m-1,p-1) ;
    printf("\n") ;
}
