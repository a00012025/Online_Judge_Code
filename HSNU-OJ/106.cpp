#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        LL n,m ; scanf("%lld%lld",&n,&m) ;
        LL ans ;
        if(m%2==0)
        {
            LL k=m/2 ;
            if(n>=m) ans=k ;
            else if(n<=k) ans=(n+4)*(n-1)/2 ;
            else ans=((k+4)*(k-1)/2)-(3*k+1-n)*(n-k)/2 ;
        }
        else
        {
            LL k=m/2 ;
            if(n>=m) ans=k ;
            else if(n<=k) ans=(n+4)*(n-1)/2 ;
            else ans=(k+4)*(k-1)/2 - (3*k-n+2)*(n-k-1)/2 ;
        }
        printf("%lld\n",ans) ;
    }
}
