#include<stdio.h>
#include<math.h>
#define LL long long
#define LD long double
#define DB double
const DB pi=2*acos(0.0) ;

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T-- && ++tc)
    {
        printf("Case #%d: ",tc) ;
        DB x1,y1,r1,x2,y2,r2 ;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2) ;
        DB dis2=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) ;
        DB d=(DB)sqrt(dis2) ;
        if(d>=r1+r2) {printf("%.8lf\n",pi*r1*r1) ; continue ;}
        else if(d==0 && r1<=r2) {printf("0.00000000\n") ; continue ;}
        else if(d<r1-r2){printf("%.8lf\n",pi*r1*r1-pi*r2*r2) ; continue;}
        else if(d<r2-r1){printf("0.00000000\n") ; continue ;}
        DB cos1,cos2,ang1,ang2 ;
        DB area,s=(r1+r2+d)/2 ;
        cos1=((r1/d)+(d/r1)-((r2/r1/d)*r2))/2 ;
        cos2=((r2/d)+(d/r2)-((r1/r2/d)*r1))/2 ;
        area=sqrt(s)*sqrt(s-r1)*sqrt(s-r2)*sqrt(s-d) ;
        ang1=acos(cos1) ; ang2=acos(cos2) ;
        if(ang1<0) ang1+=pi ;
        if(ang2<0) ang2+=pi ;
        DB sub=r1*ang1/2*r1+r2*ang2/2*r2-area ;
        sub*=2 ;
        DB ans=r1*r1*pi-sub ;
        printf("%.8lf\n",ans) ;
    }
}
