#include <stdio.h>
main () 
{
 char s[10000] ;
 int i,j,z,n ; 
 while (scanf ("%s",s)==1)
 {
  for (i=0 ; s[i]!='\0' ; i++)  ; 
  for (j=0 ; j<=i ; j++)
  {
   if (s[j]!=s[i-j-1]) 
    {
    z=1 ;
    break ; 
    } 
   else z=0 ; 
  } 
  if (z==0) printf ("yes\n") ;
  else printf ("no\n") ; 
 }     
}
