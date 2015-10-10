#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=300000+10 ;

struct P
{
    int x,y,z ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x<rhs.x ;
    }
}p[maxn];

int m,n,A,B,a,b ;
int C=~(1<<31) , M=(1<<16)-1 ;
int R()
{
    a = 36969 * (a & M) + (a >> 16);
    b = 18000 * (b & M) + (b >> 16);
    return (C & ((a << 16) + b)) % 1000000;
}

bool can(const set<pii> &s,const pii &p0)
{
    auto it=s.lower_bound(pii(p0.F,-1e9)) ;
    if(it==s.begin()) return 0 ;
    it-- ;
    return it->S < p0.S ;
}

void insert(set<pii> &s,const pii &p0)
{
    s.insert(p0) ; auto it=s.find(p0) ;
    bool keep=1 ;
    if(it!=s.begin())
    {
        it-- ;
        if(it->S <= p0.S) keep=0 ;
        it++ ;
    }
    if(!keep){s.erase(it) ; return ;}
    while(1)
    {
        auto it2=it ; it2++ ;
        if(it2!=s.end() && it2->S >= p0.S) s.erase(it2) ;
        else break ;
    }
}

int d[maxn] ;
set<pii> st[maxn] ;
void solve()
{
    a=A ; b=B ;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z) ;
    n+=m ;
    for(int i=m+1;i<=n;i++)
        p[i].x=R() , p[i].y=R() , p[i].z=R() ;
    sort(p+1,p+n+1) ;

    for(int i=1;i<=n;i++) st[i].clear() ;
    st[0].insert(pii(-1,-1)) ;
    int sz=0 ;
    for(int i=1;i<=n;i++)
    {
        pii p0(p[i].y,p[i].z) ;
        int l=0 , r=sz+1 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(can(st[mid],p0)) l=mid ;
            else r=mid ;
        }
        if(l==sz) sz++ ;
        insert(st[l+1],p0) ;
    }
    printf("%d\n",sz) ;
}

main()
{
    while(scanf("%d%d%d%d",&m,&n,&A,&B)==4 && n+m+A+B) solve() ;
}
