#include<bits/stdc++.h>
#define INF 1500000000
using namespace std;
const int maxn=200000+10 ;

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x<rhs.x ;
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
        if(it->y >= p.y) keep=0 ;
        it++ ;
    }
    if(!keep) { st.erase(it) ; return ; }
    while(1)
    {
        auto it2=it ; it2++ ;
        if(it2!=st.end() && it2->y<=p.y)
            st.erase(it2) ;
        else break ;
    }
}

P a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
    sort(a+1,a+n+1) ;

    insert((P){-INF,0}) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        auto it=st.upper_bound((P){a[i].x-a[i].y,-INF}) ; it-- ;
        int val=it->y+1 ; ans=max(ans,val) ;
        insert((P){a[i].x+a[i].y,val}) ;
    }
    printf("%d\n",ans) ;
}
