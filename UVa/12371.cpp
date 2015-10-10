#include<stdio.h>
#include<algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;
LL dp[100001][51]={0} ;
main()
{
    dp[2][1]=((LL)1) ;
    for(LL n=3;n<=100000;n++) for(LL k=1;k<=min(n,(LL)50);k++)
    {
        dp[n][k]=(dp[n-1][k]*(n*(n-1)%MOD)%MOD)
                    +(((((n*(n-1)/((LL)2))%MOD)*(n-1))%MOD)*dp[n-2][k-1])%MOD ;
        dp[n][k]%=MOD ;
    }
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k) ;
        printf("Case %d: %lld\n",++tc,dp[n][k]) ;
    }
}
