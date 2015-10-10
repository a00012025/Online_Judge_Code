#include <stdio.h>
main () 
{
 int a,c,d,n,k,S=0 ;
 while (scanf ("%d %d",&n,&k)==2) 
 {
 c=n ;
 a=n ;
 while (a>0)
   {
    S=S+a ;
    a=c/k ;
    c=(c%k) + (c/k) ;
   }
 printf ("%d\n",S) ;
 S=0 ;  
 
 
 }

}
