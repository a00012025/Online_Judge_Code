#include <stdio.h>
#include <math.h>
main ()
{
 int  a,b,c,d,e,f,x=1,i ;
 double y ;
 scanf ("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f) ;
  for (i=0 ; i<b ; i++)
  {
  x*=a ;
  }
  printf ("%d\n",x) ;
  y=sqrt(c) ;
  printf ("%.3f\n",y) ;
  if (d>=0) printf ("%d\n",d) ;
  else printf ("%d\n",-d) ;
  printf ("%d\n",e) ;
 scanf (" ") ;

} 
