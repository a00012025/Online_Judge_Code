#include<stdio.h>
#include<string.h>
int dp[21][21][21] ;
main()
{
    memset(dp,0,sizeof(dp)) ;
    for(int i=2;i<=20;i++) dp[1][0][i]=1 ;
    dp[1][0][0]=1 ; dp[1][1][1]=1 ;

    for(int i=1;i<=20;i++) dp[0][0][i]=1 ;
    dp[0][1][0]=1 ;

    for(int n=2;n<=20;n++)
    {
        dp[n][0][0]=2*dp[n-1][0][0] ;
        for(int i=2;i<n;i++) dp[n][0][0]+=dp[i-1][0][0]*dp[n-i][0][0] ;
        for(int r=0;r<=20;r++) for(int k=1;k<=20;k++)
        {
            dp[n][r][k]=dp[n-1][r][k-1] ;
            for(int i=1;i<n;i++) for(int j=0;j<=r;j++)
                dp[n][r][k]+=dp[i-1][j][k-1]*dp[n-i][r-j][k] ;
        }
    }
    int n,r,k ;
    while(scanf("%d %d %d",&n,&r,&k)!=EOF) printf("%d\n",dp[n][r][k]) ;
}
