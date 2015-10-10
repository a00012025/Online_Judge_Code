#include<stdio.h>
main()
{
    double a,b,c,d ;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)==4)
    {
        double ans1=(d-c)/(a-b) ;
        double ans2=a*ans1+c ;
        if(ans1<0){ans1=-ans1 ; printf("-") ;}
        int x=(int)(100*ans1) ;
        if(x%100==0)printf("%d\n",x/100);
        else if(x%10==0)printf("%d.%d\n",x/100,x/10-(x/100)*10);
        else printf("%d.%d%d\n",x/100,x/10-(x/100)*10,x%10) ;
        if(ans2<0){ans2=-ans2 ; printf("-") ;}
        x=(int)(100*ans2) ;
        if(x%100==0)printf("%d\n",x/100);
        else if(x%10==0)printf("%d.%d\n",x/100,x/10-(x/100)*10);
        else printf("%d.%d%d\n",x/100,x/10-(x/100)*10,x%10) ;
    }
}
