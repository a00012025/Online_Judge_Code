#include<stdio.h>
#include<queue>
#include<algorithm>
#define INF 10000000
using namespace std;
struct P{int x,y,num ;};
int lev[30][30][30],G[30][30] ;
int dx[5]={1,-1,0,0} , dy[5]={0,0,1,-1} ;

int level(int x,int y)
{
    int ret=INF ;
    for(int i=0;i<30;i++) ret=min(ret,lev[x][y][i]) ;
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m,k ;
        scanf("%d%d%d",&n,&m,&k) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            scanf("%d",&G[i][j]) ;
            for(int k=0;k<30;k++) lev[i][j][k]=INF ;
        }
        queue<P> q ;
        q.push((P){1,1,0}) ; lev[1][1][0]=0 ;
        while(!q.empty())
        {
            P u=q.front() ; q.pop() ;
            for(int i=0;i<4;i++)
            {
                int nx=u.x+dx[i] , ny=u.y+dy[i] ;
                if(nx<1 || nx>n || ny<1 || ny>m) continue ;
                if(!G[nx][ny] && lev[nx][ny][0]>level(u.x,u.y)+1)
                {
                    lev[nx][ny][0]=level(u.x,u.y)+1 ;
                    q.push((P){nx,ny,0}) ;
                }
                else if(G[nx][ny] && u.num<k && lev[nx][ny][u.num+1]>lev[u.x][u.y][u.num]+1)
                {
                    lev[nx][ny][u.num+1]=lev[u.x][u.y][u.num]+1 ;
                    q.push((P){nx,ny,u.num+1}) ;
                }
            }
        }
        if(lev[n][m][0]==INF) printf("-1\n") ;
        else printf("%d\n",lev[n][m][0]) ;
    }
}
