#include <stdio.h>
main() 
{
 int a=1,b=0,n,m=0 ;
 while (scanf ("%d",&n)==1)
 {
  if (n==-1) break ;
  else
  {      
  while (a<n) 
   {
    a*=2 ;
    b=b+1 ;
   }
  m=m+1 ;
  if (m<10001) printf ("Case %d: %d\n",m,b) ;
  b=0 ;
  a=1 ;

  }
 }



}
