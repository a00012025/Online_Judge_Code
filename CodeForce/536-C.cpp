#include<bits/stdc++.h>
#define DB long double
#define pii pair<int,int>
using namespace std;
const DB eps=1e-7,mul=1e5 ;
const int maxn=200000+10 ;

int dcmp(DB x)
{
    if(fabsl(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt
{
    DB x,y ;
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

DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
DB cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }

typedef vector<pt> poly ;
pt st[maxn] ;
void convex_hull(poly &v,poly &p)
{
    p.clear() ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    int n=v.size() ;
    int sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && dcmp(cross(st[sz-2],st[sz-1],v[i]))<0)
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=0;i<sz;i++) p.push_back(st[i]) ;

    sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && dcmp(cross(st[sz-2],st[sz-1],v[i])>0))
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

poly a,b ;
set<pii> ans ;
int x[maxn],y[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]) ;
        a.push_back((pt){mul/x[i],mul/y[i]}) ;
    }
    convex_hull(a,b) ;
    for(int i=0;i<b.size();i++)
    {
        if(i && dcmp(b[i-1].y-b[i].y)<=0) break ;
        int x0=int(mul/b[i].x+0.5) , y0=int(mul/b[i].y+0.5) ;
        ans.insert((pii){x0,y0}) ;
    }
    for(int i=1;i<=n;i++) if(ans.count((pii){x[i],y[i]}))
        printf("%d ",i) ;
    printf("\n") ;
}
