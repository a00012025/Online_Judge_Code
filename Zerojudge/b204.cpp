#include <stdio.h> 
main () 
{
 int s[50] ;
 int n,i,M ;
 while (scanf ("%d",&n)==1)
 {
 if (n==0) break ;
 M=0 ;
 for (i=1 ; i<=n ; i++) scanf ("%d",&s[i]) ;
 for (i=1 ; i<n ; i++)
  {
  if (s[i+1]>s[i]) M+=20*(s[i+1]-s[i]) ;
  else M+=10*(s[i]-s[i+1]) ;
  }
 printf ("%d\n",M) ; 
 }

}
