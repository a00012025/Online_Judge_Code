#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=500000+10 ;

struct P
{
    int h,id ;
    bool operator < (const P &rhs) const
    {
        return h==rhs.h ? id<rhs.id : h>rhs.h ;
    }
}a[maxn];

struct seg
{
    int l,r ;
    bool operator < (const seg &rhs) const
    {
        return l==rhs.l ? r<rhs.r : l<rhs.l ;
    }
};

set<seg> st ;
map<int,int,greater<int> > lens ;
vector<pii> v ;

void Erase(int x)
{
    auto it=lens.find(x) ;
    if( !(--(it->S)) ) lens.erase(it) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].h) , a[i].id=i ;
    sort(a+1,a+n+1) ;

    st.insert((seg){1,n}) ;
    lens[n]++ ;
    for(int i=1;i<=n;i++)
    {
        if(i==1 || a[i].h!=a[i-1].h)
        {
            int maxl= lens.begin()->F , sz=v.size() ;
            if(sz && v[sz-1].S==maxl) v[sz-1].F=a[i].h ;
            else v.push_back(mkp(a[i].h,maxl)) ;
        }
        auto it=st.lower_bound((seg){a[i].id,n+1}) ; it-- ;
        int L=it->l , R=it->r ;
        st.erase(it) ; Erase(R-L+1) ;
        if(L==R) continue ;
        if(L==a[i].id) st.insert((seg){L+1,R}) , lens[R-L]++ ;
        else if(R==a[i].id) st.insert((seg){L,R-1}) , lens[R-L]++ ;
        else
        {
            st.insert((seg){L,a[i].id-1}) ;
            st.insert((seg){a[i].id+1,R}) ;
            lens[a[i].id-L]++ ;
            lens[R-a[i].id]++ ;
        }
    }
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int d ; scanf("%d",&d) ;
        int l=0 , r=v.size() ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(v[mid].S>=d) l=mid ;
            else r=mid ;
        }
        printf("%d\n",v[l].F) ;
    }
}
