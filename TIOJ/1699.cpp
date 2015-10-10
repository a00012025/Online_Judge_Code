#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+10,maxq=1000000+10 ;

struct P
{
    int l,r,k,id;
    bool operator < (const P &rhs) const
    {
        return l==rhs.l ? r<rhs.r : l<rhs.l ;
    }
};

int a[maxn] ;
vector<int> v0 ;
vector<P> G[300] ;
bool ans[maxq] ;

int num[maxn],cnt[maxn],maxval ;

void add(int x)
{
    cnt[num[x]]-- ;
    num[x]++ ; cnt[num[x]]++ ;
    maxval=max(maxval,num[x]) ;
}

void sub(int x)
{
    cnt[num[x]]-- ;
    num[x]-- ; cnt[num[x]]++ ;
    if(!cnt[maxval]) maxval-- ;
}

void solve(const vector<P> &v)
{
    memset(cnt,0,sizeof(cnt)) ;
    memset(num,0,sizeof(num)) ;
    cnt[0]=maxn ; maxval=0 ;
    for(int i=v[0].l;i<=v[0].r;i++) add(a[i]) ;
    if(maxval > (v[0].r-v[0].l)/v[0].k) ans[v[0].id]=1 ;
    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i-1].l;j<v[i].l;j++) sub(a[j]) ;
        if(v[i-1].r > v[i].r) for(int j=v[i-1].r;j>v[i].r;j--) sub(a[j]) ;
        if(v[i-1].r < v[i].r) for(int j=v[i-1].r+1;j<=v[i].r;j++) add(a[j]) ;
        if(maxval > (v[i].r-v[i].l)/v[i].k) ans[v[i].id]=1 ;
    }
}

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    int sq=(int)sqrt(n+0.5) ;

    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , v0.push_back(a[i]) ;
    sort(v0.begin(),v0.end()) ;
    v0.resize(unique(v0.begin(),v0.end())-v0.begin()) ;
    for(int i=1;i<=n;i++) a[i]=lower_bound(v0.begin(),v0.end(),a[i])-v0.begin() ;

    for(int i=1;i<=Q;i++)
    {
        int l,r,k ; scanf("%d%d%d",&l,&r,&k) ;
        G[l/sq].push_back((P){l,r,k,i}) ;
    }
    for(int i=0;i<300;i++) if(!G[i].empty())
        sort(G[i].begin(),G[i].end()) , solve(G[i]) ;
    for(int i=1;i<=Q;i++) printf("%s\n",ans[i] ? "Yes" : "No") ;
}
