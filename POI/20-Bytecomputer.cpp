#include<bits/stdc++.h>
#define INF 1000000000
#define MIN(x,y,z) min(min(x,y),z)
using namespace std;
const int maxn=1000000+10 ;

int dp[maxn][3] ;
int a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=0;i<3;i++) dp[1][i]= ( a[1]==i-1 ? 0 : INF ) ;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==1)
        {
            dp[i][2]=MIN(dp[i-1][0],dp[i-1][1],dp[i-1][2]) ;
            dp[i][1]=dp[i-1][0]+1 ;
            dp[i][0]=dp[i-1][0]+2 ;
        }
        else if(a[i]==0)
        {
            dp[i][2]=dp[i-1][2]+1 ;
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]) ;
            dp[i][0]=dp[i-1][0]+1 ;
        }
        else
        {
            dp[i][2]=dp[i-1][2]+2 ;
            dp[i][1]=INF ;
            dp[i][0]=dp[i-1][0] ;
        }
    }
    int ans=MIN(dp[n][0],dp[n][1],dp[n][2]) ;
    if(ans>2*n) printf("BRAK\n") ;
    else printf("%d\n",ans) ;
}
