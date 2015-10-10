#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],dp[2][maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        dp[1][1]=a[1] ;
        for(int i=2;i<n;i++) for(int j=0;j<2;j++)
            dp[j][i]=max(dp[j][i-1],dp[j][i-2]+a[i]) ;
        int ans=dp[1][n-1] ;
        for(int i=1;i<=n-2;i++) ans=max(ans,dp[0][i]+a[n]) ;
        printf("%d\n",ans) ;
    }
}
