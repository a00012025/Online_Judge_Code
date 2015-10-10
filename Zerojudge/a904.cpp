#include<stdio.h>
#include<algorithm>
#include<math.h>
#define DB double
using namespace std;
struct pt{double x,y;}p[401],st[501],v[501];

const DB eps=1e-6 , INF=1000000000.0 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x,a.y+b.y} ;}
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x,a.y-b.y} ;}
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x,d*a.y} ;}
bool operator == (const pt &a,const pt &b) {return a.x==b.x && a.y==b.y ;}
DB dot(pt a,pt b) {return a.x*b.x+a.y*b.y ;}
DB cross(pt a,pt b) {return a.x*b.y-a.y*b.x ;}
DB length(pt a) {return sqrt(dot(a,a)) ;}

int on_segment(pt a,pt b,pt c)
{
    return dcmp(cross(a-b,a-c))==0 && dcmp(dot(a-b,a-c))<0 ;
}

int n,m ;
DB cal(int x)
{
    pt now=st[x] ;
    DB ret=INF ;
    for(int i=0;i<n;i++)
    {
        pt p1=p[i] , p2=p[(i+1)%n] ;
        if(now==p1)
        {
            pt p0=p[(i+n-1)%n] ;
            if(dcmp(cross(p0-p1,v[x]))==0 && dcmp(dot(p0-p1,v[x]))<0)
                return 0.0 ;
            else if(dcmp(cross(p0-p1,v[x]))==0)
                ret=min(ret,length(p0-p1)) ;

            else if(dcmp(cross(p2-p1,v[x]))==0 && dcmp(dot(p2-p1,v[x]))<0)
                return 0.0 ;
            else if(dcmp(cross(p2-p1,v[x]))==0)
                ret=min(ret,length(p2-p1)) ;

            else if(dcmp(cross(p0-p1,p2-p1))==dcmp(cross(p0-p1,v[x]))
                    && dcmp(cross(p0-p1,p2-p1))==dcmp(cross(v[x],p2-p1)))
                        continue ;
            else return 0.0 ;
        }
        else if(now==p2) continue ;
        else if(on_segment(now,p1,p2))
        {
            if(dcmp(dot(p1-now,v[x]))>0) ret=min(ret,length(p1-now)) ;
            else ret=min(ret,length(p2-now)) ;
        }
        else
        {
            pt N=(pt){(p1-p2).y,(p2-p1).x} ;
            if(dcmp(dot(N,p1-now))<0) N=(pt){(p2-p1).y,(p1-p2).x} ;
            if(dcmp(dot(N,v[x]))<=0) continue ;
            DB len=dot(p1-p2,now-p2)/length(p1-p2) ;
            pt foot=p2+(p1-p2)*(len/length(p1-p2)) ;
            DB cos_val=dot(v[x],N)/(length(v[x])*length(N)) ;
            ret=min(ret,length(foot-now)/cos_val) ;
        }
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y) ;
        for(int i=0;i<m;i++) scanf("%lf%lf%lf%lf",&st[i].x,&st[i].y,&v[i].x,&v[i].y) ;
        DB ans=0.0 ;
        for(int i=0;i<m;i++)
            ans=max(ans,cal(i)) ;
        printf("%.4lf\n",ans) ;
    }
}
