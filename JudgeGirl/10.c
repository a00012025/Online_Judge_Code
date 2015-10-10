#include<stdio.h>
main()
{
    int a,b,ans=1 ; scanf("%d%d",&a,&b) ;
    while(b--) ans*=a ;
    printf("%d\n",ans) ;
}
