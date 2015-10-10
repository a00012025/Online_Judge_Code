#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a1,a2,x,y ;
bool check(LL val)
{
    LL b1=(val/x)-(val/(x*y)) ;
    LL b2=(val/y)-(val/(x*y)) ;
    return max(0LL,a1-b2)+max(0LL,a2-b1)<=val-b1-b2-val/(x*y) ;
}

main()
{
    scanf("%d%d%d%d",&a1,&a2,&x,&y) ;
    LL l=0 , r=1e15 ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%lld\n",r) ;
}
