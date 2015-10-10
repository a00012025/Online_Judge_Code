#include <stdio.h>
main ()
{
 int a,n,M=0 ;
 scanf ("%d",&n) ;
 while (scanf ("%d",&a)==1)
 {
 if (a>M) M=a ;
 if (n==1) break ;       
 n=n-1 ;
 }
 printf ("%d\n",M) ;
 scanf (" ") ;

}
