#include <stdio.h> 
main () 
{
 int s[170000] ;
 int a,n,m,i ;
 scanf ("%d",&n) ;
 n=1 ;
 for (i=1 ; i<=170000 ; i++) 
   {
   n=n*10 ;
   s[i]=n/17 ;
   n=n-s[i]*17 ;
   }
 while (scanf ("%d",&a)==1)
 {
 m=0 ;
 printf ("%d ",s[a]) ;
 for (i=1 ; i<=a ; i++) m+=s[i] ;
 printf ("%d\n",m) ;
 }
 
}
