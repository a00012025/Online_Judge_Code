#include <stdio.h> 
main () 
{
 long long a,b ;
  while (scanf ("%lld",&a)==1) 
  {
    b=a/4 ; 
    if (a%4 == 2)
    {
    printf ("%lld\n",b*b+b) ;
    }
    else
    {
    printf ("%lld\n",b*b) ;
    }
  }
}
