#include <stdio.h>
main () 
{
 long long a,b,c,n ;
 scanf ("%lld",&n) ;
 while (scanf ("%lld %lld %lld",&a,&b,&c)==3)
 {
 if (a==1) printf ("%lld\n",b+c) ;
 else if (a==2) printf ("%lld\n",b-c) ;
 else if (a==3) printf ("%lld\n",b*c) ;
 else if (a==4) printf ("%lld\n",b/c) ;
 }

}
