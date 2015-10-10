#include <stdio.h> 
main () 
{
 int s[500] ;
 int a,n,i,j,min,K  ;
 while (scanf ("%d",&n)==1)
 {
  min=10000 ;
  for (i=1 ; i<=n ; i++) scanf ("%d",&s[i]) ;
  for (i=1 ; i<=n ; i++)
    {
    if (s[i]<=min) min=s[i] ;
    }
  for (i=min ; i>=1 ; i--)
    {
    K=1 ;
      for (j=1 ; j<=n ; j++)
      {
      if ((s[j]%i)!=0) K*=0 ;
      else K*=1 ;
      }  
    if (K==1) break ;    
    }
 printf ("%d\n",i) ;
 }

}
