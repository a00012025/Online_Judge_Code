#include <stdio.h>
main ()
{
 char s[100] ;
 int a,i,j ;
 while (scanf ("%s",s)==1)
 {
  for (i=0 ; s[i]!='\0' ; i++) ;
  for (j=0 ; j<i-1 ; j++)
  {
  a=s[j+1]-s[j] ;
  if (a>=0) printf ("%d",a) ;
  else printf ("%d",-a) ;
  }
 printf ("\n") ; 
 }
}
