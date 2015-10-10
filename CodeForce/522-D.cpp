#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
const int maxn=500000+10 ;

int ST[4*maxn] ;
void build(int l,int r,int id)
{
    ST[id]=INF ;
    if(l==r) return ;
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

void modify(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { ST[id]=min(ST[id],val) ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify(l,r,mid+1,R,2*id+1,val) ;
    else modify(l,mid,L,mid,2*id,val) ,
            modify(mid+1,r,mid+1,R,2*id+1,val) ;
}

int query(int L,int R,int id,int pos)
{
    if(L==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return min(ST[id],query(L,mid,2*id,pos)) ;
    else return min(ST[id],query(mid+1,R,2*id+1,pos)) ;
}

map<int,int> mp ;
int a[maxn],le[maxn] ;

struct P
{
    int l,r,id ;
    bool operator < (const P &rhs) const
    {
        return r<rhs.r ;
    }
}q[maxn] ;
int ans[maxn] ;

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++)
    {
        auto it=mp.find(a[i]) ;
        le[i]= it==mp.end() ? -1 : it->second ;
        mp[a[i]]=i ;
    }

    build(1,n,1) ;
    for(int i=1;i<=Q;i++)
        scanf("%d%d",&q[i].l,&q[i].r) , q[i].id=i ;
    sort(q+1,q+Q+1) ;
    for(int i=1,j=1;i<=Q;i++)
    {
        while(j<=q[i].r)
        {
            if(le[j]!=-1) modify(1,le[j],1,n,1,j-le[j]) ;
            j++ ;
        }
        ans[q[i].id]=query(1,n,1,q[i].l) ;
    }
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]==INF?-1:ans[i]) ;
}
