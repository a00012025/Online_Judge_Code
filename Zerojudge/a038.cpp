#include <stdio.h>
main()
{
 char s[1000] ;
 int i,j,k ;
 while (scanf ("%s",s)==1)
 {
   for (i=0 ; s[i]!='\0' ; i++) ;
   for (j=i-1 ; (s[j]=='0')&&(j>=0) ; j--) ;
   for (k=j ; k>=0 ; k--) printf ("%c",s[k]) ;
   printf ("\n") ;
    
 }
}
