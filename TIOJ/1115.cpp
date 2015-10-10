#include<bits/stdc++.h>
#define DB long double
using namespace std;
const DB eps=1e-5 , PI=acos((DB)-1.0) ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}
main()
{
    DB x,y,r ;
    double _x,_y,_r ;
    while(scanf("%lf%lf%lf",&_x,&_y,&_r)!=EOF)
    {
        x=_x ; y=_y ; r=_r ;
        DB area=PI*r*r ;
        if(y>=0 && dcmp(y-r)<0)
        {
            DB ang=2*acos(y/r) ;
            area-=area * (ang/(2*PI)) ;
            area+=r*r*sin(ang)/2 ;
        }
        else if(y<=0 && dcmp(y+r)>0)
        {
            DB ang=2*acos((-y)/r) ;
            area=area * (ang/(2*PI)) ;
            area-=r*r*sin(ang)/2 ;
        }
        else if(y<=0) area=0.0 ;
        double ans=area ;
        printf("%.2f\n",ans) ;
    }
}
