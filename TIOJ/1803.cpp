#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

LL power(LL x,int a)
{
    if(a==0) return 1LL ;
    if(a==1) return x ;
    LL tmp=power(x,a/2) ;
    if(a%2) return (((x*tmp)%MOD)*tmp)%MOD ;
    else return (tmp*tmp)%MOD ;
}

inline LL inv(LL x)
{
    return power(x,MOD-2) ;
}

LL frac[maxn] ;
LL cal(int n,int d)
{
    LL ret=frac[n]*inv(frac[n/d]) ; ret%=MOD ;
    ret*= inv( power(d,n/d) ) ; ret%=MOD ;
    return ret ;
}

main()
{
    frac[0]=1LL ;
    for(int i=1;i<maxn;i++) frac[i]=(frac[i-1]*i)%MOD ;
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int g=__gcd(n,k) ;
        LL ans=0LL ;
        for(int i=2;i<=g;i++) if(g%i==0)
            ans=(ans+cal(n,i)) % MOD ;
        printf("%lld\n",ans) ;
    }
}
