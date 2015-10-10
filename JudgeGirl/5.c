#include<stdio.h>
#define LL long long
main()
{
    LL a,b,c ; scanf("%lld%lld%lld",&a,&b,&c) ;
    printf("%lld\n%lld\n",2*(a*b+b*c+c*a),a*b*c) ;
}
