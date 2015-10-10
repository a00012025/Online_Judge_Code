#include<stdio.h>
#include<string.h>
long long dp[2010][2010],a[2010] ;
int const C=1000000007 ;
main()
{
    int n,h ;
    scanf("%d %d",&n,&h) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][0]=1 ;
    for(int i=1;i<=n;i++)
    {
        int k=h-a[i]-1 ;
        if(k>=0) dp[i][k]=(k+1)*(dp[i-1][k+1]+dp[i-1][k]) ;
        dp[i][k]%=C ;
        k=h-a[i] ;
        if(k>=0) dp[i][k]=dp[i-1][k-1]+dp[i-1][k] ;
        dp[i][k]%=C ;
    }
    printf("%d\n",dp[n][0]) ;
}
