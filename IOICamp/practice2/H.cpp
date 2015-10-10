#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;
struct P{LL ma,s ; int pos ;};
int a[maxn],n ;
P ST[8*maxn] ;

inline void pull(int id)
{
    ST[id].ma=max(ST[2*id].ma,ST[2*id+1].ma) ;
    ST[id].pos= ST[2*id].ma>=ST[2*id+1].ma ? ST[2*id].pos : ST[2*id+1].pos ;
    ST[id].s=ST[2*id].s+ST[2*id+1].s ;
}

void build(int l,int r,int id)
{
    if(l==r) { ST[id]=(P){a[l],a[l],l} ; return ; }
    int mid=(l+r)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
    pull(id) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(L==R) { ST[id].ma=ST[id].s=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    pull(id) ;
}

LL query_s(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id].s ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query_s(l,r,L,mid,2*id) ;
    else if(l>mid) return query_s(l,r,mid+1,R,2*id+1) ;
    else return query_s(l,mid,L,mid,2*id)+query_s(mid+1,r,mid+1,R,2*id+1) ;
}

void cal_mod(int id,int val)
{
    while(ST[id].ma >= val)
    {
        int pos=ST[id].pos ;
        modify(1,n,1,pos,ST[id].ma%val) ;
    }
}

void modify2(int l,int r,int L,int R,int id,int val)
{
    if(l==L && r==R) { cal_mod(id,val) ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) modify2(l,r,L,mid,2*id,val) ;
    else if(l>mid) modify2(l,r,mid+1,R,2*id+1,val) ;
    else
    {
        modify2(l,mid,L,mid,2*id,val) ;
        modify2(mid+1,r,mid+1,R,2*id+1,val) ;
    }
    pull(id) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int Q ; scanf("%d%d",&n,&Q) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build(1,n,1) ;
        while(Q--)
        {
            int op ; scanf("%d",&op) ;
            if(op==1)
            {
                int l,r ; scanf("%d%d",&l,&r) ;
                printf("%lld\n",query_s(l,r,1,n,1)) ;
            }
            else if(op==2)
            {
                int l,r,m ; scanf("%d%d%d",&l,&r,&m) ;
                modify2(l,r,1,n,1,m) ;
            }
            else
            {
                int i,x ; scanf("%d%d",&i,&x) ;
                modify(1,n,1,i,x) ;
            }
        }
    }
}
