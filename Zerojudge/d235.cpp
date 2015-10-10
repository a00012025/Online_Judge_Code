#include <stdio.h> 
main () 
{
 int x,y,i,j,k ;
 char s[1000] ;
 while (scanf ("%s",s)==1)
 {
 if (s[0]=='0') break ;       
 x=0 ;
 y=0 ;       
 for (k=0 ; s[k]!='\0' ; k++) ;
 for (i=0 ; i<k ; i=i+2) x=x+s[i]-'0' ;
 for (j=1 ; j<k ; j=j+2) y=y+s[j]-'0' ;
 if ((x-y)%11==0)
  {
  for (i=0 ; i<k ; i++) printf ("%c",s[i]) ;
  printf (" is a multiple of 11.\n") ;
  }
 else
  {
  for (i=0 ; i<k ; i++) printf ("%c",s[i]) ;
  printf (" is not a multiple of 11.\n") ;
  } 
 }
}
