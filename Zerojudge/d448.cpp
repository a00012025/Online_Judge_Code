#include <stdio.h> 
main () 
{
   double a,b,c,d,e ;
   double f,g,h,i ;
   while (scanf ("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e)==5)
   {
    f=d-e ;
    g=b-a ;
    h=a-c ;
    i=(f*g)/h ;
    printf ("%lf\n",d+i) ;
   }
}
