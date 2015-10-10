#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=400000 ;

LL dp[maxn] ;
LL a[maxn] ;
main()
{
    while(scanf("%lld",&a[1])!=EOF)
    {
        if(!a[1]) { printf("100\n") ; continue ; }
        int n=1 ;
        while(1)
        {
            n++ ; scanf("%lld",&a[n]) ;
            if(!a[n]) break ;
        }
        dp[0]=0LL ;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+a[i] ;
            for(int j=max(i-3,0);j<i-1;j++)
                dp[i]=min(dp[i],dp[j]+a[i]) ;
        }
        printf("%lld\n",10LL*dp[n]+100LL*((LL)n) ) ;
    }
}
