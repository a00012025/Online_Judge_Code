#include <stdio.h>
main()
{
 int a,b,c ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 c=(a-b)%2 ;
 if ((a==0)&&(b==0)) break ;
 else if (c==0) printf ("Win\n") ;
 else printf ("Loss\n") ;
 }
 scanf (" ") ;
}
