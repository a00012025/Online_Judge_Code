#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

LL cal(LL n)
{
    LL ret=0 ;
    for(LL i=1;i<=n;)
    {
        LL j=n/(n/i) , q=n/i ;
        ret+=n*(j-i+1)-q*((i+j)*(j-i+1)/2%MOD)%MOD ;
        ret%=MOD ;
        i=j+1 ;
    }
    return ret ;
}

inline LL get2(LL x)
{
    return x*(x+1)%MOD*(2*x+1)%MOD*166666668%MOD ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,m ; scanf("%lld%lld",&n,&m) ;
        LL ans=cal(n)*cal(m)%MOD , sub=0 ;
        for(LL i=1;i<=min(n,m);)
        {
            LL j=min(n/(n/i),m/(m/i)) ;
            LL q1=n/i , q2=m/i ;
            sub+=q1*q2%MOD*(get2(j)-get2(i-1))%MOD ;
            sub%=MOD ;
            sub-=(q1*m%MOD+q2*n%MOD)*((i+j)*(j-i+1)/2%MOD)%MOD ;
            sub%=MOD ;
            sub+=n*m%MOD*(j-i+1)%MOD ;
            sub%=MOD ;
            i=j+1 ;
        }
        printf("%lld\n",((ans-sub)%MOD+MOD)%MOD) ;
    }
}
