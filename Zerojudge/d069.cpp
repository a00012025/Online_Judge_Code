#include <stdio.h>
main() 
{
 int a,b,c,d,n ;
      scanf ("%d",&n) ;
      while (scanf ("%d",&a)==1 ) 
          {  
      b=a % 4 ;
      c=a % 100 ;
      d=a % 400 ;
       if (d==0) {
                 printf ("a leap year\n") ;
                 scanf (" ") ;
                 }
       else if ((b==0)&&(c!=0)) {
                                printf ("a leap year\n") ;
                                scanf (" ") ;
                                }
       else {
            printf ("a normal year\n") ;
            scanf (" ") ;
            }
            }
        scanf (" ") ;
}
