#include <stdio.h>
main () 
{
     int a,b,c,d ;
     while (scanf ("%d %d",&a,&b)==2) 
      {
     if (a<b) {
               c=((b-a)/2) ;
               c=c+1 ;
               printf ("%d",c) ;
               }
     else if (b%2==0) {
                   printf ("1") ;
                   }
     else {
          printf ("0") ;
          }
      }
}
