#include<stdio.h>
#define LL long long
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n,m,k=1 ;
        scanf("%lld %lld",&n,&m) ;
        while(k*(k-1)/2+n-k<m) k++ ;
        printf("%lld\n",n-k) ;
    }
}
