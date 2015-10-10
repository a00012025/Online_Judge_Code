#include<stdio.h>
const double eps = 1e-6;
main()
{
    int T,cnt=0;
    scanf("%d",&T) ;
    while(++cnt && cnt<=T)
    {
        int a,b,c,d,e,f,g,h,price ;
        scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&price);
        int Area2 = a*d+c*f+e*h+g*b-c*b-e*d-g*f-a*h ;
        if(Area2<0) Area2=-Area2 ;
        printf("Case #%d: %.2lf\n",cnt,(double)2*price/Area2) ;
    }
}
