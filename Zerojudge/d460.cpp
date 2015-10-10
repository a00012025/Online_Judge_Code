#include <stdio.h>
main () 
{
 int a ;
 while (scanf ("%d",&a)==1)
{ 
  if ((a>=0) && (a<=5)) 
  {
  printf ("0") ;
  }
    else if ((a>=6) && (a<=11)) 
  {
  printf ("590") ;
  }
    else if ((a>=12) && (a<=17)) 
  {
  printf ("790") ;
  }
    else if ((a>=18) && (a<=59)) 
  {
  printf ("890") ;
  }
    else {
         printf ("399") ;
         }
}
}
