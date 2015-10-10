#include <stdio.h>
main ()
{
 int a,b,n,m,i,x,y=1  ;
 int s[50] ;
 while (scanf ("%d",&n)==1)
{
 if (n==0) break ;       
 x=0 ;
 m=0 ;		
 for (i=0 ; i<n ; i++)
 {
 scanf ("%d",&s[i]) ;
 }
 for (i=0 ; i<n ; i++)
 {
 m+=s[i] ;
 }
 m=m/n ;
 for (i=0 ; i<n ; i++)
 {
 if (s[i]>=m) x=x+s[i]-m ;
 else x=x-s[i]+m ;
 }
 printf ("Set #%d\nThe minimum number of moves is %d.\n",y,x/2) ;
 y+=1 ;5
}
scanf (" ") ;
}
