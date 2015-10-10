#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct pt
{
    LL x,y ; int id ;
    bool operator < (const pt &rhs) const
    {
        if(x==rhs.x) return y<rhs.y ;
        return x<rhs.x ;
    }
};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y,0} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y,0} ; }
bool operator == (const pt &a,const pt &b)
{ return a.x==b.x && a.y==b.y && a.id==b.id ; }

LL cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
LL cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }

pt st[maxn] ;
typedef vector<pt> poly ;
void convex_hull(poly &v,poly &p)
{
    p.clear() ;
    sort(v.begin(),v.end()) ;
    int n=v.size() ;
    int sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && cross(st[sz-2],st[sz-1],v[i])<=0LL)
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=0;i<sz;i++) p.push_back(st[i]) ;

    sz=0 ;
    for(int i=0;i<n;i++)
    {
        while(sz>=2 && cross(st[sz-2],st[sz-1],v[i])>=0LL)
            sz-- ;
        st[sz++]=v[i] ;
    }
    for(int i=sz-1;i>=0;i--) p.push_back(st[i]) ;
}

poly p,q ;
vector<int> ans ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        p.clear() ;
        for(int i=1;i<=n;i++)
        {
            LL x,y ; scanf("%lld%lld",&x,&y) ;
            p.push_back((pt){x,y,i}) ;
        }
        convex_hull(p,q) ;
        ans.clear() ;
        for(auto i : q) ans.push_back(i.id) ;
        sort(ans.begin(),ans.end()) ;
        ans.resize(unique(ans.begin(),ans.end())-ans.begin()) ;
        printf("%d\n",(int)ans.size()) ;
        for(auto i : ans) printf("%d\n",i) ;
    }
}
