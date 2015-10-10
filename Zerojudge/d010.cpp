#include <stdio.h>
main() 
{
 int a,i,x ;
 while (scanf ("%d",&a)==1)
 {
  x=0 ;      
    for (i=1 ; i<a ; i++)
    {
     if ((a%i)==0) x=x+i ;
    }
  if (x>a) printf ("盈數\n") ;
  else if (x==a) printf ("完全數\n") ;
  else if (x<a) printf ("虧數\n") ;
  
 }


}
