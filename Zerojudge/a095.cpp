#include <stdio.h> 
main () 
{
 int a,b ;
 while (scanf ("%d %d",&a,&b)==2)
 {
   if (a!=b)
   {
   printf ("%d\n",b+1) ;
   }
   else
   {
   printf ("%d\n",b) ;
   }
 }
} 
