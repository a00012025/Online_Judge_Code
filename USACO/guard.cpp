#include<bits/stdc++.h>
#define INF (1LL<<60)
#define LL long long
using namespace std;
const int maxn=20+1 ;

LL dp[1<<maxn] ;
int h[maxn],w[maxn],str[maxn] ;
LL hsum[1<<maxn],wsum[1<<maxn] ;

main()
{
    if(fopen("guard.in","r"))
    {
        freopen("guard.in","r",stdin) ;
        freopen("guard.out","w",stdout) ;
    }
    int n,H ; scanf("%d%d",&n,&H) ;
    for(int i=0;i<n;i++) scanf("%d%d%d",&h[i],&w[i],&str[i]) ;

    dp[0]=INF ;
    LL ans=-INF ;
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=-INF ;
        for(int j=0;j<n;j++) if(i&(1<<j))
        {
            wsum[i]+=w[j] ;
            hsum[i]+=h[j] ;
            dp[i]=max(dp[i],
            min(str[j]-wsum[i^(1<<j)],dp[i^(1<<j)])) ;
        }
        if(hsum[i]>=H) ans=max(ans,dp[i]) ;
    }
    if(ans<0) printf("Mark is too tall\n") ;
    else printf("%lld\n",ans) ;
}
