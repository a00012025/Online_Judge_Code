#include <stdio.h>
main () 
{
 int a,b,n,m ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d",&a,&b)==2)
 {
   for (b=b ; b>0 ; b=b-1)
   {
     for (m=1 ; m<=a ; m++)
      {  
       for (n=m ; n>0 ; n=n-1)
       {
       if (n>1) printf ("%d",m) ;
       else printf ("%d\n",m) ;
       }
      }
     for (m=a-1 ; m>=1 ; m=m-1)  
      {
        for (n=m ; n>0 ; n=n-1)
        {
        if (n>1) printf ("%d",m) ;
        else printf ("%d\n",m) ;
        } 
      }
   printf ("\n") ;
   }
 }    
}
