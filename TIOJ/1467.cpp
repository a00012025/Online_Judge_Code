#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL n ;
    while(scanf("%lld",&n)!=EOF)
    {
        LL k=(n+1)/2 ;
        LL ans=(n-1)*(n-2)/2 ;
        ans=ans-3*((n-1)*(n-k)-(n+k-1)*(n-k)/2) ;
        printf("%lld\n",ans) ;
    }
}
