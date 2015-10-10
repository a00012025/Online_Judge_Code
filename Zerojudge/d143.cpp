#include <stdio.h>
main()
{
 int a,b,n ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 if (a>b) printf (">\n") ;
 if (a==b) printf ("=\n") ;
 if (a<b) printf ("<\n") ;
 }
}
