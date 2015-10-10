#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100001] ;
main()
{
    int n,num=0 ;
    while(scanf("%d",&n)!=EOF)
    {
        num++ ;
        a[num]=n ;
        sort(&a[1],&a[num+1]) ;
        if(num%2==1) printf("%d\n",a[1+(num/2)]) ;
        else printf("%lld\n",((long long)a[num/2]+a[(num+2)/2])/2) ;
    }
}
