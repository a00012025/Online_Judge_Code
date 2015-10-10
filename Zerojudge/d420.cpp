#include <stdio.h>
main() 
{
 int a,b,n=0,m,x ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 if ((a>0)&&(b>0))       
 {
 n+=1 ;
 x=a ;
 for ( m=1 ; x!=1 ; m++ )
  {
  if (x>b) 
  {
  m=m-1 ;
  break ;
  }      
  if ((x%2)==0) x=x/2 ;
  else x=3*x+1 ;
  }
 printf ("Case %d: A = %d, limit = %d, number of terms = %d\n",n,a,b,m) ; 
 }
}
}
