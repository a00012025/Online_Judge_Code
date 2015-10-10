#include<stdio.h>
#include<queue>
using namespace std;
struct P
{
    int x,y,w ;
    bool operator < (const P &rhs) const
    {
        return w > rhs.w ;
    }
};
priority_queue<P> pq ;
const int INF=100000000 ;
int n,m,d[1000][1000],G[1000][1000] ;
int dx[5]={1,-1,0,0} , dy[5]={0,0,1,-1} ;

void dijkstra()
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=INF ;
    d[1][1]=G[1][1] ;
    while(!pq.empty()) pq.pop() ;
    pq.push((P){1,1,G[1][1]}) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=u.x+dx[i] , ny=u.y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m) continue ;
            if(d[nx][ny]>u.w+G[nx][ny])
            {
                d[nx][ny]=u.w+G[nx][ny] ;
                pq.push((P){nx,ny,d[nx][ny]}) ;
            }
        }
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&G[i][j]) ;
        dijkstra() ;
        printf("%d\n",d[n][m]) ;
    }
}
