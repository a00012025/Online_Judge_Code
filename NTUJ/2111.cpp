#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-7 ;
const int maxn=1000+10 ;

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
DB area(const pt &a,const pt &b,const pt &c){return cross(a,b,c)/2 ;}

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

inline pt cent(const pt &a,const pt &b,const pt &c)
{
    return (a+b+c)*(1.0/3) ;
}

int solve()
{
    int n ; scanf("%d",&n) ;
    poly p ;
    for(int i=0;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        p.push_back((pt){x,y}) ;
    }
    pt cen(0,0) , ori(0,0) ;
    DB tot=0 ;
    for(int i=0;i<n;i++)
    {
        pt a=p[i] , b=p[(i+1)%n] ;
        DB A=area(ori,a,b) ;
        cen= cen + cent(ori,a,b) * A ;
        tot+=A ;
    }
    cen=cen*(1/tot) ;
    poly q ;
    convex_hull(p,q) ;
    int ret=0 , sz=q.size() ;
    for(int i=0;i<sz;i++)
    {
        pt a=q[i] , b=q[(i+1)%sz] ;
        if(dcmp(dot(b-a,cen-a))>0 && dcmp(dot(a-b,cen-b))>0) ret++ ;
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) printf("%d\n",solve()) ;
}
