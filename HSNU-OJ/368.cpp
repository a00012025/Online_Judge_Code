#include<bits/stdc++.h>
#define LL long long
#define INF 1000000001
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=200000+10 ;

int bit[maxn] ;
void add(int x,int val,int ma)
{
    while(x<=ma) bit[x]+=val , x+=lowbit(x) ;
}
int query(int l,int r)
{
    int ret=0 ; l-- ;
    while(r) ret+=bit[r] , r-=lowbit(r) ;
    while(l) ret-=bit[l] , l-=lowbit(l) ;
    return ret ;
}

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
}a[maxn];

LL ans=0LL ;
P segl[maxn],segr[maxn] ;
int y[2*maxn] ;
set<int> st ;
void solve(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    solve(l,mid) ;
    solve(mid+1,r) ;

    st.clear() ; st.insert(INF) ;
    int cntl=0,cnt=0 ;
    y[cnt++]=INF ;
    for(int i=mid;i>=l;i--)
    {
        auto it=st.upper_bound(a[i].y) ;
        segl[cntl++]=(P){*it,a[i].y} ;
        st.insert(a[i].y) ;
        y[cnt++]=a[i].y ;
    }

    st.clear() ; st.insert(-INF) ;
    y[cnt++]=-INF ;
    int cntr=0 ;
    for(int i=mid+1;i<=r;i++)
    {
        auto it=st.upper_bound(a[i].y) ; it-- ;
        segr[cntr++]=(P){a[i].y,*it} ;
        st.insert(a[i].y) ;
        y[cnt++]=a[i].y ;
    }

    sort(y,y+cnt) ;
    cnt=unique(y,y+cnt)-y ;
    sort(segl,segl+cntl) ;
    sort(segr,segr+cntr) ;
    for(int i=0;i<cntl;i++)
        segl[i].x=lower_bound(y,y+cnt,segl[i].x)-y+1 ,
        segl[i].y=lower_bound(y,y+cnt,segl[i].y)-y+1 ;
    for(int i=0;i<cntr;i++)
        segr[i].x=lower_bound(y,y+cnt,segr[i].x)-y+1 ,
        segr[i].y=lower_bound(y,y+cnt,segr[i].y)-y+1 ;

    fill(bit,bit+cnt+1,0) ;
    for(int i=cntr-1,j=cntl-1;i>=0;i--)
    {
        while(j>=0 && segl[j].x >= segr[i].x)
            add(segl[j].y,1,cnt) , j-- ;
        ans+=query(segr[i].y,segr[i].x) ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
    sort(a+1,a+n+1) ;
    solve(1,n) ;
    printf("%lld\n",ans) ;
}
