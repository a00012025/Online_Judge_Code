#include <stdio.h>
main() 
{
 char s[100] ;
 int n=1 ;
 while (scanf ("%s",s)==1)
 {
  if (s[0]=='#') break ;
  else if ((s[0]=='H')&&(s[1]=='E')&&(s[2]=='L')&&(s[3]=='L')&&(s[4]=='O')&&(s[5]=='\0')) printf ("Case %d: ENGLISH\n",n) ;
  else if ((s[0]=='H')&&(s[1]=='O')&&(s[2]=='L')&&(s[3]=='A')&&(s[4]=='\0')) printf ("Case %d: SPANISH\n",n) ;
  else if ((s[0]=='H')&&(s[1]=='A')&&(s[2]=='L')&&(s[3]=='L')&&(s[4]=='O')&&(s[5]=='\0')) printf ("Case %d: GERMAN\n",n) ;
  else if ((s[0]=='B')&&(s[1]=='O')&&(s[2]=='N')&&(s[3]=='J')&&(s[4]=='O')&&(s[5]=='U')&&(s[6]=='R')&&(s[7]=='\0')) printf ("Case %d: FRENCH\n",n) ;
  else if ((s[0]=='C')&&(s[1]=='I')&&(s[2]=='A')&&(s[3]=='O')&&(s[4]=='\0')) printf ("Case %d: ITALIAN\n",n) ; 
  else if ((s[0]=='Z')&&(s[1]=='D')&&(s[2]=='R')&&(s[3]=='A')&&(s[4]=='V')&&(s[5]=='S')&&(s[6]=='T')&&(s[7]=='V')&&(s[8]=='U')&&(s[9]=='J')&&(s[10]=='T')&&(s[11]=='E')&&(s[12]=='\0')) printf ("Case %d: RUSSIAN\n",n) ;
  else printf ("Case %d: UNKNOWN\n",n) ;
  n+=1 ;
 }

}
