#include <stdio.h>
main () 
{
 int x,y,z,n ;
 scanf ("%d",&n) ;
 n=1 ;
 while (scanf ("%d %d",&x,&y)==2)
 {
 if ((x%2==1)&&(y%2==1)) 
   {
   z=(y*y-x*x+2*x+2*y)/4 ;
   printf ("Case %d: %d\n",n,z) ;
   }
  if ((x%2==1)&&(y%2==0)) 
   {
   z=(y*y-x*x+2*x-1)/4  ;
   printf ("Case %d: %d\n",n,z) ;
   }
  if ((x%2==0)&&(y%2==1)) 
   {
   z=(y*y-x*x+2*y+1)/4  ;
   printf ("Case %d: %d\n",n,z) ;
   }
  if ((x%2==0)&&(y%2==0)) 
   {
   z=(y*y-x*x)/4  ;
   printf ("Case %d: %d\n",n,z) ;
   } 
  n=n+1 ;
 }

}
