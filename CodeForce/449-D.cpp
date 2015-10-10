#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=1<<20 ;

int dp[21][maxn] ;
int pw2[maxn] ;
main()
{
    for(int i=0;i<maxn;i++) pw2[i]= i?pw2[i-1]*2%MOD : 1 ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        dp[0][x]++ ;
    }
    for(int d=0;d<20;d++) for(int i=0;i<(1<<20);i++)
        dp[d+1][i]=dp[d][i]+( (i&(1<<d)) ? 0 : dp[d][i+(1<<d)] ) ;

    LL ans=0LL ;
    for(int i=1;i<(1LL<<20);i++)
        ans=(ans+(__builtin_popcount(i)%2 ? 1 : -1)*pw2[dp[20][i]])%MOD ;
    printf("%I64d\n",(pw2[n]-ans+MOD)%MOD) ;
}
