#include<bits/stdc++.h>
#define INF 1000000
#define pb(x) push_back(x)
#define pf(x) push_front(x)
using namespace std;
const int maxn=100+10 ;

char G[maxn][maxn] ;
int d[maxn][maxn][4] ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
deque<int> dq ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    swap(n,m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        for(int k=0;k<4;k++) d[i][j][k]=INF ;
    int sx,sy,ex,ey ;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey) ;
    sx-- ; sy-- ; ex-- ; ey-- ;
    for(int k=0;k<4;k++)
    {
        d[sx][sy][k]=0 ;
        dq.pb(sx) ; dq.pb(sy) ; dq.pb(k) ;
    }
    while(!dq.empty())
    {
        int x=dq.front() ; dq.pop_front() ;
        int y=dq.front() ; dq.pop_front() ;
        int t=dq.front() ; dq.pop_front() ;
        int nx=x+dx[t] , ny=y+dy[t] ;
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&G[nx][ny]=='O')
        {
            if(d[nx][ny][t]>d[x][y][t])
                d[nx][ny][t]=d[x][y][t] ,
                dq.pf(t) , dq.pf(ny) , dq.pf(nx) ;
        }
        for(int i=0;i<4;i++) if(i!=t)
        {
            if(d[x][y][i]>d[x][y][t]+1)
                d[x][y][i]=d[x][y][t]+1 ,
                dq.pb(x) , dq.pb(y) , dq.pb(i) ;
        }
    }

    int ans=INF ;
    for(int i=0;i<4;i++) ans=min(ans,d[ex][ey][i]) ;
    if(ans==INF) printf("No Way!!\n") ;
    else printf("%d\n",ans) ;
}
