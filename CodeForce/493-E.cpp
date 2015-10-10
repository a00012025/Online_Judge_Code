#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;

LL gcd(LL x,LL y) /// x,y > 0
{
    return y==0 ? x : gcd(y,x%y) ;
}

void get_ans(LL a,LL b,LL &x,LL &y,LL c) /// a,b,c > 0
{
    if(b==0) {x=c/a ; y=0 ; return ;}
    get_ans(b,a%b,y,x,c) ; y-=(a/b)*x ;
    debugf("%I64d,%I64d,%I64d,%I64d,%I64d\n",a,b,x,y,c) ;
}

LL solve(LL x1,LL y1,LL x2,LL y2)
{
    debugf("solve %I64d,%I64d,%I64d,%I64d\n",x1,y1,x2,y2) ;
    if(y1==0LL || y2==0LL) return ( (y1==0LL&&y2==0LL) ? 1LL : 0LL ) ;
    LL r1=y1%x1 , r2=y2%x2 ;
    if( ((r1-r2) % gcd(x1,x2)) !=0) return 0LL ;
    LL p0,q0, gc=gcd(x1,x2) ;
    if(r1==r2) p0=q0=0LL ;
    else if (r2>r1) get_ans(x1,x2,p0,q0,r2-r1) , q0=-q0 ; /// bomb ?
    else get_ans(x1,x2,p0,q0,r1-r2) , p0=-p0 ; /// bomb ?
    if(p0<0)
    {
        LL add=(-p0-1)/( x2/gc )+1 ;
        p0 += add*(x2/gc) , q0 += add*(x1/gc) ;
    }
    debugf("p0 , q0 = %I64d,%I64d\n",p0,q0) ;
    LL ret=0LL ;
    while(((y1-r1)/x1 >= p0) && ((y2-r2)/x2 >= q0))
    {
        LL a=r1+p0*x1 ;
        ret += solve(x1,(y1-a)/x1,x2,(y2-a)/x2) ;
        ret %= MOD ;
        p0 += x2/gc , q0 += x1/gc ;
        if(p0<0 || q0<0) break ;
    }
    return ret ;
}

main()
{
    LL x1,x2 ; get_ans(99999999993LL,1000000000000000000LL,x1,x2,1) ;
    debugf("%I64d,%I64d\n",x1,x2) ;
    LL x,y,z ; scanf("%I64d%I64d%I64d",&x,&y,&z) ;
    if(x!=y && ((z-y)%(y-x)!=0)) printf("0\n") ;
    else if(x==y && y!=z) printf("0\n") ;
    else if(x==y && x!=1) printf("2\n") ;
    else if(x==y && x==1) printf("inf\n") ;
    else printf("%I64d\n",solve(x,y,y,z)) ;
}
