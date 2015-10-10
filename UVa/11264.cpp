#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;

LL dp[1001],a[1001] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        dp[0]=0LL ; int num=0 ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        for(int i=1;i<=n;i++)
        {
            LL x= i==n ? INF : a[i+1]-a[i] ;
            if(dp[num]<x) { dp[num+1]=a[i]+dp[num] ; num++ ; continue ; }
            int id=lower_bound(dp,dp+num+1,x) - dp ;
            dp[id]=min(dp[id],dp[id-1]+a[i]) ;
        }
        printf("%d\n",num) ;
    }
}
