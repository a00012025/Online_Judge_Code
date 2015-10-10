#include <stdio.h>
main()
{
 long long a ;
 while (scanf ("%lld",&a)==1)
 {
 if (a<0) break ;
 else if (a==1) printf ("0%%\n") ;
 else printf ("%lld%%\n",25*a) ;
 }
 scanf (" ") ; 
}
