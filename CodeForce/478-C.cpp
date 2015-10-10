#include<stdio.h>
#define LL long long
#include<algorithm>
using namespace std;
main()
{
    LL a[4] ;
    scanf("%I64d %I64d %I64d",&a[0],&a[1],&a[2]) ;
    sort(a,a+3) ;
    if(a[2]>2*(a[0]+a[1])) printf("%I64d\n",a[0]+a[1]) ;
    else printf("%I64d\n",(a[0]+a[1]+a[2])/3) ;
}
