#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 ;

int n,a[maxn],inv[maxn],mi[maxn] ;
set<int> sti ;
set<pii> st ;

void insert(const pii &p)
{
    st.insert(p) ;
    set<pii>::iterator it=st.find(p) ;
    bool keep=1 ;
    if(it!=st.begin())
    {
        it-- ;
        if(it->S > p.S) keep=0 ;
        it++ ;
    }
    if(!keep) { st.erase(it) ; return ; }

    while(1)
    {
        set<pii>::iterator it2=it ;
        it2++ ; if(it2==st.end()) break ;
        if(it2->S < p.S) st.erase(it2) ;
        else break ;
    }
}

bool check()
{
    for(int i=1;i<n;i++)
    {
        if(i==1) { sti.insert(a[1]) ; continue ; }
        if(a[i]<(*sti.begin())) { sti.insert(a[i]) ; continue ; }
        if(!st.empty() && (*st.begin()).F < a[i])
        {
            set<pii>::iterator it=st.lower_bound(mkp(a[i],a[i])) ;
            it-- ;
            if(mi[i+1]<it->S) return 0 ;
        }
        set<int>::iterator it=sti.lower_bound(a[i]) ; it-- ;
        insert(mkp(a[i],*it)) ; /// a[i] > *it
        sti.insert(a[i]) ;
    }
    return 1 ;
}

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

vector<int> v[maxn] ;
void add_edge(int x,int y)
{
    if(getfa(x)==getfa(y)) return ;
    v[x].push_back(y) ;
    v[y].push_back(x) ;
    fa[getfa(x)]=getfa(y) ;
}

int ans[maxn] ;
void dfs(int x)
{
    for(auto i : v[x]) if(!ans[i])
        ans[i]=3-ans[x] , dfs(i) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) , inv[a[i]]=i ;
    for(int i=n;i>=1;i--) mi[i]= (i==n?a[i]:min(mi[i+1],a[i])) ;

    if(!check()) { printf("NIE\n") ; return 0 ; }

    sti.clear() ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    for(int i=1;i<n;i++)
    {
        sti.insert(a[i]) ;
        if(a[i]==(*sti.begin())) continue ;
        set<int>::iterator it=sti.lower_bound(a[i]) ; it-- ;

        while(*it > mi[i+1])
        {
            add_edge(inv[*it],i) ;
            if(a[i]<a[i-1]) break ;
            if(it==sti.begin()) break ;
            it-- ;
        }
    }

    for(int i=1;i<=n;i++) if(!ans[i])
        ans[i]=1 , dfs(i) ;

    printf("TAK\n") ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]) ;
}
