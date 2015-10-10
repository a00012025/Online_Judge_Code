#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-6 ;
const int maxn=1000+10 ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt
{
    DB x,y ;
    pt(const DB &xx,const DB &yy){ x=xx , y=yy ; }
    pt(){} ;
    bool operator < (const pt &rhs) const
    {
        if(!dcmp(x-rhs.x)) return y<rhs.y ;
        return x<rhs.x ;
    }
};

pt operator + (const pt &a,const pt &b) { return pt(a.x+b.x,a.y+b.y) ; }
pt operator - (const pt &a,const pt &b) { return pt(a.x-b.x,a.y-b.y) ; }
pt operator * (const pt &a,const DB &d) { return pt(d*a.x,d*a.y) ; }
bool operator == (const pt &a,const pt &b) { return !dcmp(a.x-b.x) && !dcmp(a.y-b.y) ; }
bool operator != (const pt &a,const pt &b) { return !(a==b) ; }

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
DB dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }
DB length(const pt &a) { return sqrt(dot(a,a)) ; }

typedef vector<pt> poly ;

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

DB Area(const poly &p)
{
    DB ret=0.0 ;
    int sz=p.size() ;
    for(int i=1;i<sz-1;i++) ret+=cross(p[0],p[i],p[i+1])/2.0 ;
    return fabs(ret) ;
}

poly p,q ;
main()
{
    int n ; DB k ; scanf("%d%lf",&n,&k) ;
    for(int i=1;i<=n;i++)
    {
        DB x,y ; scanf("%lf%lf",&x,&y) ;
        p.push_back(pt(x,y)) ;
    }
    DB ans=-Area(p) ;
    convex_hull(p,q) ;
    ans+=Area(q) ;
    printf("%d\n", int(ceil((ans+eps)/k-eps)+eps) ) ;
}
