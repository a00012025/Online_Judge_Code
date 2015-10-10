#include <stdio.h> 
main()
{
 int a,x,i ;
 while (scanf ("%d",&a)==1)
 {
 x=0 ;  
 for (a=a ; a>=5 ; a=a)
 {
   x+=a/5 ;
   a=a/5 ;
 }
 printf ("%d\n",x) ;
 }
}
