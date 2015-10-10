#include <stdio.h>
main() 
{
 int a,b,i,x ;
 while (scanf ("%d %d",&a,&b)==2)
 {
  x=0 ;      
    for (i=a ; i<=b ; i++)
    {
    if ((i%2)==0) x=x+i ;
    }
  printf ("%d\n",x) ;
  x=0 ;  
 
 }
}
