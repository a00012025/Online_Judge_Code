#include <stdio.h>
main() 
{
 int a,b,c,m=0,n=0 ;
 while (scanf ("%d %d %d",&a,&b,&c)==3)
 {
 if ((a+b>c)&&(b+c>a)&&(a+c>b)) m+=1 ;
 n+=1 ; 
 if (n==5) break ;
 }
 printf ("%d",m); 
 scanf (" ") ;

}
