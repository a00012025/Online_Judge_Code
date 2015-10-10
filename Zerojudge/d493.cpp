#include <stdio.h>
main() 
{
 int a,b,i,x ;
 while (scanf ("%d %d",&a,&b)==2)
 {
   x=1 ;
   if ((a==-1)&&(((b+1)%2)==0))  x=-1 ;
   else if ((a==-1)&&((b%2)==0)) x=1  ;
   else if (a==0) x=0 ;
   else if (a==1) x=1 ;
   else 
     {
       for (i=1 ; i<=b ; i++)
       {
       x*=a ;
       }
     }
  printf ("%d\n",x) ; 
 } 
}
