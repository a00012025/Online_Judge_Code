#include <stdio.h>
main () 
{
 int a,b,m=1073741824 ,n ;
 while (scanf ("%d",&a)==1)
 {
  b=a ;
   while (a<m)
   {
    m=m/2 ;
   }     
   for (n=m ; n>=1 ; n=(n)/2)
   {
     if (b>=n) {
     printf ("1") ;
     b=b-n ;
     }
     else  {
     printf ("0") ;
     }
    }
   printf ("\n") ;
   m=1073741824 ;
 }
}
