#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
const int maxn=1000000+10 ;

int dp[maxn][2] ;
char s[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%s",&n,s+1) ;
        dp[n+1][0]=0 ; dp[n+1][1]=INF ;
        for(int i=n;i>=1;i--) for(int j=0;j<2;j++)
        {
            dp[i][j]=INF ;
            int add ;
            if(s[i]=='B' && j==1) add=0 ;
            else if(s[i]=='A' && j==0) add=0 ;
            else add=1 ;
            for(int k=0;k<2;k++)
            {
                if(k==j) dp[i][j]=min(dp[i][j],dp[i+1][k]+add) ;
                else dp[i][j]=min(dp[i][j],dp[i+1][k]+add+1) ;
            }
        }
        printf("%d\n",min(dp[1][0],dp[1][1])) ;
    }
}
