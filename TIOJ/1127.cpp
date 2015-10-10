#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL dp[2][50] ;
main()
{
    dp[0][0]=1 ; dp[1][0]=1 ;
    for(int i=2;i<=42;i+=2)
        dp[1][i]=2*dp[0][i-2]+dp[1][i-2] ,
        dp[0][i]=dp[0][i-2]+dp[1][i] ;
    int n ;
    while(scanf("%d",&n)!=EOF) printf("%lld\n",dp[0][n-1]) ;
}
