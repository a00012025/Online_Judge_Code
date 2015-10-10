#include <stdio.h>
main ()
{
  long long a,b,c,d ;
  while (scanf ("%lld",&a)==1)
  {
  b=(a*a+a)/2 ;
  c=(a*a*a)/6 + (3*a*a)/6 + (2*a)/6 ;
  d=(a*a*a)%6 + (3*a*a)%6 + (2*a)%6 ;
  printf ("%lld %lld\n",b,c+(d/6)) ;
  }


}
