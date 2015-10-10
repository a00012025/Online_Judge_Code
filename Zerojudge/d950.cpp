#include <stdio.h>
main()
{
 int a,b,n,x,y,z,i ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 x=1 ;
 y=1 ;
 z=1 ;       
 a=a-1 ;
 b=b-1 ;
 for (i=1 ; i<=a ; i++) x*=i ;
 for (i=1 ; i<=b ; i++) y*=i ;
 for (i=1 ; i<=a-b ; i++) z*=i ;
 printf ("%d\n",x/y/z) ;
 }
}
