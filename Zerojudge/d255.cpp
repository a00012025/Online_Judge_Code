#include <stdio.h>
#include <math.h>
main () 
{
 int a,b,i,j,k,n ;
 double c ;
 while (scanf ("%d",&a)==1)
 {
 b=0 ;
 if (a==0) break ;
 else
 {
  c=a/2 ;      
  for (i=1 ; i<a ; i++)
  {
    for (j=i+1 ; j<=a ; j++)
    {
     n=1 ;   
     if ((j!=2)&&(j!=3)&&(i!=2)&&(i!=3))
     {
          for (k=2 ; k<=c ; k++) 
          {
           if ((i%k==0)&&(j%k==0)) n=k ;
          } 
     }
     else if (j%i==0) n=i ;
     else n=1 ; 
     b=b+n ;
    }
  }
 printf ("%d\n",b) ;
 b=0 ; 
 }
 }
 scanf (" ") ;
}

