#include<stdio.h>
main()
{
    int a,b,c,x,y,z ; scanf("%d%d%d",&a,&b,&c) ;
    z=a-c ; b-=8*z ;
    y=(b-2*c)/2 ; x=c-y ;
    printf("%d\n%d\n%d\n",x,y,z) ;
}
