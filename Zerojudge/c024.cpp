#include <stdio.h>
main()
{
 long long int a ;
 while (scanf ("%lld",&a)==1)
 {
 if (a<0) break ;
 printf ("%lld\n",a*(a+1)/2+1) ;
 }
 scanf (" ") ;

}
