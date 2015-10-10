#include <stdio.h>
main()
{
 int a,b,c,d,e,f,n ;
 scanf ("%d",&n) ;
 while (scanf ("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6)
 {
 if ((c==e)&&(d==f)) printf ("該死的東西!竟敢想讓我死！\n") ;
 else if ((a==e)&&(b==f)) printf ("該死的東西!竟敢想讓我死！\n") ;
 else if ((a==c)&&(c==e)&&(b*f+f*d-f*f-b*d>0)) printf ("該死的東西!竟敢想讓我死！\n") ;
 else if ((b==d)&&(d==e)&&(a*e+e*c-e*e-a*c>0)) printf ("該死的東西!竟敢想讓我死！\n") ;
 else if ((a*d+e*f-e*d-a*f==b*c+e*f-c*f-b*e)&&(a*e+e*c-e*e-a*c>0)) printf ("該死的東西!竟敢想讓我死！\n") ;
 else printf ("父親大人!母親大人!我快到了！\n") ;
 }
}
