#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
#define MOD 1000000007
using namespace std;
const int maxn=200000+10 ;

LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1 ;
    LL t=power(x,n/2) ;
    if(n%2) return t*t%MOD*x%MOD ;
    else return t*t%MOD ;
}

LL inv(LL x)
{
    return power(x,MOD-2) ;
}

LL fac[maxn],ifac[maxn] ;
inline LL C(int n,int m)
{
    return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD ;
}

pii p[maxn] ;
LL dp[maxn] ;
main()
{
    for(int i=0;i<maxn;i++)
        fac[i]=(i ? fac[i-1]*i%MOD : 1) ,
        ifac[i]=inv(fac[i]) ;
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=0;i<k;i++) scanf("%d%d",&p[i].F,&p[i].S) ;
    p[k++]=(pii){n,m} ;
    sort(p,p+k) ;
    for(int i=0;i<k;i++)
    {
        dp[i]=C(p[i].F+p[i].S-2,p[i].F-1) ;
        for(int j=0;j<i;j++) if(p[j].S<=p[i].S)
            dp[i]-=dp[j]*C(p[i].F+p[i].S-p[j].F-p[j].S,p[i].F-p[j].F)%MOD ,
            dp[i]%=MOD ;
        if(dp[i]<0) dp[i]+=MOD ;
    }
    printf("%lld\n",dp[k-1]) ;
}
