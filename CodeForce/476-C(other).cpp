#include<stdio.h>
#define LL long long
#define MOD 1000000007
main()
{
    LL a,b ;
    LL p=1000000007 ;
    scanf("%d%d",&a,&b);
    printf("%I64d\n",b*(b-1)%p*a%p*250000002%p*((a+1)*b%p+2));
}
