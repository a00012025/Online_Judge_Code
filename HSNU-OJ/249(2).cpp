#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;
struct P
{
    int len,x ;
    bool operator < (const P &rhs) const
    {
        if(len!=rhs.len) return len<rhs.len ;
        else return x<rhs.x ;
    }
}a[maxn];

int MOD,ST[8*maxn] ;
void build(int l,int r,int id)
{
    ST[id]=1 ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(L==R) { ST[id]=(val%MOD) ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    ST[id]=(ST[2*id]*ST[2*id+1])%MOD ;
}

int query(int l,int r,int L,int R,int id)
{
    if(L==l && R==r) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return (query(l,mid,L,mid,2*id)*query(mid+1,r,mid+1,R,2*id+1))%MOD ;
}

P a2[maxn] ;
vector<int> v[maxn] ;
int can_eat(int vid,int val)
{
    if(2*v[vid][0]>val) return 0 ;
    int l=0 , r=v[vid].size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(2*v[vid][mid]<=val) l=mid ;
        else r=mid ;
    }
    return l+1 ;
}

int num[maxn],id[maxn] ;
main()
{
    int n,k ; scanf("%d%d%d",&n,&k,&MOD);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].len,&a[i].x) ;
        v[a[i].x].push_back(a[i].len) ;
    }
    for(int i=1;i<=k;i++) sort(v[i].begin(),v[i].end()) ;
    sort(a+1,a+n+1) ;
    for(int i=n;i>=1;i--) if(a2[a[i].x].len==0)
        a2[a[i].x]=a[i] ;
    sort(a2+1,a2+k+1) ;
    for(int i=1;i<=k;i++) id[a2[i].x]=i ;

    build(1,k,1) ;
    int ans=0 , j=0 ;
    for(int i=1;i<=k;i++)
    {
        while(j<n && 2*a[j+1].len<=a2[i].len)
        {
            j++ ;
            num[a[j].x]++ ;
            modify(1,k,1,id[a[j].x],num[a[j].x]+1) ;
        }
        int l=i , r=k+1 ;
        int val=can_eat(a2[i].x,a2[i].len) ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(can_eat(a2[i].x,a2[mid].len)>val) r=mid ;
            else l=mid ;
        }
        int add= i<l ? query(i+1,l,1,k,1) : 1 ;
        add = (add + num[a2[i].x]) % MOD ;
        add *= (i>1 ? query(1,i-1,1,k,1) : 1 ) ;
        add %= MOD ;
        ans = (ans+add)%MOD ;
    }
    printf("%d\n",ans) ;
}
