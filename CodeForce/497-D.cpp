#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=1000+10 ;

struct pt
{
    DB x,y;
    void scan(){scanf("%lf%lf",&x,&y) ;}
};
struct cir
{
    DB x,y,r;
    cir(const pt &c,DB _r){x=c.x , y=c.y , r=_r ;}
};

const DB eps=1e-7 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    else return x>0 ? 1 : -1 ;
}

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x , a.y-b.y} ; }
pt operator * (const pt &a,const DB &d) {return (pt){d*a.x,d*a.y} ; }
DB dot(const pt &a,const pt &b){return a.x*b.x + a.y*b.y ;}
DB cross(const pt &a,const pt &b) {return a.x*b.y - a.y*b.x ;}
DB length(const pt &a) {return sqrt(dot(a,a)) ;}

DB pt_to_seg(const pt &p,const pt &a,const pt &b)
{
    return fabs(cross(p-a,b-a))/length(a-b) ;
}

pt pt_foot(const pt &p,const pt &a,const pt &b)
{
    return a + (b-a) * (dot(p-a,b-a)/dot(b-a,b-a)) ;
}

bool seg_inter_circle(const pt &a,const pt &b,const cir &C)
{
    pt c=(pt){C.x,C.y} ;
    if(dcmp(C.r-length(c-a))>=0 && dcmp(C.r-length(c-b))<=0) return 1 ;
    if(dcmp(C.r-length(c-b))>=0 && dcmp(C.r-length(c-a))<=0) return 1 ;
    if(dcmp(C.r-length(c-b))>0 && dcmp(C.r-length(c-a))>0) return 0 ;
    if(dcmp(pt_to_seg(c,a,b)-C.r)>0) return 0 ;
    pt f=pt_foot(c,a,b) ;
    return dcmp(dot(a-f,b-f))<=0 ;
}

pt P,Q,a[maxn],b[maxn] ;
bool check(const pt &p1,const pt &p2,const pt &q)
{
    return seg_inter_circle(p1-P,p2-P,cir(q-Q,length(P-Q))) ;
}

int n,m ;
main()
{
    P.scan() ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) a[i].scan() ;
    Q.scan() ; scanf("%d",&m) ;
    for(int i=0;i<m;i++) b[i].scan() ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(check(a[i],a[(i+1)%n],b[j])){printf("YES\n") ; return 0 ;}
    swap(n,m) ; swap(P,Q) ; swap(a,b) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(check(a[i],a[(i+1)%n],b[j])){printf("YES\n") ; return 0 ;}
    printf("NO\n") ;
}
