#include <stdio.h>
main() 
{
 int a,b,x,y ;
 while (scanf ("%d %d",&a,&b)==2)
 {
  x=a       ;
  for (y=1 ; x<=b ; y++)
   {
   a=a+1 ;
   x=x+a ;
   }
  printf ("%d\n",y) ;
 }
}
