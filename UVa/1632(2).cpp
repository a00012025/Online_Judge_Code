#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10010 ;
const int INF=1000000000 ;
int pos[maxn],t[maxn],dp[maxn][maxn][2] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%lld%lld",&pos[i],&t[i]) , dp[i][i][0]=dp[i][i][1]=0 ;
        for(int i=n-1;i>=0;i--) for(int j=i+1;j<n;j++)
        {
            dp[i][j][0]=min(dp[i+1][j][0]+pos[i+1]-pos[i],dp[i+1][j][1]+pos[j]-pos[i]) ;
            if(dp[i][j][0]>=t[i]) dp[i][j][0]=INF ;
            dp[i][j][1]=min(dp[i][j-1][1]+pos[j]-pos[j-1],dp[i][j-1][0]+pos[j]-pos[i]) ;
            if(dp[i][j][1]>=t[j]) dp[i][j][1]=INF ;
        }
        if(dp[0][n-1][0]==INF && dp[0][n-1][1]==INF) printf("No solution\n") ;
        else printf("%lld\n",min(dp[0][n-1][0],dp[0][n-1][1])) ;
    }
}

