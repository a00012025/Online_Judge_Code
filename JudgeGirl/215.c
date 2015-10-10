#include<stdio.h>
#include<stdlib.h>
void err(){ printf("0\n") ; exit(0) ; }
main()
{
    int a,b,c,x,y,z ; scanf("%d%d%d",&a,&b,&c) ;
    if(!(b>=a && a>=c)) err() ;
    z=a-c ;
    if(z>2147483647/8 || c>2147483647/2) err() ;
    if(2147483647-8*z<2*c || b%2) err() ;
    y=(b-8*z-2*c)/2 ; x=c-y ;
    if(x<0||y<0||z<0) err() ;
    printf("%d\n%d\n%d\n",x,y,z) ;
}
