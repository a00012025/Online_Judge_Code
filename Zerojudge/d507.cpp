#include <stdio.h>
main () 
{
 int a,b,c ;
 while (scanf ("%d %d %d",&a,&b,&c)==3)
 {
  if ((a>b) && (a>c))
   {
    if ((c*c)+(b*b) > (a*a))
    {
    printf ("acute triangle") ;
    }      
    else if ((c*c)+(b*b) == (a*a))
    {
     printf ("right triangle")   ;  
    }
    else 
    {
    printf ("obtuse triangle") ;
    }
   }
  else if ((b>a) && (b>c))  
   {
    if ((a*a)+(c*c) > (b*b))
    {
    printf ("acute triangle") ;
    }      
    else if ((a*a)+(c*c) == (b*b))
    {
     printf ("right triangle")   ;  
    } 
    else 
    {
    printf ("obtuse triangle") ;
    }
   } 
   else
    {
    if ((a*a)+(b*b) > (c*c))
    {
    printf ("acute triangle") ;
    }      
    else if ((a*a)+(b*b) == (c*c))
    {
     printf ("right triangle")   ;  
    }
    else 
    {
    printf ("obtuse triangle") ;
    }
    }

}
}

