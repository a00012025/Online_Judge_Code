#include <stdio.h>
main() 
{
 int a,x=0,y=0,z=0,n ;
 while (scanf ("%d",&n)==1)
{
  for (n=n ; n>0 ; n--)
  {
  scanf ("%d",&a) ;
  if (a%3==0) x+=1 ;
  else if (a%3==1) y+=1 ;
  else if (a%3==2) z+=1 ;
  }
 printf ("%d %d %d\n",x,y,z) ;
 x=0 ;
 y=0 ;
 z=0 ;
}
}
