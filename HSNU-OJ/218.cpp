#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-10,PI=2*acos(0) ;
int dcmp(const DB &x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y;};
pt operator + (const pt &a,const pt &b){return (pt){a.x+b.x,a.y+b.y};}
pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y};}
pt operator * (const pt &a,const DB &d){return (pt){d*a.x,d*a.y};}
DB cross(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}
DB dot(const pt &a,const pt &b){return a.x*b.x+a.y*b.y;}
DB length(const pt &a){return sqrt(dot(a,a)) ;}

pt foot(const pt &p,const pt &a,const pt &b)
{
    return a+(b-a)*(dot(p-a,b-a)/dot(a-b,a-b)) ;
}

DB W,H,r ;
pt p ;
vector<DB> v ;
void inter(const pt &p1,const pt &p2)
{
    pt f=foot(p,p1,p2) ;
    DB dis=length(p-f) ;
    if(dcmp(dis-r)>0) return ;
    pt p3=f-p ;
    DB ang=atan2(p3.y,p3.x) , dif=acos(dis/r) ;
    v.push_back(ang+dif) ;
    v.push_back(ang-dif) ;
}

main()
{
    scanf("%lf%lf%lf%lf%lf",&W,&H,&p.x,&p.y,&r) ;
    v.push_back(PI/2) ; v.push_back(-PI/2) ;
    inter((pt){0,0},(pt){W,0}) ;
    inter((pt){W,0},(pt){W,H}) ;
    inter((pt){W,H},(pt){0,H}) ;
    inter((pt){0,H},(pt){0,0}) ;
    for(auto &i:v)
        if(i>PI) i-=2*PI ;
        else if(i+PI<0) i+=2*PI ;
    sort(v.begin(),v.end()) ;
    v.push_back(v[0]+2*PI) ;
    DB ans=0 ;
    for(int i=0;i+1<v.size();i++) if(dcmp(v[i+1]-v[i]))
    {
        DB ang=(v[i]+v[i+1])/2,add=r*(v[i+1]-v[i]) ;
        pt np=(pt){p.x+r*cos(ang),p.y+r*sin(ang)} ;
        if(np.x>=0 && np.x<=W && np.y>=0 && np.y<=H)
            ans+=add ;
    }
    printf("%.10f\n",ans) ;
}
