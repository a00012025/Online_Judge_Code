#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=70000 ;

LL dp[maxn] ;
LL power[maxn] ;
main()
{
    int k,m,n,MOD ;
    while(scanf("%d%d%d%d",&k,&m,&n,&MOD)==4 && k+m+n+MOD)
    {
        power[0]=1LL ;
        for(int i=1;i<=n;i++) power[i]=power[i-1]*k%MOD ;

        dp[0]=1LL ;
        for(int i=1;i<=n;i++)
            dp[i]=dp[i-1]*k + (i>m ? dp[i-m-1]*power[m] : power[i-1] ) ,
            dp[i]%=MOD ;
        printf("%lld\n",dp[n]) ;
    }
}
