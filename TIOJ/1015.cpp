#include<bits/stdc++.h>
#define LL long long
using namespace std;
main()
{
    LL n,m ;
    while(scanf("%lld%lld",&n,&m)==2 && m+n)
    {
        if(n>m) swap(n,m) ;
        printf("%lld\n",n*n*m-(m+n)*n*(n-1)/2+n*(n-1)*(2*n-1)/6);
    }
}
