#include<stdio.h>
#include<math.h>
main()
{
    int a,b,c,r ;
    double area1,area2,ta,tb,tc,s,R ;
    scanf("%d%d%d%d",&a,&b,&c,&r) ;
    s=(double)(a+b+c)/2 ;
    area1=sqrt(s*(s-a)*(s-b)*(s-c)) ;
    R=area1/s ;
    double cota=(s-a)/R,cotb=(s-b)/R,cotc=(s-c)/R ;
    area2=area1+((double)acos(0.0)*r*r*2) ;
    area2-=r*r*(cota+cotb+cotc);
    printf("%.15lf\n",area2/area1) ;
}
