#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct pt
{
    int x,y ;
    pt(int _x=0,int _y=0){x=_x ; y=_y ;}
    bool operator < (const pt &rhs) const
    {
        if(x==rhs.x) return y<rhs.y ;
        return x<rhs.x ;
    }
};
typedef vector<pt> poly ;

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
bool operator == (const pt &a,const pt &b) { return !(a.x-b.x) && !(a.y-b.y) ; }
bool operator != (const pt &a,const pt &b) { return !(a==b) ; }

int dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
int cross(const pt &a,const pt &b) { return a.x*b.y - a.y*b.x ; }
int cross(const pt &a,const pt &b,const pt &c) { return cross(b-a,c-a) ; }
int dis2(const pt &a,const pt &b) { return dot(a-b,a-b) ; }
int dis2(const pt &a) { return dis2(pt(0,0),a) ; }

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

poly p,q ;
int len2[50] ;
pt ans[8],now[8],pts ;
int n,ansval,sqs ;

void dfs(int x,int las)
{
    if(las==0)
    {
        int val=n*sqs-dis2(pts) ;
        if(val>ansval)
        {
            ansval=val ;
            for(int i=0;i<n;i++) ans[i]=now[i] ;
        }
        return ;
    }
    for(int i=x;i<q.size();i++)
    {
        pts=pts+q[i] ;
        sqs+=len2[i] ;
        now[las-1]=q[i] ; dfs(i,las-1) ;
        pts=pts-q[i] ;
        sqs-=len2[i] ;
    }
}

main()
{
    int r ; scanf("%d%d",&n,&r) ;
    for(int i=-r;i<=r;i++) for(int j=-r;j<=r;j++)
        if(i*i+j*j<=r*r) p.push_back(pt(i,j)) ;
    convex_hull(p,q) ;
    for(int i=0;i<q.size();i++) len2[i]=dis2(q[i]) ;
    dfs(0,n) ;
    printf("%d\n",ansval) ;
    for(int i=0;i<n;i++) printf("%d %d\n",ans[i].x,ans[i].y) ;
}
