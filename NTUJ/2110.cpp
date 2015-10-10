#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=200000+10 ;

void insert(set<pii> &s,const pii &p)
{
    s.insert(p) ;
    auto it=s.find(p) ;
    bool keep=1 ;
    if(it!=s.begin())
    {
        it-- ;
        if(it->S <= p.S) keep=0 ;
        it++ ;
    }
    if(!keep){s.erase(it) ; return ;}
    while(1)
    {
        auto it2=it ; it2++ ;
        if(it2==s.end() || it2->S < p.S) break ;
        s.erase(it2) ;
    }
}

bool can(set<pii> &s,const pii &p)
{
    auto it=s.lower_bound(pii(p.F,-maxn)) ;
    if(it==s.begin()) return 0 ;
    it-- ;
    return it->S <= p.S ;
}

set<pii> st[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=0;i<=n;i++) st[i].clear() ;
        st[0].insert(pii(0,0)) ;
        int sz=0 ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            if(i-x<0) continue ;
            pii p(x,i-x) ;
            int l=0 , r=sz+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(can(st[mid],p)) l=mid ;
                else r=mid ;
            }
            insert(st[l+1],p) ;
            if(l==sz) sz++ ;
        }
        printf("%d\n",sz) ;
    }
}
