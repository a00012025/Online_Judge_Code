#ifdef NDEBUG

#endif // NDEBUG


#include<bits/stdc++.h>
#define LL long long
#define MAX(x,y,z) max(x,max(y,z))
using namespace std;
const int maxn=200000+10 ;
struct P{LL l,r,s,val;}ST[960000];
int n,d ;
LL k ;

inline void maintain(int id)
{
    ST[id].s = ST[2*id].s + ST[2*id+1].s ;
    ST[id].l = max(ST[2*id].l , ST[2*id].s+ST[2*id+1].l) ;
    ST[id].r = max(ST[2*id+1].r , ST[2*id+1].s+ST[2*id].r) ;
    ST[id].val = MAX( ST[2*id].r+ST[2*id+1].l , ST[2*id].val , ST[2*id+1].val );
}

void build(int l,int r,int id)
{
    if(l==r) { ST[id]=(P){0,0,-k,0} ; return ; }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    maintain(id) ;
}

void modify(int L,int R,int id,int pos,LL val)
{
    if(L==R)
    {
        ST[id].s += val ;
        ST[id].l=ST[id].r=ST[id].val=max(ST[id].s,0LL) ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    maintain(id) ;
}

LL queryr(int l,int r,int L,int R,int id) /// R==r
{
    if(l==L && r==R) return ST[id].r ;
    int mid=(L+R)/2 ;
    if(l>mid) return queryr(l,r,mid+1,R,2*id+1) ;
    return max(ST[2*id+1].r,ST[2*id+1].s+queryr(l,mid,L,mid,2*id)) ;
}

LL queryl(int l,int r,int L,int R,int id) /// L==l
{
    if(l==L && r==R) return ST[id].l ;
    int mid=(L+R)/2 ;
    if(r<=mid) return queryl(l,r,L,mid,2*id) ;
    return max(ST[2*id].l,ST[2*id].s+queryl(mid+1,r,mid+1,R,2*id+1)) ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id].val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    return MAX(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1),
               queryr(l,mid,L,mid,2*id)+queryl(mid+1,r,mid+1,R,2*id+1)) ;
}

main()
{
    int Q ; scanf("%d%d%I64d%d",&n,&Q,&k,&d) ;
    build(1,n,1) ;
    while(Q--)
    {
        int x ; LL y ; scanf("%d%I64d",&x,&y) ;
        modify(1,n,1,x,y) ;
        if(query(1,n-d,1,n,1)<=k*d && queryr(1,n,1,n,1)<=0) printf("TAK\n") ;
        else printf("NIE\n") ;
    }
}
