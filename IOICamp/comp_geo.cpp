#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-7 ;
const int maxn=100000+10 ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt
{
    DB x,y ;
    pt(DB _x=0,DB _y=0){x=_x ; y=_y ;}
    bool operator < (const pt &rhs) const
    {
        if(!dcmp(x-rhs.x)) return y<rhs.y ;
        return x<rhs.x ;
    }
};

struct line
{
    pt p,v ;
    DB ang ;
    line(const pt &pp,const pt &vv)
    {
        p=pp ; v=vv ;
        ang=atan2(v.y,v.x) ;
    }
    bool operator < (const line &rhs) const
    {
        return ang<rhs.ang ;
    }
};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) { return (pt){d*a.x,d*a.y} ; }
bool operator == (const pt &a,const pt &b) { return !dcmp(a.x-b.x) && !dcmp(a.y-b.y) ; }
bool operator != (const pt &a,const pt &b) { return !(a==b) ; }

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
DB dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

bool seg_proper_inter(const pt &a,const pt &b,const pt &c,const pt &d)
{   /// ab , cd
    DB c1=cross(b-a,c-a) , c2=cross(b-a,d-a) ;
    DB c3=cross(d-c,a-c) , c4=cross(d-c,b-c) ;
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0 ;
}

bool on_seg(const pt &p,const pt &a,const pt &b)
{
    return !dcmp(cross(a-p,b-p)) && dcmp(dot(a-p,b-p))<=0 ;
}

pt line_inter(const pt &P,const pt &u,const pt &Q,const pt &v)
{
    DB t= cross(P-Q,u)/cross(v,u) ;
    return Q + v * t ;
}

typedef vector<pt> poly ;

int pt_in_poly(const pt &p,const poly &v)
{
    int n=v.size() ;
    int wn=0 ;
    for(int i=0;i<n;i++)
    {
        if(on_seg(p,v[i],v[(i+1)%n])) return -1 ;
        int k=dcmp(cross(v[(i+1)%n]-v[i],p-v[i])) ;
        int d1=dcmp(v[i].y - p.y) ;
        int d2=dcmp(v[(i+1)%n].y - p.y) ;
        if(d1<=0 && d2>0 && k>0) wn++ ;
        if(d2<=0 && d1>0 && k<0) wn-- ;
    }
    if(wn==0) return 0 ;
    else return 1 ;
}

pt st[maxn] ;
void convex_hull(poly &v,poly &p)
{
    p.clear() ;
    sort(v.begin(),v.end()) ;
    int n=v.size() ;
    int sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && dcmp(cross(st[sz-2],st[sz-1],v[i]))<=0)
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=0;i<sz;i++) p.push_back(st[i]) ;

    sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && dcmp(cross(st[sz-2],st[sz-1],v[i])>=0))
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=sz-1;i>=0;i--)
    {
        if(i==sz-1 && st[i]==p.back()) continue ;
        if(i==0 && st[i]==p[0]) continue ;
        p.push_back(st[i]) ;
    }
}

poly poly_tmp ;
DB diameter2(poly &w)
{
    convex_hull(w,poly_tmp) ;
    poly &v=poly_tmp ;
    int n=v.size() ;

    if(n==1) return 0.0 ;
    if(n==2) return dis2(v[0],v[1]) ;

    DB ans=0.0 ;
    for(int i=0,j=1 ;i<n;i++)
    {
        while(1)
        {
            DB diff= cross(v[(i+1)%n]-v[i],v[(j+1)%n]-v[j]) ;
            if(dcmp(diff)<=0)
            {
                ans=max(ans,dis2(v[i],v[j])) ;
                if(!dcmp(diff)) ans=max(ans,dis2(v[i],v[(j+1)%n])) ;
                break ;
            }
            j=(j+1)%n ;
        }
    }
    return ans ;
}
