#include <stdio.h>
main ()
{
 int a,b ;
 while (scanf ("%d",&a)==1)
       {
        b=(a+1)*(a*a-a+6)/6 ;
        printf ("%d\n",b) ;
       }
}
