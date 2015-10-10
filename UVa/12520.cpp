#include<bits/stdc++.h>
#define LL long long
using namespace std;
main()
{
    LL n,m ;
    while(scanf("%lld%lld",&n,&m)==2 && n+m)
    {
        LL sub=0LL ;
        if(n%2==0 && m>n*n/2)
        {
            LL x=m-n*n/2 ;
            if(x<=2) sub=4*x ;
            else if(x<=2*n-2) sub=6*x-4 ;
            else sub=8*x-4*n ;
        }
        else if(n%2==1 && m>n*n/2+1)
        {
            LL x=m-n*n/2-1 ;
            if(x==1) sub=6 ;
            else if(x<=3) sub=4*x+4 ;
            else if(x<=2*n-3) sub=6*x-2 ;
            else sub=8*x-(4*n-4) ;
        }
        printf("%lld\n",4*m-sub) ;
    }
}
