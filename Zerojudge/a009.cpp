#include <stdio.h>
main()
{
 int i,j ;   
 char s[1000] ;
  while (scanf ("%s",s)==1)
  {      
  for (i=0 ; s[i]!='\0' ; i++) ;
    for (j=0 ; j<i ; j++)
    {
    printf ("%c",s[j]-7) ;
    }
    printf ("\n") ;  
  }


}
