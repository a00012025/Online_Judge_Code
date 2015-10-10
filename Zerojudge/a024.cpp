#include <stdio.h>
main () 
{
 int a,b,c,i ;
 while (scanf ("%lld %lld",&a,&b)==2)
 {  
  c=1 ;      
  for (i=2 ; (i<=a)&&(i<=b) ; i++)
   {
   if ((a%i==0)&&(b%i==0)) c=i ;
   }
  printf ("%lld\n",c) ;
 }
}

