#include <stdio.h>
main()
{
 int a ;
 scanf ("%d",&a) ;
 while (scanf ("%d",&a)==1)
 {
 a=a%9 ;
 if (a==0) a+=9 ;
 printf ("%d, ",a) ;
 if (a==2)printf ("Yes\n") ;
 else printf ("No\n") ;       
 }

}
