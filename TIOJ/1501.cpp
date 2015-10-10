#include<bits/stdc++.h>
#define INF (1LL<<60)
#define LL long long
using namespace std;
const int maxn=1000+10 ;
struct P
{
    int l,r ;
    bool operator < (const P &rhs) const
    {
        return l==rhs.l ? r>rhs.r : l<rhs.l ;
    }
};

set<P> st[maxn] ;

void insert(int id,const P &p)
{
    st[id].insert(p) ;
    auto it=st[id].find(p) ;

    bool keep=1 ;
    it++ ;
    if(it!=st[id].end() && p.r>=it->r) keep=0 ;
    it-- ;
    if(!keep) { st[id].erase(it) ; return ; }

    while(it!=st[id].begin())
    {
        auto it2=it ; it2-- ;
        if(it2->r >= p.r) st[id].erase(it2) ;
        else break ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) st[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            if(i==1) { insert(1,(P){x,x}) ; continue ; }
            for(auto j : st[i-1])
                insert(i,(P){min(j.l,x),max(j.r,x)}) ;
            if(i>2) for(auto j : st[i-2])
                insert(i,(P){min(j.l,x),max(j.r,x)}) ;
        }
        LL ans=INF ;
        for(auto i : st[n]) ans=min(ans,((LL)i.r-i.l)) ;
        printf("%lld\n",ans) ;
    }
}
