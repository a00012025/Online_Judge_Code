#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,k ; scanf("%lld",&n) , k=n/2 ;
        printf("%lld\n",n%2 ? k*k+3*k+1 : k*k+2*k) ;
    }
}
