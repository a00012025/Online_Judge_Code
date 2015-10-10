#include<stdio.h>
#define LL long long
main()
{
    LL a,b ; scanf("%I64d%I64d",&a,&b) ;
    if(a%2) a++ ;
    if(b-a<2) printf("-1\n") ;
    else printf("%I64d %I64d %I64d\n",a,a+1,a+2) ;
}
