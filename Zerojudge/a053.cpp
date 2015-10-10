#include <stdio.h>
main () 
{
 int a ;
 while (scanf ("%d",&a)==1)
{
 if ((a>=0) && (a<=10))
  {
  printf ("%d",6*a) ;
  }
 else if ((a>10) && (a<=20)) 
  {
  printf ("%d",2*a+40) ;
  }
 else if ((a>20) && (a<=40))
 {
 printf ("%d",a+60) ;
 }
 else
 {
 printf ("100") ;
 }
}
}
