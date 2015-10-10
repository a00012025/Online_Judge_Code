#include <stdio.h> 
main () 
{
 int a,b,c ;
 scanf ("%d",&a) ;
 while (scanf ("%d %d %d",&a,&b,&c)==3)
 {
  if ((a!=b)&&(b!=c)&&(c!=a)) printf ("YES\n") ;
  else printf ("NO\n") ;
 }

}
