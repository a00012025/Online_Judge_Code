#include<bits/stdc++.h>
#include"lib1622.h"
#define DB double
using namespace std;
const int maxn=1000+10 ;
const DB eps=1e-5,PI=2*acos(0.0) ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y;};
pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x+a.y*b.y ; } ;
DB cross(const pt &a,const pt &b) { return a.x*b.y-a.y*b.x ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

DB pt_to_seg(const pt &p,const pt &a,const pt &b)
{
    return cross(p-a,b-a)/length(a-b) ;
}

int n ;
pt p[maxn] ;

DB cal(const pt &a)
{
    DB ang=0.0 , mi=1e7 ;
    for(int i=0;i<n;i++)
        mi=min(mi,pt_to_seg(a,p[i],p[(i+1)%n])) ;
    return mi ;
}

int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1} ;

main()
{
    Initialize() ;
    scanf("%d",&n) ;
    DB x=0.0 , y=0.0 ;
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y) , x+=p[i].x , y+=p[i].y ;
    x/=n ; y/=n ;
    DB val=cal((pt){x,y}) ;
    for(DB len=10.0;len>eps;len*=0.5)
    {
        while(1)
        {
            bool found=0 ;
            for(int i=0;i<8;i++)
            {
                DB nx=x+len*dx[i] , ny=y+len*dy[i] ;
                DB newv=cal((pt){nx,ny}) ;
                if(newv>val) val=newv , x=nx , y=ny , found=1 ;
            }
            if(!found) break ;
        }
    }
    Report(cal((pt){x,y})) ;
}
