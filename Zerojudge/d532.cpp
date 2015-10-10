#include <stdio.h>
main() 
{
 int a,b,c,d,m,n,i,x ;
 while (scanf ("%d %d",&m,&n)==2)
 {
 x=0 ;
 for (a=m ; a<=n ; a++ ) 
   {  
 b=a % 4 ;
 c=a % 100 ;
 d=a % 400 ;
 if (a==0) break ;
 if (d==0) x+=1 ;
 else if ((b==0)&&(c!=0)) x+=1 ;
 else x+=0 ;
   }
 printf ("%d\n",x) ;
}
}
