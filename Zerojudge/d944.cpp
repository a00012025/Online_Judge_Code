#include<stdio.h>
#include<algorithm>
#define LL long long
#define INF 1LL<<60
using namespace std;
LL dp[10001][10],a[10001] ;
main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        for(int i=0;i<=n;i++) for(int j=0;j<=6;j++) dp[i][j]=INF ;
        dp[0][0]=0LL ;
        for(int i=1;i<n;i++) for(int j=0;j<=6;j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]+2*a[i]+5) ;
            if(j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+2*a[i]+10) ;
            if(j>=0 && j<=3) dp[i][j]=min(dp[i][j],dp[i-1][j+3]+a[i]+5) ;
            if(j>=1 && j<=4) dp[i][j]=min(dp[i][j],dp[i-1][j+2]+a[i]+10) ;
            //printf("dp[%d][%d]=%I64d\n",i,j,dp[i][j]) ;
        }
        LL ans=INF ;
        for(int i=0;i<7;i++) ans=min(ans,dp[n-1][i]+ (i>=3 ? a[n] : 2*a[n])) ;
        printf("%lld\n",ans) ;
    }
}
