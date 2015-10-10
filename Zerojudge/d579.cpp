#include <stdio.h>
main () 
{
 int a,b ;
 double c ;
 while (scanf("%lf",&c)==1 )
   {
   a=(int)(c) ;
   b=10000*(c-a+0.000000001) ;
   if (a>0) 
     {  
         if (b>=1000) {
                printf ("|%d.%d|=%d.%d\n",a,b,a,b) ;
                }
         else if (b>=100) {
             printf ("|%d.0",a) ;
             printf ("%d|=%d.0",b,a) ;
             printf ("%d\n",b) ;
              }
         else if (b>=10) {
             printf ("|%d.00",a) ;
             printf ("%d|=%d.00",b,a) ;
             printf ("%d\n",b) ;
              }
        else {
             printf ("|%d.000",a) ;
             printf ("%d|=%d.000",b,a) ;
             printf ("%d\n",b) ;
             }
     }
    else if (a==0)
     {  
        if (c>0)
        {
               if (b>=1000) 
                {
                printf ("|%d.%d|=%d.%d\n",a,b,-a,b) ;
                }
               else if (b>=100) 
               {
               printf ("|%d.0",a) ;
               printf ("%d|=%d.0",b,-a) ;
               printf ("%d\n",b) ;
               }
               else if (b>=10) 
               {
               printf ("|%d.00",a) ;
               printf ("%d|=%d.00",b,-a) ;
               printf ("%d\n",b) ;
               }
               else 
               {
               printf ("|%d.000",a) ;
               printf ("%d|=%d.000",b,-a) ;
               printf ("%d\n",b) ;
               }
         }        
         else 
         {
           b=10000*(a-c+0.000000001) ;
               if (b>=1000) 
                {
                printf ("|-%d.%d|=%d.%d\n",a,b,-a,b) ;
                }
               else if (b>=100) 
               {
               printf ("|-%d.0",a) ;
               printf ("%d|=%d.0",b,-a) ;
               printf ("%d\n",b) ;
               }
               else if (b>=10) 
               {
               printf ("|-%d.00",a) ;
               printf ("%d|=%d.00",b,-a) ;
               printf ("%d\n",b) ;
               }
               else 
               {
               printf ("|-%d.000",a) ;
               printf ("%d|=%d.000",b,-a) ;
               printf ("%d\n",b) ;
               }
         }
     }
     else
     {
      b=10000*(a-c+0.000000001) ;
               if (b>=1000) 
                {
                printf ("|%d.%d|=%d.%d\n",a,b,-a,b) ;
                }
               else if (b>=100) 
               {
               printf ("|%d.0",a) ;
               printf ("%d|=%d.0",b,-a) ;
               printf ("%d\n",b) ;
               }
               else if (b>=10) 
               {
               printf ("|%d.00",a) ;
               printf ("%d|=%d.00",b,-a) ;
               printf ("%d\n",b) ;
               }
               else 
               {
               printf ("|%d.000",a) ;
               printf ("%d|=%d.000",b,-a) ;
               printf ("%d\n",b) ;
               }
     }
   }  
}
