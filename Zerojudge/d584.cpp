#include <stdio.h>
main ()
{
  int a,b ;
  while (scanf ("%d %d",&a,&b)==2)
  {
   if (a==0)
   {
   printf ("0\n") ;  
   }
   else if (a==2)
   {
      if (b<30)
      {
      printf ("%d\n",3*b-23) ; 
      }
      else if (b<70)
      {
      printf ("%d\n",3*b-22) ;
      }
      else if (b<120)
      {
      printf ("%d\n",3*b-21) ;
      }
      else
      {
      printf ("%d\n",3*b-18) ;
      }
   }
   else
   {
      if (b<30)
      {
      printf ("%d\n",3*b-29) ; 
      }
      else if (b<70)
      {
      printf ("%d\n",3*b-28) ;
      }
      else if (b<120)
      {
      printf ("%d\n",3*b-27) ;
      }
      else
      {
      printf ("%d\n",3*b-24) ;
      }
   }
  }


}
