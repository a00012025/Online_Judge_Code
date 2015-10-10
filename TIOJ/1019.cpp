#include<bits/stdc++.h>
#define LL long long
#define ABS(x) ((x)>=0?(x):(-(x)))
using namespace std;
LL d[1001] ;
LL dp[1001] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%lld",&d[i]) ;
        dp[1]=0LL , dp[2]=ABS(d[2]-d[1]) ;
        for(int i=3;i<=n;i++)
            dp[i]=min(dp[i-2]+ABS(d[i-2]-d[i]),dp[i-1]+ABS(d[i-1]-d[i])) ;
        printf("%lld\n",dp[n]) ;
    }
}
