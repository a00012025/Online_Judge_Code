#include<bits/stdc++.h>
#define INF 1000
using namespace std;
const int maxn=100+5 ;

int dis[maxn][maxn] ;
int d[maxn][maxn] ;
bool done[maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dis[i][j]=(i==j?0:INF) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        dis[x][y]=1 ;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        d[i][j]=min(INF,dis[1][i]+dis[i][j]+dis[j][1]) ;
    d[1][1]=1 ;
    int tot=n*n ;
    while(tot--)
    {
        int ix,iy,mi=INF+1 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            if(!done[i][j] && d[i][j]<mi)
            mi=d[i][j] , ix=i , iy=j ;
        done[ix][iy]=1 ;
        if(ix==2 && iy==2){printf("%d\n",mi) ; break ;}
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!done[i][j])
            d[i][j]=min(d[i][j],d[ix][iy]+dis[iy][i]+dis[i][j]+dis[j][ix]-1) ;
    }
}
