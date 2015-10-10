#include<stdio.h>
#include<string.h>
#define LL long long
LL dp[21][21][21] ;
main()
{
    memset(dp,0,sizeof(dp)) ;
    dp[1][1][1]=1 ;
    for(int n=2;n<=20;n++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        dp[n][i][j]=dp[n-1][i-1][j]+dp[n-1][i][j-1]+((LL)n-2)*dp[n-1][i][j];
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b) ;
        printf("%lld\n",dp[n][a][b]) ;
    }
}
