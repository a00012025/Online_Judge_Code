#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
#define MAX(x,y,z) max(x,max(y,z))
using namespace std;
const int maxn=100000+10 ;

struct P{LL val,le,ri ;}ST[12*maxn] ;

int h[2*maxn],d[2*maxn] ;
LL sum[2*maxn] ;

void maintain(int L,int R,int id)
{
    int mid=(L+R)/2 ;
    ST[id].le = max(ST[2*id].le , ST[2*id+1].le+sum[mid+1]-sum[L]) ;
    ST[id].ri = max(ST[2*id+1].ri , ST[2*id].ri+sum[R]-sum[mid]) ;
    ST[id].val = MAX(ST[2*id].val,ST[2*id+1].val,
                     sum[mid+1]-sum[mid]+ST[2*id].ri+ST[2*id+1].le) ;
}

void build(int L,int R,int id)
{
    if(L==R) { ST[id]=(P){-INF,2*h[L],2*h[L]} ; return ; }
    int mid=(L+R)/2 ;
    build(L,mid,2*id) ;
    build(mid+1,R,2*id+1) ;
    maintain(L,R,id) ;
//    printf("[%d,%d] : %I64d , %I64d , %I64d\n",L,R,ST[id].val,ST[id].le,ST[id].ri);
}

LL query_l(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id].le ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query_l(l,r,L,mid,2*id) ;
    else return max(ST[2*id].le ,
                   sum[mid+1]-sum[L]+query_l(mid+1,r,mid+1,R,2*id+1)) ;
}

LL query_r(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id].ri ;
    int mid=(L+R)/2 ;
    if(l>mid) return query_r(l,r,mid+1,R,2*id+1) ;
    else return max(ST[2*id+1].ri ,
                   sum[R]-sum[mid]+query_r(l,mid,L,mid,2*id)) ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(L==l && r==R) return ST[id].val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else
    {
        LL ret=max(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1)) ;
        ret=max(ret,query_r(l,mid,L,mid,2*id) +
                query_l(mid+1,r,mid+1,R,2*id+1) +
                sum[mid+1]-sum[mid] ) ;
        return ret ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&d[i]) , d[i+n]=d[i] ;
    for(int i=1;i<=n;i++) scanf("%d",&h[i]) , h[i+n]=h[i] ;
    for(int i=1;i<2*n;i++) sum[i+1]=sum[i]+d[i] ;
    build(1,2*n,1) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x>y) printf("%I64d\n",query(y+1,x-1,1,2*n,1)) ;
        else printf("%I64d\n",query(y+1,x+n-1,1,2*n,1)) ;
    }
}
