#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=3000+10 ;
const DB eps=1e-7 ;

struct pt{DB x,y;};
pt operator - (const pt &a,const pt &b){return (pt){a.x-b.x,a.y-b.y};}
DB dot(const pt &a,const pt &b){return a.x*b.x+a.y*b.y;}
DB len(const pt &a){return sqrt(dot(a,a));}
DB cross(const pt &a,const pt &b){return a.x*b.y-a.y*b.x ;}
DB cross(const pt &a,const pt &b,const pt &c){return cross(b-a,c-a) ;}

struct line
{
    DB a,b,c,val;
    bool operator < (const line &rhs) const
    {
        return val>rhs.val ;
    }
    void scan(){scanf("%lf%lf%lf",&a,&b,&c);}
}L[maxn];

pt getinter(const line &P,const line &Q)
{
    DB d=cross((pt){P.a,Q.a},(pt){P.b,Q.b}) ;
    DB x=cross((pt){P.c,Q.c},(pt){P.b,Q.b}) ;
    DB y=cross((pt){P.a,Q.a},(pt){P.c,Q.c}) ;
    return (pt){x/d,y/d} ;
}

DB area(const pt &a,const pt &b,const pt &c)
{
    return fabs(cross(a,b,c))/2 ;
}

DB area(const line &P,const line &Q,const line &R)
{
    return area(getinter(P,Q),getinter(Q,R),getinter(P,R)) ;
}

DB getcos(const line &P,const line &Q)
{
    pt u=(pt){P.b,-P.a} , v=(pt){Q.b,-Q.a} ;
    if(cross(u,v)<-eps) v=(pt){-Q.b,Q.a} ;
    return dot(u,v)/len(u)/len(v) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        L[i].scan() ;
        if(i>1) L[i].val=getcos(L[1],L[i]) ;
    }
    sort(L+2,L+n+1) ;
    DB ans=0 ;
    for(int i=2;i<=n;i++) for(int j=i+1;j<=n;j++)
        ans+=area(L[1],L[i],L[j])*(n-2*(j-i))/n/(n-1) ;
    printf("%.10f\n",ans*6/(n-2)) ;
}
