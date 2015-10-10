#define NDEBUG
#include<bits/stdc++.h>
#define DB double
#define LL long long
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
using namespace std;
const DB eps=1e-7 ;
const LL INF=1LL<<60 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x<0 ? -1 : 1 ;
}

struct pt{DB x,y;};

pt operator + (const pt &a,const pt &b) {return (pt){a.x+b.x , a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x , a.y-b.y} ; }
pt operator * (const pt &a,const DB d) {return (pt){d*a.x , d*a.y} ; }

DB dot(const pt &a,const pt &b) {return a.x*b.x+a.y*b.y ;}
DB cross(const pt &a,const pt &b) {return a.x*b.y - a.y*b.x ;}
DB length(const pt &a) {return dot(a,a) ;}

bool segment_inter(pt a,pt b,pt c,pt d)
{
    return dcmp(cross(b-a,c-a)*cross(b-a,d-a))<=0 && dcmp(cross(d-c,a-c)*cross(d-c,b-c))<=0 ;
}

bool on_segment(pt a,pt b,pt p)
{
    return dcmp(cross(a-p,b-p))==0 && dcmp(cross(a-p,b-p))<0 ;
}

pt p[40],q[1001] ;
int n,m ;
bool see[1001][40] ;

bool check(int i,int j) /// q[i] can see p[j]~p[(j+1)%n] ?
{
    if(on_segment(p[j],p[(j+1)%n],q[i])) return 0 ;
    for(int k=(j+1)%n ; (k+1)%n!=j ; k=(k+1)%n)
        if(segment_inter(q[i],p[j],p[k],p[(k+1)%n])) return 0 ;
    for(int k=(j+2)%n ; (k+1)%n!=((j+1)%n) ; k=(k+1)%n)
        if(segment_inter(q[i],p[(j+1)%n],p[k],p[(k+1)%n])) return 0 ;
    pt mid=(p[j]+p[(j+1)%n]) * 0.5 ;
    for(int k=0;k<n;k++)
        if(k!=j && segment_inter(q[i],mid,p[k],p[(k+1)%n])) return 0 ;
    debugf("q[%d] can see p[%d]\n",i,j) ;
    return 1 ;
}

struct P{int l,r ; LL cost;}a[1001] ;

bool contain(int l,int r,int x,int y) /// l~r contain x~y ?
{
    if(l<=r) return x>=l && x<=r && y>=l && y<=r ;
    if(x<n && x>=l && y<n && y>=l && x>y) return 0 ;
    if(x<=r && y<n && y>=l) return 0 ;
    if(x<=r && y<=r && x>y) return 0 ;
    return ( (x<n && x>=l)||(x<=r) ) && ( (y<n && y>=l)||(y<=r) ) ;
}

LL dp[40][40] ;
LL process()
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j]=INF ;
    for(int len=1;len<=n;len++) for(int i=0;i<n;i++)
    {
        int j=(i+len-1)%n ;
        for(int k=0;k<m;k++)
        {
            int l=a[k].l , r=a[k].r ;
            if(contain(l,r,i,j)) dp[i][j]=min(dp[i][j],a[k].cost) ;
            else
            {
                bool res1=contain(l,r,i,i) , res2=contain(l,r,j,j) ;
                LL &ans=dp[i][j] ;
                if(res1 && !res2) ans=min(ans,dp[(r+1)%n][j]+a[k].cost) ;
                else if(res1 && res2) ans=min(ans,dp[(r+1)%n][(l-1+n)%n]+a[k].cost) ;
                else if(!res1 && res2) ans=min(ans,dp[i][(l-1+n)%n]+a[k].cost) ;
            }
        }
        debugf("dp[%d][%d]=%lld\n",i,j,dp[i][j]) ;
    }
    return dp[0][n-1] ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y) ;
        scanf("%d",&m) ;
        for(int i=0;i<m;i++) scanf("%lf%lf%lld",&q[i].x,&q[i].y,&a[i].cost) ;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) see[i][j]=check(i,j) ;
        for(int i=0;i<m;i++)
        {
            int z=0 ;
            for(;see[i][z];z=(z+1)%n) ;
            for(;!see[i][z];z=(z+1)%n) ;
            a[i].l=z ;
            for(;see[i][z];z=(z+1)%n) ;
            a[i].r=(z-1+n)%n ;
            debugf("a[%d] : %d ~ %d\n",i,a[i].l,a[i].r) ;
        }
        LL ans=process() ;
        if(ans==INF) printf("Impossible\n") ;
        else printf("%lld\n",ans) ;
    }
}
