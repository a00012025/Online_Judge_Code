#include <stdio.h>
main() 
{
int a,b,c ;
while(scanf ("%d %d",&a,&b)==2)
            {
             c=(a*2+b)%3  ;  
             if (c==0) {
                      printf ("´¶³q\n") ;
                      }
             else if (c==1) {
                           printf ("¦N\n") ;
                           }
             else {
                  printf ("¤j¦N\n") ;
                  }              
            }       
}
