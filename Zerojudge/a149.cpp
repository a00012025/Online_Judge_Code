#include <stdio.h>
main () 
{
 long long a,m,n,y,x ;
 scanf ("%lld",&y) ; 
 while (scanf ("%lld",&a)==1)
 {
 m=1000000000 ;
 x=1 ; 
  while (a<m) 
  {
  m=m/10 ; 
  }
  while (a>m)
  {
    if (m<1) break ;
    else x*=(a/m)-10*(a/(10*m)) ; 
    m=m/10 ; 
  } 
  if (a==0){
    x=0 ;
        }
  printf ("%lld\n",x) ; 
   x=1 ; 
   m=1000000000 ; 
 } 
} 
