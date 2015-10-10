#include<bits/stdc++.h>
#define DB double
#define SQ(X) ((X)*(X))
#define INF 1e9
using namespace std;
const DB eps=1e-10 ;
const int maxn=120000+10 ;

struct P
{
    int x,y,z;
    void norm()
    {
        int g=__gcd(__gcd(x,y),z) ;
        x/=g ; y/=g ; z/=g ;
    }
}p[maxn];

int len2(const P &a){return SQ(a.x)+SQ(a.y)+SQ(a.z) ; }
bool equ(const P &a,const P &b)
{
    P a2=a , b2=b ;
    a2.norm() ; b2.norm() ;
    return a2.x==b2.x && a2.y==b2.y && a2.z==b2.z ;
}
inline bool great(const P &a,const P &b)
{
    if(a.x>b.x) return 1 ;
    else if(a.x==b.x && a.y>b.y) return 1 ;
    else if(a.x==b.x && a.y==b.y && a.z>b.z) return 1 ;
    else return 0 ;
}

struct Q
{
    DB x,y,z ;
    int id ;
    bool operator < (const Q &rhs) const
    {
        return x<rhs.x ;
    }
    void init(P &p0,int _id)
    {
        id=_id ;
        DB l=sqrt(len2(p0)) ;
        x=p0.x/l ; y=p0.y/l ; z=p0.z/l ;
    }
}q[maxn];

int len2(const Q &a){return SQ(a.x)+SQ(a.y)+SQ(a.z) ; }
Q operator - (const Q &a,const Q &b){return (Q){a.x-b.x,a.y-b.y,a.z-b.z,-1} ;}

int m,n,S,W ;
DB nowd ;
int ans1,ans2 ;
void up(int na1,int na2)
{
    int id1=q[na1].id , id2=q[na2].id ;
    if(equ(p[id1],p[id2])) return ;
    DB nd=sqrt(len2(q[na1]-q[na2])) ;
    if(nd<nowd-eps) nowd=nd , ans1=id1 , ans2=id2 ;
    else if(fabs(nd-nowd)<eps)
    {
        if(great(p[ans1],p[id1]) ||
           (equ(p[ans1],p[id1]) && great(p[ans2],p[id2])))
            nowd=nd , ans1=id1 , ans2=id2 ;
    }
}

void solve()
{
    for(int i=1;i<=m;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z) ;
    n+=m ;

    int g = S;
    for(int i=m+1;i<=n;i++)
    {
        p[i].x = (g/7) %100 + 1;
        p[i].y = (g/700) %100 + 1;
        p[i].z = (g/70000)%100 + 1;
        if( g%2 == 0 ) { g = (g/2); }
        else { g = (g/2) ^ W; }
    }
    DB ang=rand()*1.0/RAND_MAX ;
    for(int i=1;i<=n;i++) q[i].init(p[i],i) ;
    sort(q+1,q+n+1) ;

    nowd=INF ; ans1=ans2=-1 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n && q[j].x<=q[i].x+nowd+eps;j++)
        up(i,j) , up(j,i) ;
    printf("%d %d %d %d %d %d\n",p[ans1].x,p[ans1].y,p[ans1].z,
                                p[ans2].x,p[ans2].y,p[ans2].z) ;
}

main()
{
    srand(time(NULL)) ;
    while(scanf("%d%d%d%d",&m,&n,&S,&W)==4 && m+n+S+W) solve() ;
}