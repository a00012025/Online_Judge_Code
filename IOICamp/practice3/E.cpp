#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;

LL ans1,ans2 ;
void update(LL x,LL y)
{
    LL g=__gcd(x,y) ;
    x/=g , y/=g ;
    if( ans1*y > ans2*x ) ans1=x , ans2=y ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n ; scanf("%lld",&n) ;
        if(n==1) { printf("1/1\n") ; continue ; }
        ans1=1LL , ans2=0LL ;
        LL x= (int)sqrt(n*2+0.5) ; x=n-x ;
        update(2*(n-x),n*n-x*x+n-3*x) ;
        x-- ;
        update(2*(n-x),n*n-x*x+n-3*x) ;
        printf("%lld/%lld\n",ans2,ans1) ;
    }
}
