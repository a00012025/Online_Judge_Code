#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=50000+10 ;
const DB eps=1e-7,PI=2*acos(0.0) ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt
{
    DB x,y;
    bool operator < (const pt &rhs) const
    {
        return dcmp(x-rhs.x) ? x<rhs.x : y<rhs.y ;
    }
    bool operator == (const pt &rhs) const
    {
        return !dcmp(x-rhs.x) && !dcmp(y-rhs.y) ;
    }
};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) { return (pt){d*a.x,d*a.y} ; }
DB dot(const pt &a,const pt &b) { return a.x*b.x+a.y*b.y ; }
DB cross(const pt &a,const pt &b) { return a.x*b.y-a.y*b.x ; }
int cross(const pt &a,const pt &b,const pt &c) { return dcmp(cross(b-a,c-a)) ; }

typedef vector<pt> poly ;

poly np ;
poly convex_hull(poly &p)
{
    np.resize(p.size()+10) ;
    sort(p.begin(),p.end()) ;
    int s1=0 ;
    for(int i=0;i<p.size();i++)
    {
        while(s1>=2 && cross(np[s1-2],np[s1-1],p[i])<=0) s1-- ;
        np[s1++]=p[i] ;
    }

    int s2=s1 ;
    for(int i=(int)p.size()-1;i>=0;i--)
    {
        if(i+1==p.size() && p[i]==np[s1-1])
            { s1-- ; continue ; }
        while(s2>=s1+2 && cross(np[s2-2],np[s2-1],p[i])<=0) s2-- ;
        np[s2++]=p[i] ;
    }

    if(np[s2-1]==np[0]) s2-- ;
    np.resize(s2) ;
    return np ;
}

pt inter(const pt &P,const pt &u,const pt &Q,const pt &v)
{
    return P + u * (cross(v,Q-P)/cross(v,u)) ;
}

int n ;
poly p2 ;
DB ang[maxn],ang2[maxn] ;
pt tmp[maxn] ;
int solve(poly &p,const poly &q)
{
    p2=convex_hull(p) ;
    int sz=p2.size() ;
    if(sz==2)
    {
        int ans=0 ;
        for(int i=0;i<n;i++)
            if(dcmp(dot(p2[0]-q[i],p2[1]-q[i]))<=0)
            ans++ ;
        return ans ;
    }

    DB x0=0 , y0=0 ;
    for(auto i : p2) x0+=i.x , y0+=i.y ;
    pt ori = (pt){x0,y0} * (1.0/sz) , zero=(pt){0,0} ;

    for(int i=0;i<sz;i++)
    {
        p2[i]=p2[i]-ori ;
        ang[i]=atan2(p2[i].y,p2[i].x) ;
    }

    for(int i=0;i+1<sz;i++) if(ang[i+1]<ang[i])
    {
        for(int j=0;j<sz;j++)
            tmp[j]=p2[j] , ang2[j]=ang[j] ;
        for(int j=0;j<sz;j++)
            p2[j]=tmp[(j+i+1)%sz] ,
            ang[j]=ang2[(j+i+1)%sz] ;
        break ;
    }

    int ans=0 ;
    for(int i=0;i<n;i++)
    {
        pt nowp=q[i]-ori , z ;
        DB angle=atan2(nowp.y,nowp.x) ;
        if(dcmp(angle-ang[0])<=0 || dcmp(angle-ang[sz-1])>=0)
            z=inter(p2[0],p2[sz-1]-p2[0],zero,nowp) ;
        else
        {
            int l=0 , r=sz-1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(dcmp(angle-ang[mid])>=0) l=mid ;
                else r=mid ;
            }
            z=inter(p2[r],p2[l]-p2[r],zero,nowp) ;
        }
        if(dcmp(dot(z-nowp,zero-nowp))<=0) ans++ ;
    }
    return ans ;
}

poly p,q ;
main()
{
    freopen("curling.in","r",stdin) ;
    freopen("curling.out","w",stdout) ;
    scanf("%d",&n) ;
    p.resize(n) ; q.resize(n) ;
    p2.resize(n) ;
    for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y) ;
    for(int i=0;i<n;i++) scanf("%lf%lf",&q[i].x,&q[i].y) ;
    printf("%d %d\n",solve(p,q),solve(q,p)) ;
}
