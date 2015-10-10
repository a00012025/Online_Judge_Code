#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct pt
{
    int x,y ;
    bool operator < (const pt &rhs) const
    {
        if(x==rhs.x) return y<rhs.y ;
        return x<rhs.x ;
    }
};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
bool operator == (const pt &a,const pt &b) { return !(a.x-b.x) && !(a.y-b.y) ; }
bool operator != (const pt &a,const pt &b) { return !(a==b) ; }

int dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
int cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
int cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
int dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }
int length(const pt &a) { return sqrt(dot(a,a)) ; }

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
        while(sz>=2 && cross(st[sz-2],st[sz-1],v[i])<=0)
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=0;i<sz;i++) p.push_back(st[i]) ;

    sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && cross(st[sz-2],st[sz-1],v[i])>=0)
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

int Area2(const poly &p)
{
    if(p.size()<3) return 0 ;
    int ret=0 ;
    for(int i=1;i+1<p.size();i++) ret+=cross(p[i]-p[0],p[i+1]-p[0]) ;
    return ret ;
}

poly p,q ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        p.clear() ;
        int n ; scanf("%d",&n) ;
        while(n--){int x,y ; scanf("%d%d",&x,&y);p.push_back((pt){x,y}) ;}
        convex_hull(p,q) ;
        int ans=Area2(q) ;
        printf("%d.%d\n",ans/2,ans%2?5:0) ;
    }
}
