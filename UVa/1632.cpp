#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10000 ;
const int INF=1000000000 ;
int pos[maxn],t[maxn],dp[maxn][maxn][2] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d%d",&pos[i],&t[i]) ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) dp[i][j][0]=dp[i][j][1]=dp[j][i][0]=dp[j][i][1]=INF ;
        for(int i=0;i<n;i++) dp[i][i][0]=dp[i][i][1]=0 ;
        for(int i=0;i<n;i++) for(int j=i;j<n;j++)
            if(dp[i][j][0]!=INF || dp[i][j][1]!=INF)
        {
            if(dp[i][j][0]!=INF)
            {
                if(i && dp[i][j][0]+pos[i]-pos[i-1] <= t[i-1])
                    dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][0]+pos[i]-pos[i-1]) ;
                if(j<n-1 && dp[i][j][0]+pos[j+1]-pos[i] <= t[j+1])
                    dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][0]+pos[j+1]-pos[i]) ;
            }
            if(dp[i][j][1]!=INF)
            {
                if(i && dp[i][j][1]+pos[j]-pos[i-1] <= t[i-1])
                    dp[i-1][j][0]=min(dp[i-1][j][0],dp[i][j][1]+pos[j]-pos[i-1]) ;
                if(j<n-1 && dp[i][j][1]+pos[j+1]-pos[j] <= t[j+1])
                    dp[i][j+1][1]=min(dp[i][j+1][1],dp[i][j][1]+pos[j+1]-pos[j]) ;
            }
        }
        if(dp[0][n-1][0]==INF && dp[0][n-1][1]==INF) printf("No solution\n") ;
        else printf("%d\n",min(dp[0][n-1][0],dp[0][n-1][1])) ;
    }
}
