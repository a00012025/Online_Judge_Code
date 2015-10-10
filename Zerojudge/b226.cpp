#include <stdio.h>
main ()
{
 int a,b,c,d ;
 while (scanf ("%d %d %d %d",&a,&b,&c,&d)==4)
 {
 if ((a==0)&&(b==0)&&(c==0)&&(d==0)) ;
 else if (((a%c)==0)&&((b%d)==0)) printf ("%d\n",a*b/c/d) ;
 else if (((a%d)==0)&&((b%c)==0)) printf ("%d\n",a*b/c/d) ;
 else printf ("-1\n") ;
 }

}
