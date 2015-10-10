#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=1200+10 ;

int dx[]={0,-3,-4,-5,-4,-3,0,3,4,5,4,3} ;
int dy[]={5,4,3,0,-3,-4,-5,-4,-3,0,3,4} ;
int chx[12][4]={{0,0,0,0},{-1,-1,-2,-2},{-1,-2,-2,-3},{-1,-2,-3,-4},
{-1,-2,-2,-3},{-1,-1,-2,-2},{0,0,0,0},{1,1,2,2},{1,2,2,3},
{1,2,3,4},{1,2,2,3},{1,1,2,2}} ;
int chy[12][4]={{1,2,3,4},{1,2,2,3},{1,1,2,2},{0,0,0,0},{-1,-1,-2,-2},
{-1,-2,-2,-3},{-1,-2,-3,-4},{-1,-2,-2,-3},{-1,-1,-2,-2},
{0,0,0,0},{1,1,2,2},{1,2,2,3}} ;

bool G[maxn][maxn] ;
queue<int> q ;
int d[maxn][maxn] ;

main()
{
    int n,m,k ;
    while(scanf("%d%d%d",&n,&m,&k)==3 && n+m+k)
    {
        memset(G,0,sizeof(G)) ;
        while(k--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            G[x][y]=1 ;
        }
        int sx,sy,ex,ey ;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey) ;
        fill(d[0],d[n-1]+m,INF) ;
        while(!q.empty()) q.pop() ;
        q.push(sx) ; q.push(sy) ; d[sx][sy]=0 ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            for(int i=0;i<12;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx<0||nx>=n||ny<0||ny>=m) continue ;
                if(G[nx][ny] || d[nx][ny]!=INF) continue ;
                bool ok=1 ;
                for(int j=0;j<4;j++)
                    if(G[x+chx[i][j]][y+chy[i][j]])
                        {ok=0 ; break ;}
                if(!ok) continue ;
                d[nx][ny]=d[x][y]+1 ;
                q.push(nx) ; q.push(ny) ;
            }
        }
        if(d[ex][ey]==INF) printf("No Way!\n") ;
        else printf("%d\n",d[ex][ey]) ;
    }
}
