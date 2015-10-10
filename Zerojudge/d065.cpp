#include <stdio.h>
main () 
{
 int a,b,c ;
 while (scanf ("%d %d %d",&a,&b,&c)==3)
 {
 if ((a>b) && (a>c))
  {
  printf ("%d",a) ;
  }
  else  if ((b>c) && (b>a))
  {
  printf ("%d",b) ;
  }
  else 
  {
  printf ("%d",c) ;
  }
        
 }
 }
