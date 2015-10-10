#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,k,MOD ;
int dp[1005][105] ;

main()
{
    scanf("%d%d%d",&n,&k,&MOD) ;

    for(int i=1;i<=9;i++) dp[1][i%k]++ ;
    int now=1 ;
    for(int i=2;i<=n;i++)
    {
        now*=10 ; now%=k ;
        for(int j=0;j<=9;j++)
        {
            if(i==n && j==0) continue ;
            for(int z=1;z<k;z++)
                dp[i][(z+j*now)%k]=(dp[i][(z+j*now)%k]+dp[i-1][z])%MOD ;
            dp[i][(now*j)%k]++ ;
        }
    }

    LL ans=9LL ;
    for(int i=1;i<n;i++) ans*=10 , ans%=MOD ;
    for(int i=1;i<k;i++) ans-=dp[n][i] , ans%=MOD ;
    ans=(ans+MOD)%MOD ;
    printf("%I64d\n",ans) ;
}
