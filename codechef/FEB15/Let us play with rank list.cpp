#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL cal(LL n,LL s)
{
    if(s==n*(n+1)/2) return 0LL ;
    s=sqrt(8*(s-n)+1+0.5) ;
    s=(s+1)/2 ;
    return n-s ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,s ; scanf("%lld%lld",&n,&s) ;
        printf("%lld\n",cal(n,s)) ;
    }
}
