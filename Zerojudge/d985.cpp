#include <stdio.h>
main()
{
 int a,b,p,q,m=60,n=59,x ;
 int i,j,k ;
 int s[10],t[10],u[10] ;
 while (scanf ("%d",&p)==1)
 {
  k=0 ;      
  for (i=p ; i>0 ; i--)
  {
  x=0 ;      
  scanf ("%d",&q) ;
   for (j=q ; j>0 ; j--)
   {
   scanf ("%d %d",&a,&b) ;
   x=x+60*a+b ;
   if ((a<m)||((a==m)&&(b<n)))
     {
     m=a ;
     n=b ;
     }
   } 
   s[k]=x/q ;
   t[k]=m ;
   u[k]=n ;
   k++ ;
   m=60 ;
   n=59 ;
   x=0 ;
  }
 for (i=1 ; i<=p ; i++)
 {
 printf ("Track %d:\nBest Lap: %d minute(s) %d second(s).\nAverage: %d minute(s) %d second(s).\n\n",i,t[i-1],u[i-1],s[i-1]/60,s[i-1]%60) ;
 } 
 }
     
 
}
