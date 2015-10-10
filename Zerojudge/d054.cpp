#include<stdio.h>
#define LL long long
LL a[50] ;
main()
{
    a[0]=1 ; a[1]=1 ; a[2]=5 ;
    for(int i=3;i<=40;i++) a[i]=4*a[i-2]+a[i-1]+2*a[i-3] ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]) ;
    }
}
