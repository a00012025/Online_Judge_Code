#include<stdio.h>
main()
{
    int n,a[10000] ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=n-1;i>=0;i--) printf("%d%c",a[i],i?' ':'\n') ;
}
