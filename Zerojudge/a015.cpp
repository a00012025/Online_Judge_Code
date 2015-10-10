#include <stdio.h>
main ()
{
 int m,n,i,j ;
 int a[100][100]  ; 
 while (scanf ("%d %d",&m,&n)==2)
 {
  for  (i=0 ; i<m ; i+=1)
  {
    for (j=0 ; j<n ; j+=1)
    {
    scanf ("%d",&a[i][j]) ; 
    } 
  } 
  
  for  (j=0 ; j<n ; j+=1)
  {
    for (i=0 ; i<m ; i+=1)
    {
    printf  ("%d ",a[i][j]) ; 
    } 
   printf ("\n") ; 
  } 
 }    

} 
