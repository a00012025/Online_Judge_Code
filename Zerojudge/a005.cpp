#include <stdio.h>
main()
{
 int a,b,c,d,n ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d %d %d",&a,&b,&c,&d)==4)
 {
 if ((a-b==b-c)&&(b-c==c-d)) printf ("%d %d %d %d %d\n",a,b,c,d,d+d-c) ;
 else printf ("%d %d %d %d %d\n",a,b,c,d,d*d/c) ;
 }    

}
