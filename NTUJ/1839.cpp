#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000+10 ;

struct pt
{
    int x,y ;
    bool operator < (const pt &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

pt operator + (const pt &a,const pt &b){return (pt){a.x+b.x,a.y+b.y} ;}
pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y} ;}
bool operator == (const pt &a,const pt &b){return a.x==b.x && a.y==b.y ;}
LL dot(const pt &a,const pt &b){return (LL)a.x*b.x+(LL)a.y*b.y ;}
LL cross(const pt &a,const pt &b){return (LL)a.x*b.y-(LL)a.y*b.x ;}
LL cross(const pt &a,const pt &b,const pt &c){return cross(b-a,c-a) ;}

typedef vector<pt> poly ;
LL Area(const poly &p)
{
    int sz=p.size() ;
    if(sz<=2) return 0 ;
    LL ret=0 ;
    for(int i=1;i<sz-1;i++) ret+=cross(p[0],p[i],p[i+1]) ;
    return ret ;
}

pt st[maxn] ;
poly convex_hull(poly &p)
{
    sort(p.begin(),p.end()) ;
    poly q ;
    int sz=0 ;
    for(int i=0;i<p.size();i++)
    {
        if(sz<2){st[sz++]=p[i] ; continue ;}
        while(sz>=2 && cross(p[i],st[sz-1],st[sz-2])>=0) sz-- ;
        st[sz++]=p[i] ;
    }
    for(int i=0;i<sz;i++) q.push_back(st[i]) ;
    sz=0 ;
    for(int i=0;i<p.size();i++)
    {
        if(sz<2){st[sz++]=p[i] ; continue ;}
        while(sz>=2 && cross(p[i],st[sz-1],st[sz-2])<=0) sz-- ;
        st[sz++]=p[i] ;
    }
    for(int i=sz-1;i>=0;i--)
    {
        if(i==sz-1 && st[i]==q.back()) continue ;
        if(!i && st[i]==q[0]) continue ;
        q.push_back(st[i]) ;
    }
    return q ;
}

poly p ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        p.clear() ;
        while(n--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            p.push_back((pt){x,y}) ;
            p=convex_hull(p) ;
            LL ans=Area(p) ;
            printf("%lld.%d\n",ans/2,ans%2?5:0) ;
        }
    }
}
