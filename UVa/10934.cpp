#include<stdio.h>
#define ULL unsigned long long
ULL dp[102][65] ;
main()
{
    for(int i=0;i<=64;i++) dp[0][i]=(ULL)0 ;
    for(int i=0;i<=101;i++) dp[i][0]=(ULL)0 ;
    for(int i=1;i<=100;i++) for(int j=1;j<=63;j++)
        dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+1 ;
    int k ;
    ULL n ;
    while(scanf("%d%llu",&k,&n)==2 && k)
    {
        int i ;
        for(i=0;i<=63 && dp[k][i]<n;i++) ;
        if(i==64) printf("More than 63 trials needed.\n") ;
        else printf("%d\n",i) ;
    }
}
