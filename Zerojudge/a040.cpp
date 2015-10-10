#include <stdio.h>
#include <math.h>
main()
{
 int a,b,i,j,k,x,y,z,m,n,A=1 ;

 while (scanf ("%d %d",&a,&b)==2)
 {
  for (x=a ; x<=b ; x++)
  {
   m=0 ;     
   for (i=1 ; i<=x ; i*=10) m=m+1 ;   
   for (k=1,y=0 ; k<pow(10,m) ; k*=10) 
   {
     z=(x/k)-10*(x/(10*k))  ; 
     for (j=0,n=1 ; j<m ; j++) n*=z ;
     y+=n ;
   }
   if (x==y) {
             printf ("%d ",x) ;
             A*=0 ;
             }
   else A*=1 ;          
  }
  if (A==1) printf ("none\n") ;
  else printf ("\n") ;
  A=1 ;
 }
}
