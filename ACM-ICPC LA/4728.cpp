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
bool operator == (const pt &a,const pt &b) { return !dcmp(a.x-b.x) && !dcmp(a.y-b.y) ; }

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
DB dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }


typedef vector<pt> poly ;

pt st[maxn] ;
void convex_hull(poly &v,poly &p)
{
    p.clear() ;
    sort(v.begin(),v.end()) ;
    v.erase(unique(v.begin(),v.end()),v.end()) ;
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

poly pts ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        pts.clear() ;
        for(int i=0;i<n;i++)
        {
            int x,y,w ; scanf("%d%d%d",&x,&y,&w) ;
            pts.push_back(pt(x,y)) ;
            pts.push_back(pt(x,y+w)) ;
            pts.push_back(pt(x+w,y)) ;
            pts.push_back(pt(x+w,y+w)) ;
        }
        printf("%d\n",(int)(diameter2(pts)+0.5)) ;
    }
}
