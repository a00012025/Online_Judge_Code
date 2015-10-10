#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int dp[maxn][4] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%s",&n,s+1) ;
        memset(dp,0,sizeof(dp)) ;
        dp[n+1][0]=1 ;
        dp[n][s[n]-'a'+1]=1 ;
        for(int i=n-1;i>=1;i--)
        {
            int c=s[i]-'a'+1 ;
            for(int j=1;j<=3;j++) if(j!=c)
                dp[i][0]|=dp[i+1][j] ;
            for(int j=1;j<=3;j++)
            {
                if(j==c)
                    {dp[i][j]=dp[i+1][0] ; continue ; }
                dp[i][j]=dp[i+1][6-j-c] ;
            }
        }
        if(dp[1][0]) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
