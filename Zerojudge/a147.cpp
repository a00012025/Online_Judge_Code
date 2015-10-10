#include <stdio.h>
main ()
{
  int a,x=1 ;
  while (scanf ("%d",&a)==1)
  {
    if (a==0) break  ;
    else 
    {
    while (a>x) 
    {
      if (a==x+1)
      {
         if (x%7 !=0)
         {
         printf ("%d\n",x) ;
         x=1 ;
         break ;
         }
      }
      else
      {
         if (x%7 !=0)
         {
         printf ("%d ",x) ;
         x=x+1 ;
         }
         else
         {
         x=x+1 ;
         }
      }
    }
    } 
  }
  scanf (" ") ;
   
  
}
