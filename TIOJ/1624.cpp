#include<bits/stdc++.h>
#define DB double
#define INF 1e10
#define SQR(x) ((x)*(x))
#define MIN(x,y,z) min(x,min(y,z))
using namespace std;
const int maxn=400+10 ;

DB dp[2][maxn][maxn] ;
int a[maxn],b[maxn] ;
DB dis[maxn][maxn] ;
main()
{
    int n,m,K,c,d ; scanf("%d%d%d%d%d",&n,&m,&K,&c,&d) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    sort(a+1,a+n+1) ;
    sort(b+1,b+m+1) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        dis[i][j]=c*sqrt(SQR(a[i]-b[j])+SQR(d)) ;
    for(int i=1;i<=K;i++) for(int j=0;j<=n;j++) for(int k=0;k<=m;k++)
    {
        dp[i%2][j][k]=INF ;
        if(j<i || k<i) continue ;
        dp[i%2][j][k]=MIN(dp[i%2][j][k-1],dp[i%2][j-1][k],
                          dp[(i+1)%2][j-1][k-1]+dis[j][k]) ;
    }
    printf("%d\n",int(ceil(dp[K%2][n][m]-1e-7)+1e-7)) ;
}
