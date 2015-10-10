#include <stdio.h>
main() 
{
 char s ;
 int n,m=0 ;
 scanf ("%d",&n) ;
 while (scanf ("%s",&s)==1)
 {     
  if ((s=='a')||(s=='d')||(s=='g')||(s=='j')||(s=='m')||(s=='p')||(s=='t')||(s=='w')||(s==' ')) m+=1 ;
  else if ((s=='b')||(s=='e')||(s=='h')||(s=='k')||(s=='n')||(s=='q')||(s=='u')||(s=='x')) m+=2 ;
  else if ((s=='c')||(s=='f')||(s=='i')||(s=='l')||(s=='o')||(s=='r')||(s=='v')||(s=='y')) m+=3 ;
  else if ((s=='s')||(s=='z')) m+=4 ;
  if (s==32) 
  {
  n+=1 ;
  printf ("Case #%d: %d\n",n,m) ;
  m=0 ;
  }
 }


}
