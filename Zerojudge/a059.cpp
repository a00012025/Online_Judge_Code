#include <stdio.h>
main () 
{
 int a,b,n,x=1,y=0 ;
 scanf ("%d",&n) ;
 n=1 ; 
 while (scanf ("%d %d",&a,&b)==2)
 {
   for (x=1 ; x<46341 ; x=x+1 ) 
   { 
     if  ((a<=x*x) && (b>=x*x)) 
     {
     y=y+x*x ; 
     } 
   } 
  printf ("Case %d: %d\n",n,y) ;
  y=0 ; 
  n=n+1 ; 
 } 

     
} 
