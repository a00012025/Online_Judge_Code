#include <stdio.h>
main() 
{
 int a,b,c,d ;
 while (scanf ("%d",&a)==1 ) {  
 b=a % 4 ;
 c=a % 100 ;
 d=a % 400 ;
 if (d==0) {
           printf ("�|�~\n") ;
           scanf (" ") ;
           }
 else if ((b==0)&&(c!=0)) {
                          printf ("�|�~\n") ;
                          scanf (" ") ;
                          }
 else {
      printf ("���~\n") ;
      scanf (" ") ;
      }
      }
}
