#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

char s[2000] ;
LL dp[1010][1010],sum[1010] ;
main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        int n=strlen(s+1) ; n++ ;
        dp[1][1]=1LL ;
        for(int i=2;i<=n;i++)
        {
            sum[0]=0LL ;
            for(int j=1;j<i;j++) sum[j]=(sum[j-1]+dp[i-1][j])%MOD ;
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=0LL ;
                if(s[i-1]!='I') dp[i][j]+=sum[j-1] , dp[i][j]%=MOD ;
                if(s[i-1]!='D') dp[i][j]+=sum[i-1]-sum[j-1] , dp[i][j]=(dp[i][j]+MOD)%MOD ;
            }
        }
        LL ans=0LL ;
        for(int i=1;i<=n;i++) ans+=dp[n][i] , ans%=MOD ;
        printf("%lld\n",ans) ;
    }
}

