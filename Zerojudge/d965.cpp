#include<bits/stdc++.h>
using namespace std;
struct P
{
    int len,val ;
    bool operator < (const P &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return len<rhs.len ;
    }
};
int n,a[2001],dp[2001][2001] ;
set<P> st ;

void st_insert(P x)
{
    st.insert(x) ;
    set<P>::iterator it=st.find(x) ;
    bool keep=1 ;
    if(it!=st.begin())
    {
        it-- ; if(it->len >= x.len) keep=0 ;
        it++ ;
    }
    if(!keep) {st.erase(*it) ; return ;}
    while(1)
    {
        set<P>::iterator it2=it ; it2++ ;
        if(it2==st.end()) break ;
        if(it2->len <= x.len) st.erase(*it2) ;
        else break ;
    }
}

main()
{
        freopen("pe.txt","r",stdin) ;
        //freopen("pe(me).txt","w",stdout) ;
    int T ;scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        dp[0][0]=0 ;
        int ans=0 ;
        for(int i=0;i<=n;i++)
        {
            if(ans==n) break ;
            st.clear() ;
            if(!i) st.insert((P){0,0}) ;
            else for(int j=0;j<i;j++) st_insert((P){dp[j][i] , a[j]}) ;
            for(int j=i+1;j<=n;j++)
            {
                if(ans==n) break ;
                set<P>::iterator it=st.upper_bound((P){-1,a[j]}) ; it-- ;
                dp[i][j]=(it->len)+1 ; ans=max(ans,dp[i][j]) ;
                st_insert((P){dp[i][j] , a[j]}) ;
            }
        }
        printf("%d\n",ans) ;
    }
}
