#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n ;
LL best(LL x)
{
    int num=0 ;
    for(LL now=(1LL<<n)-x-1;now;now=(now-1)/2) num++ ;
    return (1LL<<(n-num))-1 ;
}
LL worst(LL x)
{
    int num=0 ;
    for(LL now=x;now;now=(now-1)/2) num++ ;
    return (1LL<<n)-(1LL<<(n-num)) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL p ; scanf("%d%lld",&n,&p) ; p-- ;
        LL l=0 , r=(1LL<<n) ;
        while(r-l>1)
        {
            LL mid=(l+r)/2 ;
            if(worst(mid)<=p) l=mid ;
            else r=mid ;
        }
        printf("%lld ",l) ; l=0 , r=(1LL<<n) ;
        while(r-l>1)
        {
            LL mid=(l+r)/2 ;
            if(best(mid)<=p) l=mid ;
            else r=mid ;
        }
        printf("%lld\n",l) ;
    }
}
