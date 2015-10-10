#include<bits/stdc++.h>
#define MAX(x,y,z) max(x,max(y,z))
#define INF 2100000000
using namespace std;
const int maxn=100000+10 ;

int x[maxn],h[maxn] ;
int dp[maxn][3] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&h[i]) ;
    x[n+1]=INF ;
    dp[1][0]=1 ; dp[1][2]=(x[1]+h[1]<x[2] ? 1 : -INF) ;
    for(int i=2;i<=n;i++) for(int j=0;j<3;j++)
    {
        dp[i][j]=-INF ;
        if(j==0)
        {
            if(x[i]-h[i]<=x[i-1]) continue ;
            if(h[i-1]+h[i]>=x[i]-x[i-1])
                dp[i][j]=max(dp[i-1][0],dp[i-1][1])+1 ;
            else dp[i][j]=MAX(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1 ;
        }
        else if(j==1) dp[i][j]=MAX(dp[i-1][0],dp[i-1][1],dp[i-1][2]) ;
        else
        {
            if(x[i]+h[i]>=x[i+1]) continue ;
            dp[i][j]=dp[i][1]+1 ;
        }
    }
    printf("%d\n",MAX(dp[n][0],dp[n][1],dp[n][2])) ;
}
