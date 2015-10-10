#include <stdio.h>
main() 
{
 int a,b,c,n,i ;
 while (scanf ("%d",&n)==1)
 {
  b=1 ;
  c=1 ;      
  for (i=n-1 ; i>0 ; i--)
  {
  a=b+c ;
  b=c ;
  c=a ;
  }
  if (n==1) printf ("1\n") ;
  else printf ("%d\n",a) ;
 } 
}
