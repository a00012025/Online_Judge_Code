#include <stdio.h>
main () 
{
  int a,b,c,d ;
  while (scanf ("%d %d %d",&a,&b,&c)==3)
    {
    d=(a+b+c)/2 ;
    printf ("%d",d*(d-a)*(d-b)*(d-c)) ;
    }       
}
