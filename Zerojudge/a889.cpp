#include<stdio.h>
#define LL long long
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int m,n ;
        scanf("%d %d",&m,&n) ;
        LL ans=((LL)n)*(n+1)/2 ;
        int p=n/m,r=n%m ; p-- ;
        ans+=((LL)p)*((LL)p+1)/2*m + ((LL)r)*(p+1) ;
        printf("%lld\n",ans) ;
    }
}
