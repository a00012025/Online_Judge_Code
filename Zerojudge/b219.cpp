#include<stdio.h>
#define LL long long
LL a[10000001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    a[1]=a[2]=1LL ;
    for(int i=3;i<=n;i++)
    {
        a[i]=(i-1)*a[i-1]+(i-2)*a[i-2] ;
        a[i]%=m ;
    }
    printf("%lld\n",a[n]) ;
}
