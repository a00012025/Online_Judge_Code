#include <stdio.h>
main() 
{
 int a,b,c,d,n=1,m ;
 scanf ("%d",&m) ;
 while (scanf ("%d",&a)==1 ) {  
 b=a % 4 ;
 c=a % 100 ;
 d=a % 400 ;
 if (d==0) {
           printf ("Case %d: a leap year\n",n) ;
           n+=1 ;
           }
 else if ((b==0)&&(c!=0)) {
                          printf ("Case %d: a leap year\n",n) ;
                          n+=1 ;
                          }
 else {
      printf ("Case %d: a normal year\n",n) ;
      n+=1 ;
      }
      }
}
