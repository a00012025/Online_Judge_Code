#include <stdio.h> 
main () 
{
   long int a ;
   double b,c ;

   while (scanf ("%d",&a)==1)
   {
   b=-160/9+a/9+a/9+a/9+a/9+a/9 ;
   c=(a%9)*5 ;
   printf ("%.3lf\n",b-((7-c)/9)) ;
   }  
   
}
