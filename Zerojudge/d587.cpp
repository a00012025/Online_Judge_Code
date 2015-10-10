#include <stdio.h>
main()
{
 int s[1000000],t[1000000] ;
 int i,j,k,n,m,M ;
 while (scanf ("%d",&n)==1)
 {
 M=4 ;
 m=n ;
 for (i=0 ; i<n ; i++) scanf ("%d",&s[i]) ;
 for (k=0 ; k<n ; k++)
   {
    for (i=0 ; i<m ; i++)
      {
      if (s[i]<=M) M=s[i] ; 
      }
    for (i=0 ; s[i]!=M ; i++) ;
    for (j=i ; j<m-1 ; j++) s[j]=s[j+1] ;
    m=m-1 ;
    t[k]=M ;
    M=4 ;
   }
 for (i=0 ; i<n ; i++) printf ("%d ",t[i]) ;
 printf ("\n") ;
 }
}
