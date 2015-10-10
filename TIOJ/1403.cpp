#include<bits/stdc++.h>
#define MOD 1000000
#define lowbit(x) (x&-x)
#define DB double
using namespace std;
const int maxn=250000+10 ;
const DB eps=1e-7 ;

int bit[200] ;
void add(int x)
{
    while(x<200) bit[x]++ , x+=lowbit(x) ;
}

int query(int x)
{
    int ret=0 ;
    while(x) ret+=bit[x] , x-=lowbit(x) ;
    return ret ;
}

int x[maxn],v[maxn] ;
int las[maxn],nex[maxn] ;
struct P
{
    int l,r ;
    DB t ;
    P(int _l,int _r)
    {
        l=_l ; r=_r ;
        t= ((DB)x[r]-x[l])/((DB)v[l]-v[r]) ;
    }
    bool operator < (const P &rhs) const
    {
        if(fabsl(t-rhs.t)>eps) return t<rhs.t ;
        return x[l]+t*v[l] < x[rhs.l]+rhs.t*v[rhs.l] ;
    }
};

set<P> st ;
void check(int l)
{
    int r=nex[l] ;
    if(!l || !r || v[r]>=v[l]) return ;
    st.insert(P(l,r)) ;
}

main()
{
    int n; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&v[i]) ;
    int ans=0 ;
    for(int i=n;i>=1;i--)
    {
        ans=(ans+query(v[i]-1))%MOD ;
        add(v[i]) ;
    }
    printf("%d\n",ans) ;

    for(int i=1;i<=n;i++)
        nex[i]= (i==n ? 0 : i+1), las[i]= i-1 ,
        check(i) ;
    int cnt=10000 ;
    while(!st.empty())
    {
        P u=*st.begin() ; st.erase(st.begin()) ;
        printf("%d %d\n",u.l,u.r) ;
        int L=las[u.l] , R=nex[u.r] ;
        st.erase(P(L,u.l)) ;
        st.erase(P(u.r,R)) ;
        las[u.r]=L ; nex[u.r]=u.l ;
        las[u.l]=u.r ; nex[u.l]=R ;
        nex[L]=u.r ; las[R]=u.l ;
        check(L) ; check(u.l) ;
        if(!(--cnt)) break ;
    }
}
