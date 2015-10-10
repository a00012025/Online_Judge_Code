#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int INF=100000 ;
char s[50],t[50] ;
int dp[50][50] ;
LL num[50][50] ;
main()
{
        //freopen("1.txt","r",stdin);
    int T,tc=0 ; scanf("%d",&T) ; gets(s+1) ;
    while(T--)
    {
        gets(s+1) ; gets(t+1) ;
        int n=strlen(s+1) , m=strlen(t+1) ;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=INF ;
        dp[0][0]=0 ; num[0][0]=1LL ;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) if(i||j)
        {
            if(!i || !j)
            {
                num[i][j]=1LL ;
                dp[i][j]= i ? i : j ;
                continue ;
            }
            if(s[i]==t[j])
            {
                dp[i][j]=dp[i-1][j-1]+1 ;
                num[i][j]=num[i-1][j-1] ;
            }
            else
            {
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1) ;
                num[i][j]=0LL ;
                if(dp[i][j]==dp[i][j-1]+1) num[i][j]+=num[i][j-1] ;
                if(dp[i][j]==dp[i-1][j]+1) num[i][j]+=num[i-1][j] ;
            }
            //printf("num[%d][%d]=%d\n",i,j,num[i][j]) ;
        }
        printf("Case #%d: %d %lld\n",++tc,dp[n][m],num[n][m]) ;
    }
}
