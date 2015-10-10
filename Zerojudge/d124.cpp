#include <stdio.h>
main() 
{
 char s[10000] ;
 int i,j,x ;
 while (scanf ("%s",s)==1)
 {
 x=0 ;       
 if (s[0]!='-')
   {
   for (i=0 ; s[i]!='\0' ; i++) x+=s[i]-'0' ;
   }
 else if (s[0]=='-')
   {
   for (i=1 ; s[i]!='\0' ; i++) x+=s[i]-'0' ;
   } 
 if ((x%3)==0) printf ("yes\n") ;
 else printf ("no\n") ;    
 }
}
