#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;
struct P{int l,r,type,id ;}a[maxn];
bool cmp(const P &a,const P &b)
{
    if(a.l != b.l) return a.l<b.l ;
    else if(a.type != b.type) return a.type<b.type ;
    else if(a.r != b.r) return a.r<b.r ;
    else return a.id<b.id ;
}

struct Q
{
    int id,val;
    bool operator < (const Q &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return id<rhs.id ; /// OK???
    }
};
int n,m,times[maxn],ans[maxn/2] ;
set<Q> st ;
bool solve()
{
    for(int i=1;i<=m+n;i++)
    {
        if(a[i].type==1) { st.insert((Q){a[i].id,a[i].r}) ; continue ; }
        if(st.empty()) return 0 ;
        set<Q>::iterator it=st.lower_bound((Q){-1,a[i].r}) ;
        if(it==st.end()) return 0 ;
        ans[a[i].id]=it->id ;
        if((--times[it->id])==0) st.erase(it) ;
    }
    printf("YES\n") ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        a[i]=(P){x,y,2,i} ;
    }
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y,k ; scanf("%d%d%d",&x,&y,&k) ;
        a[i+n]=(P){x,y,1,i} ;
        times[i]=k ;
    }
    sort(a+1,a+m+n+1,cmp) ;
    if(!solve()) printf("NO\n") ;
}
