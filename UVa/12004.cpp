#include<stdio.h>
#define LL long long
main()
{
    int T,tc=0 ;
    scanf("%d",&T);
    while(T--)
    {
        LL n;
        scanf("%lld",&n) ;
        if(n*(n-1)%4)printf("Case %d: %lld/2\n",++tc,n*(n-1)/2) ;
        else printf("Case %d: %lld\n",++tc,n*(n-1)/4) ;
    }
}
