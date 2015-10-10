#include<bits/stdc++.h>
#define DB long double
using namespace std;
const DB eps=1e-22 ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y ;};

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }

bool chk(DB x,DB y,int a,int b,DB s)
{
    pt p=(pt){x,y} ;
    pt p1=(pt){a+s,b-s} , p2=(pt){a+s,b+s} ;
    if(dcmp(cross(p1,p))>=0 && dcmp(cross(p,p2))>=0)
        return 1 ;
    p1=(pt){a+s,b+s} , p2=(pt){a-s,b+s} ;
    if(dcmp(cross(p1,p))>=0 && dcmp(cross(p,p2))>=0)
        return 1 ;
    p1=(pt){a-s,b+s} , p2=(pt){a-s,b-s} ;
    if(dcmp(cross(p1,p))>=0 && dcmp(cross(p,p2))>=0)
        return 1 ;
    p1=(pt){a-s,b-s} , p2=(pt){a+s,b-s} ;
    if(dcmp(cross(p1,p))>=0 && dcmp(cross(p,p2))>=0)
        return 1 ;
    return 0 ;
}

int a,b,c,d ;
bool check(DB val)
{
    if(val<0) return 0 ;
    DB x1=a-val , x2=a+val , y1=b-val , y2=b+val ;
    if(chk(x1,y1,c,d,val) || chk(x1,y2,c,d,val)
       || chk(x2,y1,c,d,val) || chk(x2,y2,c,d,val)) return 1 ;
    x1=c-val , x2=c+val , y1=d-val , y2=d+val ;
    if(chk(x1,y1,a,b,val) || chk(x1,y2,a,b,val)
       || chk(x2,y1,a,b,val) || chk(x2,y2,a,b,val)) return 1 ;
    return 0 ;
}

main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d) ;
    DB l=-1.0 , r=1e9 ;
    for(int i=1;i<=1000;i++)
    {
        DB mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    double ans=r ;
    printf("%.15f\n",ans) ;
}
