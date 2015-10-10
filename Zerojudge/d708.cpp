#include<stdio.h>
#define LL long long
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        LL x=0LL ;
        for(int i=1;i<n;i++) {LL y ; scanf("%lld",&y) ; x^=y ;}
        printf("%lld\n",x) ;
    }
}
