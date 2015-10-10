#include <stdio.h>
#include <math.h>
main () 
{ 
int a,b,c ; 
int x,y ;
while (scanf("%d %d %d",&a,&b,&c)==3) 
     {
    if (b*b-4*a*c>0) 
        {
        x=(-b+sqrt(b*b-4*a*c))/(2*a) ; 
        y=(-b-sqrt(b*b-4*a*c))/(2*a) ; 
        printf ("Two different roots x1=%d , x2=%d\n",x,y); 
        } 
        
    else if (b*b-4*a*c==0) 
        {
        x=(-b+sqrt(b*b-4*a*c))/(2*a) ; 
        printf ("Two same roots x=%d\n",x); 
        }
        
    else {
        printf ("No real root\n"); 
        }
     }
} 
