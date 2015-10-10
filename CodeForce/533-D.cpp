#include<bits/stdc++.h>
#define INF 1100000000
using namespace std;
const int maxn=100000+10 ;

int ST[4*maxn] ;
void build(int l,int r,int id)
{
    ST[id]=-INF ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void Setmax(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R){ ST[id]=max(ST[id],val) ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) Setmax(l,r,L,mid,2*id,val) ;
    else if(l>mid) Setmax(l,r,mid+1,R,2*id+1,val) ;
    else Setmax(l,mid,L,mid,2*id,val) ,
        Setmax(mid+1,r,mid+1,R,2*id+1,val) ;
}

int query(int L,int R,int id,int pos)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return max(ST[id],query(L,mid,2*id,pos)) ;
    else return max(ST[id],query(mid+1,R,2*id+1,pos)) ;
}

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

set<P> st ;
void insert(const P &p)
{
    st.insert(p) ; auto it=st.find(p) ;
    bool keep=1 ;
    if(it!=st.begin())
    {
        it-- ;
        if(p.y >= it->y) keep=0 ;
        it++ ;
    }
    if(!keep){st.erase(it) ; return ;}
    while(1)
    {
        auto it2=it ; it2++ ;
        if(it2!=st.end() && it2->y >= p.y) st.erase(it2) ;
        else break ;
    }
}

int pos[maxn],s[maxn] ;
int dp1[maxn],dp2[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<=n+1;i++) scanf("%d",&pos[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&s[i]) , s[i]*=2 ;

    build(1,n,1) ;
    Setmax(1,n,1,n,1,pos[0]) ;
    for(int i=1;i<=n;i++)
    {
        dp1[i]=(s[i]-pos[i])+query(1,n,1,i) ;
        if(dp1[i]<=0) continue ;
        int id=upper_bound(pos+1,pos+n+2,pos[i]+dp1[i])-pos-1 ;
        if(id==n+1) {printf("0\n") ; return 0;}
        if(id>i) Setmax(i+1,id,1,n,1,pos[i]) ;
    }

    build(1,n,1) ;
    Setmax(1,n,1,n,1,-pos[n+1]) ;
    for(int i=n;i>=1;i--)
    {
        dp2[i]=(s[i]+query(1,n,1,i))+pos[i] ;
        if(dp2[i]<=0) continue ;
        int id=lower_bound(pos+1,pos+n+2,pos[i]-dp2[i])-pos ;
        if(id<i) Setmax(id,i-1,1,n,1,-pos[i]) ;
    }

    int ans=pos[n+1]-pos[0] ;
    for(int i=1;i<=n;i++)
    {
        if(dp1[i]>0) ans=min(ans,pos[n+1]-pos[i]) ;
        if(dp2[i]>0) ans=min(ans,pos[i]-pos[0]) ;
    }

    for(int i=n;i>=1;i--)
    {
        auto it=st.upper_bound((P){dp1[i]+pos[i],INF}) ;
        if(it!=st.begin() && dp1[i]>0)
            it-- , ans=min(ans,pos[it->y]-pos[i]) ;
        if(dp2[i]>0) insert((P){pos[i]-dp2[i],i}) ;
    }
    printf("%.4f\n",ans*1.0/2) ;
}
