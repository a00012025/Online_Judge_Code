#include <stdio.h> 
main () 
{
 int a,m,i ;
 scanf ("%d",&a) ;
 while (scanf ("%d",&a)==1)
 {
  for (i=0 ; a>0 ; i++)
    {
    if (a>=27) a=a-27 ;
    else if (a>=9) a=a-9 ;
    else if (a>=3) a=a-3 ;
    else if (a>=1) a=a-1 ;
    }
 printf ("%d\n",i) ;
 }

}
