#include <stdio.h>
#include <math.h>
main ()
{
 int a,b,i ;
 double c ;
 while (scanf ("%d",&a)==1)
 {
 if (a==0) break ;
 c=sqrt(a) ;
 if (a==2) b=1 ;
 else if (a==1) b=0 ;
 else
 {
   for (i=2 ; i<=c ; i++)
   {
     if ((a%i)==0)
     {
     b=0 ;
     break ;
     }
     else  b=1 ;

   } 
 }
 if (b==0) printf ("1\n") ;
 else printf ("0\n") ; 
}   
scanf (" ") ;
}
