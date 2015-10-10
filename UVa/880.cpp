#include<stdio.h>
#include<math.h>
#define LL long long
main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        double x=sqrt(8*n+1) ; x+=3 ; x/=2 ; x-=0.000001 ;
        LL i=floor(x) ;
        LL j=n-((i-1)*(i-2)/2) ;
        printf("%lld/%lld\n",i-j,j) ;
    }
}
