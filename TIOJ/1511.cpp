#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    LL n ;
    char s[20],t[20] ;
    while(scanf("%lld%s%s",&n,s,t)!=EOF)
    {
        LL k=n/2 ;
        LL ans ;
        if(n%2)
        {
            if(s[0]=='R') ans=0 ;
            else if(s[0]=='O') ans=n*((n-k-1)*(n-k-2)/2) ;
            else
            {
                ans=-2*n*n+(6*k+6)*n-3*k*k-9*k-4 , ans/=2 ;
                if(ans%3==0) ans=(ans/3)*n ;
                else ans=ans*(n/3) ;
            }
        }
        else
        {
            if(s[0]=='R') ans=k*(2*k-2) ;
            else if(s[0]=='O') ans=n*((n-k-1)*(n-k-2)/2) ;
            else
            {
                ans=-2*n*n+(6*k+6)*n-3*k*k-9*k-4 , ans/=2 ;
                if(ans%3==0) ans=(ans/3)*n ;
                else ans=ans*(n/3) ;
                ans=ans-k*(2*k-2) ;
            }
        }
        printf("%lld\n",ans) ;
    }
}
