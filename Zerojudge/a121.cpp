#include <stdio.h>
#include <math.h>
main ()
{
 int a,b,i,x,n,m ;
 double c ;
 while (scanf ("%d %d",&a,&b)==2)
 {
 n=0 ;      
   for (x=a ; x<=b ; x++)     
   {
    m=1 ;    
    c=sqrt(x) ;
    if (x==2) m=1 ;
    else if (x%2==0) m=0 ;
    else if (x==3) m=1 ;
    else if (x%3==0) m=0 ;
    else if (x==5) m=1 ;
    else if (x%5==0) m=0 ;
    else if (x==1) m=0 ;
    else
    {
      for (i=2 ; i<=c ; i++)
      {
        if ((x%i)==0)
        {
        m*=0 ;
        }
        else  m*=1 ;
      } 
    }
    if (m==1) n=n+1 ;
    else n=n ;
   }
 printf ("%d\n",n) ;
}   
}
