#include<bits/stdc++.h>
#define MOD 2076030
#define LL long long

LL f(LL n)
{
    if(n==0) return 1LL ;
    if(n==1) return 2LL ;
    LL tmp=f(n/2) ;
    if(n%2) return tmp*tmp*2 % MOD ;
    else return tmp*tmp % MOD ;
}

main()
{
    LL n ; scanf("%lld",&n) ;
    printf("%lld\n",f(n)) ;
}
