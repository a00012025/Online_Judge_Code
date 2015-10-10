#include <stdio.h>
main()
{
 int a,x,y=1,m=0,n=0 ;
 while (scanf ("%d",&a)==1)
 {
 x=a-1 ;
   while (x>=0)
   {
      while (x>m)
      {
      if (x>m+1)
        {
        printf ("_") ;
        m=m+1 ;
        }
      else 
        {
        printf ("_") ;
        m=0 ;
        break ;
        }  
      }
      while (y>n)
      {
      if (y>n+1) 
        {
        printf ("+") ;
        n=n+1 ;
        }
      else 
        {
        printf ("+\n") ;
        n=0 ;
        break ;
        }
      }
   x=x-1 ;
   y=y+1 ;
   }
 y=1 ;
}
}
