#include <stdio.h>
main() 
{
 int a,n,m=0,i ;
 while (scanf ("%d",&n)==1)
{
  for (i=n ; i>0 ; i--)
  {
  scanf ("%d",&a) ;
  m+=a ;
  }
  if (m>59*n) printf ("no\n") ;
  else printf ("yes\n") ;
  m=0 ;
}
}
