#include<stdio.h>
#include<math.h>
#define LL long long
main()
{
    LL n;
    while(scanf("%lld",&n)==1 && n)
    {
        double d=sqrt((double)n) ; d-=0.5 ;
        LL k=floor(d) ;
        if((k+1)*(k+1) != n) printf("no\n");
        else printf("yes\n");
    }
}
