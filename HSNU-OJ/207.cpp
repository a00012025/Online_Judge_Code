#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n ;
LL x,y ;
LL cal(LL k)
{
    LL ret=2*k*k+2*k+1 ;
    if(x-k<1) ret-=(k+1-x)*(k+1-x) ;
    if(x+k>n) ret-=(x+k-n)*(x+k-n) ;
    if(y-k<1) ret-=(k+1-y)*(k+1-y) ;
    if(y+k>n) ret-=(y+k-n)*(y+k-n) ;
    if(k>x+y-1) ret+=(k-x-y+1)*(k-x-y+2)/2 ;
    if(k>n+x-y) ret+=(k-n-x+y)*(k-n+1-x+y)/2 ;
    if(k>y-x+n) ret+=(k-n+x-y)*(k-n+1+x-y)/2 ;
    if(k>2*n-x-y+1) ret+=(k-2*n+x+y-1)*(k-2*n+x+y)/2 ;
    return ret ;
}

main()
{
    LL c ;
    while(scanf("%lld%lld%lld%lld",&n,&x,&y,&c)!=EOF)
    {
        int l=-1 , r=2*n ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(cal(mid)>=c) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
