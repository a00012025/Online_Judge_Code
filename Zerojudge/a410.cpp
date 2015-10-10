#include <stdio.h>
main () 
{
   int a,b,c,d,e,f ;
   float x,y,z,u,v,w ;
   while (scanf ("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6)
   {
    x=c*e-b*f ;
    y=a*f-c*d ;
    z=a*e-b*d ;

    if ((z==0) && (x!=0))
       {
       printf ("No answer") ;
       }
    else if ((z==0) && (x==0))
       {
       printf ("Too many") ;
       }
    else
    {
    printf ("x=%.2f\n",x/z) ;
    printf ("y=%.2f\n",y/z) ;    
   }
  }
}
