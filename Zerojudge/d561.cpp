#include <stdio.h> 
main () 
{
 char s[10000] ;
 int i,j ;
 while (scanf ("%s",s)==1)
 {
  if (s[0]!='-')
  {
    for (i=0 ; s[i]!='\0' ; i++) ;
    if (s[4]>='5') s[3]++ ;
    if (s[3]==':') 
    {
     s[3]='0' ;
     s[2]++ ;
    }
    if (s[2]==':')
    {
     s[2]='0' ;
     s[0]++ ;
    }
    for (j=0 ; (j<4)&&(s[j]!='\0') ; j++)printf ("%c",s[j]) ;
    if (i==3) printf ("0") ;
    printf ("\n") ;
 }
 else if (s[0]=='-')
 {
    for (i=0 ; s[i]!='\0' ; i++) ;
    if (s[5]>='5') s[4]++ ;
    if (s[4]==':') 
    {
     s[4]='0' ;
     s[3]++ ;
    }
    if (s[3]==':')
    {
     s[3]='0' ;
     s[1]++ ;
    }
    if ((s[1]=='0')&&(s[3]=='0')&&(s[4]=='0')) printf ("0.00\n") ;
    else{
    for (j=0 ; (j<5)&&(s[j]!='\0') ; j++) printf ("%c",s[j]) ;
    if (i==4) printf ("0") ;
    printf ("\n") ;
    }
 }
}
}
