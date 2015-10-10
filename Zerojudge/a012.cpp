#include <stdio.h>
main ()
{
 long long int  a,b ;
 while (scanf ("%lld %lld",&a,&b)==2) 
    {
    if (a-b>0) {
               printf ("%lld",a-b) ;
               }
    else {
         printf ("%lld",b-a) ;
         }
    }
}
