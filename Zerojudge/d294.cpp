#include <stdio.h>
main()
{
 int a,b,c ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 c=a*(a+1)*b*(b+1)/4 ;
 printf ("%d\n",c) ;
 }

}
