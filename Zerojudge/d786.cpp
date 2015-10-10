#include <stdio.h>
main() 
{
 int a,n,m,i,j,k=0,x=0 ;
 float s[100] ;
 double b,c ;
 while (scanf ("%d",&n)==1)
{
  for (i=n ; i>0 ; i--)
  {
    scanf ("%d",&m) ;
    for (j=m ; j>0 ; j--)
    {
    scanf ("%d",&a) ;
    x+=a ;
    }
   b=x ;
   c=m ; 
   s[k]= b/c ;
   x=0 ;
   k++ ;
  }
  for (k=0 ; k<n ; k++) printf ("%.2lf\n",s[k]) ;
  k=0 ;
}
}
