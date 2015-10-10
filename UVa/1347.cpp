#include<stdio.h>
#include<algorithm>
#include<math.h>
#define DB double
#define INF 1000000000.0
using namespace std;
int x[1001],y[1001] ;
DB dp[1001][1001] ;
DB dis(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])) ;
}
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]) ;
        for(int i=2;i<=n;i++) for(int j=1;j<i;j++) dp[i][j]=INF ;
        dp[2][1]=dis(1,2) ;
        for(int i=2;i<n;i++) for(int j=1;j<i;j++)
        {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+dis(i,i+1)) ;
            dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dis(i+1,j)) ;
        }
        DB ans=INF ;
        for(int j=1;j<n;j++) ans=min(ans,dp[n][j]+dis(j,n)) ;
        printf("%.2lf\n",ans) ;
    }
}
