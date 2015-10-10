#include<stdio.h>
#include<algorithm>
#define LL long long
#define INF 1LL<<60
using namespace std;
struct P {LL V,K,C,L;}a[1001];
bool cmp(P x,P y)
{
    return x.V<y.V ;
}
LL dp[1001],sum[1001] ;
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        sum[0]=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld%lld",&a[i].V,&a[i].K,&a[i].C,&a[i].L) ;
        }
        sort(a+1,a+n+1,cmp) ;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].L ;
        dp[0]=0LL ;
        for(int i=1;i<=n;i++)
        {
            dp[i]=INF ;
            for(int j=1;j<=i;j++)
                dp[i]=min(dp[i],dp[j-1]+a[i].K+(a[i].C)*(sum[i]-sum[j-1])) ;
        }
        printf("%lld\n",dp[n]) ;
    }
}
