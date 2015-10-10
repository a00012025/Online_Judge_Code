#include <stdio.h>
main() 
{
 char s[10000],c ;
 int n,m=0,i,j,x ;
 while (scanf ("%s",s)==1)
 {
  for (n=0 ; s[n]!='\0' ; n++) ;
  if (((s[0]=='0')&&(s[1]!='\0'))||(s[0]!='0'))      
  {
  for (m=0 ; m<n ; m++) 
  { 
  if (s[m]<'A') break ;
  else if ((s[m]<'a')&&(s[m]>'Z')) break ;
  else if (s[m]>'z') break ;
  }
  if (m!=n) 
  {
  printf ("Fail\n") ;
  continue ;
  }
  else
  {
    x=0 ;    
    for (i=0 ; i<n ; i++) 
      {
      if ((s[i]>='A')&&(s[i]<='Z')) x+=s[i]-'A'+1 ;
      else if ((s[i]>='a')&&(s[i]<='z')) x+=s[i]-'a'+1 ;
      }
    printf ("%d\n",x) ;   
  }
 }
 }  
}
