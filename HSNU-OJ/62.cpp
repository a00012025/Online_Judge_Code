#include<bits/stdc++.h>
#define INF 100000
using namespace std;

char s[2000] ;
int dp[2][1001][27] ;
int min1[1001],id1[1001],min2[1001],id2[1001] ;
main()
{
    int n,m ; scanf("%d%d%s",&n,&m,s+1) ;
    for(int j=0;j<=m;j++) for(int k=1;k<=26;k++) dp[1][j][k]=INF ;
    for(int j=1;j<=m;j++) for(int k=1;k<=26;k++) dp[1][j][k]=1 ;
    dp[1][0][s[1]-'A'+1]=1 ; /// i=1 : dp[1][j][k]
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            min1[j]=INF+1 , min2[j]=INF+1 ;
            id1[j]=id2[j]=0 ;
            for(int k=1;k<=26;k++)
            {
                int val=dp[(i+1)%2][j][k] ;
                if(val<=min1[j])
                    min2[j]=min1[j] , id2[j]=id1[j] , min1[j]=val , id1[j]=k ;
                else if(val<min2[j]) min2[j]=val , id2[j]=k ;
            }
        }
        for(int j=0;j<=m;j++) for(int k=1;k<=26;k++)
        {
            if(s[i]-'A'+1==k)
            {
                dp[i%2][j][k]=dp[(i+1)%2][j][k] ;
                if(k==id1[j]) dp[i%2][j][k]=min(dp[i%2][j][k],min2[j]+1) ;
                else  dp[i%2][j][k]=min(dp[i%2][j][k],min1[j]+1) ;
            }
            else if(j)
            {
                dp[i%2][j][k]=dp[(i+1)%2][j-1][k] ;
                if(k==id1[j-1]) dp[i%2][j][k]=min(dp[i%2][j][k],min2[j-1]+1) ;
                else dp[i%2][j][k]=min(dp[i%2][j][k],min1[j-1]+1) ;
            }
            else dp[i%2][j][k]=INF ;
        }
    }
    int ans=INF ;
    for(int i=1;i<=26;i++) ans=min(ans,dp[n%2][m][i]) ;
    printf("%d\n",ans) ;
}
