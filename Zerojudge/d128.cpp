#include <stdio.h>
main()
{
 int a,b,c,x ;
 while (scanf ("%d %d %d",&a,&b,&c)==3)
 {
 x=0 ;
 if (a+10*b+c>x) x=a+10*b+c ;
 if (10*a+b+c>x) x=10*a+b+c ;
 if (a*b*10+a*c>x) x=a*b*10+a*c ;
 if (a*c*10+c*b>x) x=a*c*10+b*c ;
 if (a+b+c>x) x=a+b+c ;
 if (a*c+b*c>x) x=a*c+b*c ;
 if (a*b+c>x) x=a*b+c ;
 if (a*b*c>x) x=a*b*c ;
 printf ("%d\n",x) ;       
 }    
}
