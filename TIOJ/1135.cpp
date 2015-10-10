#include<bits/stdc++.h>
#define LL long long
using namespace std;

void gcd(LL a,LL b,LL &x,LL &y,LL d)
{
    if(!b) { x=d/a ; y=0 ; return ; }
    gcd(b,a%b,y,x,d) ;
    y-=(a/b)*x ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL a,b,c ; int k ;
        scanf("%lld%lld%lld%d",&a,&b,&c,&k) ;
        LL g=__gcd(c,1LL<<k) ;
        if((b-a)%g) { printf("FOREVER\n") ; continue ; }
        LL x,y ;
        gcd(c,-(1LL<<k),x,y,b-a) ;
        LL MOD=(1LL<<k)/g ;
        x=((x%MOD)+MOD)%MOD ;
        printf("%lld\n",x) ;
    }
}
