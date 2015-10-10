#include <stdio.h> 
#include <math.h> 
main () 
{
 int a,b ;
 double p,c,d ;
 while (scanf("%d %d",&a,&b)==2)
 {
 p=3.14159265358979232 ;
 c=sqrt(b*b-a*a) ;
 d=p*c*b/4 ;
 printf ("%.3lf\n",d) ;
 } 
    
}
