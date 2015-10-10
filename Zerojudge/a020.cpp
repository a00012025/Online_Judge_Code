#include <stdio.h>
main() 
{
 int a ;
 char s[10] ;
 while (scanf ("%s",s)==1)
 {
 if (s[0]=='A') a=1 ;
 if (s[0]=='B') a=10 ;
 if (s[0]=='C') a=19 ;
 if (s[0]=='D') a=28 ;
 if (s[0]=='E') a=37 ;
 if (s[0]=='F') a=46 ;
 if (s[0]=='G') a=55 ;
 if (s[0]=='H') a=64 ;
 if (s[0]=='I') a=39 ;
 if (s[0]=='J') a=73 ;
 if (s[0]=='K') a=82 ;
 if (s[0]=='L') a=2 ;
 if (s[0]=='M') a=11 ;
 if (s[0]=='N') a=20 ;
 if (s[0]=='O') a=48 ;
 if (s[0]=='P') a=29 ;
 if (s[0]=='Q') a=38 ;
 if (s[0]=='R') a=47 ;
 if (s[0]=='S') a=56 ;
 if (s[0]=='T') a=65 ;
 if (s[0]=='U') a=74 ;
 if (s[0]=='V') a=83 ;
 if (s[0]=='W') a=21 ;
 if (s[0]=='X') a=3 ;
 if (s[0]=='Y') a=12 ;
 if (s[0]=='Z') a=30 ;
 a+=(8*s[1])+(7*s[2])+(6*s[3])+(5*s[4])+(4*s[5])+(3*s[6])+(2*s[7])+(1*s[8])+s[9]-('0')*37 ;
 if (a%10==0) printf ("real\n") ;
 else printf ("fake\n") ;                   
 }
 
 
 
 
}
