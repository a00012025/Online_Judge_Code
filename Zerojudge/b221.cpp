#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-5 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0;
    return x>0 ? 1 : -1 ;
}
struct pt
{
    DB x,y ;
    bool operator < (const pt &rhs) const
    {
        if(dcmp(x-rhs.x)) return x<rhs.x ;
        else return y<rhs.y ;
    }
    bool operator == (const pt &rhs) const
    {
        return dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0 ;
    }
};

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x , a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x , d*a.y} ; }
DB dot(const pt &a,const pt &b){ return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

void normalize(pt &p)
{
    DB len=length(p) ;
    p=p*(1/len) ;
}

pt get_inter(const pt &P,const pt &v,const pt &Q,const pt &w)
{
    pt u=P-Q ;
    DB t=cross(u,v)/cross(w,v) ;
    return Q + w*t ;
}

pt get_seg_inter(const pt &a,const pt &b,const pt &c,const pt &d)
{
    return get_inter(a,b-a,c,d-c) ;
}

bool on_seg(const pt &a,const pt &b,const pt &p)
{
    return dcmp(cross(a-p,b-p))==0 && dcmp(dot(a-p,b-p))<=0 ;
}

int type(const pt &p1,const pt &p2,const pt &p3)
{
    return dcmp(cross(p2-p1,p3-p1)) ;
}

void convex_hull(vector<pt> &poly)
{
    vector<pt> v ;
    int n=poly.size() ;
    for(int i=0;i<n;i++) v.push_back(poly[i]) ;
    sort(v.begin(),v.end()) ;
    poly.clear() ;
    pt st1[200],st2[200] ; int num1=0,num2=0 ;
    for(int i=0;i<n;i++)
    {
        while(num1>=2 && type(st1[num1-2],st1[num1-1],v[i])<=0) num1-- ;
        st1[num1++]=v[i] ;
    }
    for(int i=0;i<n;i++)
    {
        while(num2>=2 && type(st2[num2-2],st2[num2-1],v[i])>=0) num2-- ;
        st2[num2++]=v[i] ;
    }
    for(int i=0;i<num1;i++) poly.push_back(st1[i]) ;
    for(int i=num2-1;i>=0;i--)
    {
        if(st2[i]==st1[num1-1] || st2[i]==st1[0]) continue ;
        poly.push_back(st2[i]) ;
    }
}

DB area(const vector<pt> &poly)
{
    int n=poly.size() ;
    DB ret=0.0 ;
    for(int i=0;i<n;i++) ret+=cross(poly[i],poly[(i+1)%n]) ;
    return ret/2 ;
}

vector<pt> poly ;
main()
{
    int n ; scanf("%d",&n) ;
    pt l=(pt){0,1} , r=(pt){0,-1} ;
    for(int i=1;i<=n;i++)
    {
        DB x,y ; scanf("%lf%lf",&x,&y) ;
        poly.push_back((pt){x,y}) ;
        if(x*r.y < y*r.x) r=(pt){x,y} , normalize(r) ;
        if(x*l.y > y*l.x) l=(pt){x,y} , normalize(l) ;
    }
    convex_hull(poly) ;
        for(int i=0;i<n;i++) debugf("(%.2f,%.2f)%c",poly[i].x,poly[i].y,i==n-1?'\n':',') ;
    vector<pt> tmp1,tmp2 ;
    while(length(r-l)>1e-7)
    {
        pt mid=(r+l)*0.5 ; normalize(mid) ;
        int id1,id2 ;
        pt newp1,newp2 ;
        for(id1=0;;id1=(id1+1)%n)
        {
            newp1=get_seg_inter((pt){0,0},mid,poly[id1],poly[(id1+1)%n]) ;
            if(on_seg(poly[id1],poly[(id1+1)%n],newp1)) break ;
        }
        for(id2=(id1+1)%n;;id2=(id2+1)%n)
        {
            newp2=get_seg_inter((pt){0,0},mid,poly[id2],poly[(id2+1)%n]) ;
            if(on_seg(poly[id2],poly[(id2+1)%n],newp2)) break ;
        }
        tmp1.clear() ; tmp2.clear() ;
        tmp1.push_back(newp1) ; tmp1.push_back(newp2) ;
        for(int i=(id2+1)%n ; i!=((id1+1)%n) ; i=(i+1)%n) tmp1.push_back(poly[i]) ;
        tmp2.push_back(newp2) ; tmp2.push_back(newp1) ;
        for(int i=(id1+1)%n ; i!=((id2+1)%n) ; i=(i+1)%n) tmp2.push_back(poly[i]) ;
        if(dcmp(cross(mid,poly[(id2+1)%n]))>=0) swap(tmp1,tmp2) ;
        if(area(tmp1) < area(tmp2)) l=mid ;
        else r=mid ;
    }
    printf("%.4f\n",r.y/r.x) ;
}
