#include <stdio.h> 
main () 
{
   int a,b ;
   while (scanf ("%d",&a)==1)
   {
     b=2*a*a*a+3*a*a+a ;
     if (a!=0)
     {
     printf ("%d\n",b/6) ;
     }
   }


}
