#include<stdio.h>
#include<queue>
using namespace std;
const int INF=100000000 ;
bool inq[1000][1000] ;
int G[1000][1000],d[1000][1000] ;
int dx[5]={1,-1,0,0} , dy[5]={0,0,1,-1} ;
queue<int> q ;
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m ;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c=getchar() ;
            while(c<'0' || c>'9') c=getchar() ;
            G[i][j]=c-'0' ;
            d[i][j]=INF ; inq[i][j]=0 ;
        }
        while(!q.empty()) q.pop() ;
        d[1][1]=G[1][1] ; q.push(1) ; q.push(1) ; inq[1][1]=1 ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            inq[x][y]=0 ;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx<0 || nx>n || ny<0 || ny>m) continue ;
                if(d[x][y]+G[nx][ny]<d[nx][ny])
                {
                    d[nx][ny]=d[x][y]+G[nx][ny] ;
                    if(!inq[nx][ny]) {q.push(nx) ; q.push(ny) ;}
                    inq[nx][ny]=1 ;
                }
            }
        }
        printf("%d\n",d[n][m]) ;
    }
}
