#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB eps=1e-9 ;
const int maxn=100000+10 ;

int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}

struct pt{DB x,y ;};

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

typedef vector<pt> poly ;
DB Area(const poly &p)
{
    DB ret=0 ;
    for(int i=1;i+1<p.size();i++)
        ret+=cross(p[0],p[i],p[i+1])/2 ;
    return fabs(ret) ;
}
inline DB Area(const pt &a,const pt &b,const pt &c)
{
    return fabs(cross(a,b,c))/2 ;
}

int n,x[maxn],y[maxn] ;
poly p ;
DB pw2[maxn] ;
DB cal_area()
{
    DB now=0,sub=0 ;
    for(int i=1;i<=min(n-3,50);i++)
    {
        for(int j=0;j<n;j++) now+=Area(p[j],p[(j+i)%n],p[(j+i+1)%n]) ;
        sub+=now*(pw2[i+2]-pw2[n]) ;
    }
    sub*=(1+((n*n+n+2)/(pow(2,n+1)-(n*n+n+2)))) ;
    return Area(p)-sub ;
}

inline int getnum(int i,int j)
{
    int g=__gcd(x[i]-x[j],y[i]-y[j]) ;
    return g<0 ? -g : g ;
}
DB cal_edge()
{
    DB ret=0 ;
    for(int i=1;i<=min(n-2,50);i++)
        for(int j=0;j<n;j++)
        ret+=getnum(j,(j+i)%n)*(pw2[i+1]-pw2[n]) ;
    ret*=(1+((n*n+n+2)/(pow(2,n+1)-(n*n+n+2)))) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ; p.resize(n) ;
    for(int i=0;i<maxn;i++) pw2[i]=(i ? pw2[i-1]*0.5 : 1) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]) ;
        p[i]=(pt){x[i],y[i]} ;
    }
    printf("%.15f\n",cal_area()-cal_edge()/2+1) ;
}
