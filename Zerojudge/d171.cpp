#include <stdio.h>
#include <math.h>
main()
{
 int a,b,y ;
 double x ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 x=log10(a) ;
 x=x*b ;
 y=int(x) ;
 printf ("%d\n",y+1) ;
 }
}
