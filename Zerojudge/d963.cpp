#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define debugf(...) ((void)0) ;
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
using namespace std;
int dp[5001][5001] ;
char s[5001] ;
main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) ;
        for(int len=1;len<=n;len++) for(int i=0;i+len-1<n;i++)
        {
            if(len==1) dp[i][i]=1 ;
            else if(s[i]==s[i+len-1]) dp[i][i+len-1]= len==2 ? 2 : dp[i+1][i+len-2]+2 ;
            else dp[i][i+len-1]=max(dp[i+1][i+len-1],dp[i][i+len-2]) ;
            dp[i][i+len-1]=max(dp[i][i+len-1],1) ;
            debugf("dp[%d][%d]=%d\n",i,i+len-1,dp[i][i+len-1]) ;
        }
        printf("%d\n",dp[0][n-1]) ;
    }
}
