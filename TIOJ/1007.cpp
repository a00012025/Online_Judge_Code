#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL dp[100] ;
main()
{
    int d,n ; scanf("%d%d",&d,&n) ;
    dp[0]=1LL ;
    for(int i=1;i<=n;i++) for(int j=max(0,i-d-1);j<=i-1;j++)
        dp[i]+=dp[j] ;
    LL ans=0 ;
    for(int j=max(1,n-d);j<=n;j++) ans+=dp[j] ;
    printf("%lld\n",ans) ;
}
