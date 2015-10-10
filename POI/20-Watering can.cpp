#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=300000+10 ;

struct P{int val,tag,id;}ST[4*maxn];
struct RET{int val,id;};
int ST2[4*maxn] ;

int n,k,a[maxn] ;

void pull(int id)
{
     ST[id].val = max(ST[2*id].val,ST[2*id+1].val) ;
     if(ST[2*id].val > ST[2*id+1].val) ST[id].id=ST[2*id].id ;
     else ST[id].id=ST[2*id+1].id ;
}

void push(int id)
{
     if(!ST[id].tag) return ;
     int t=ST[id].tag ;
     ST[2*id].val+=t ; ST[2*id].tag+=t ;
     ST[2*id+1].val+=t ; ST[2*id+1].tag+=t ;
     ST[id].tag=0 ;
}

void build(int l,int r,int id)
{
     if(l==r) { ST[id]=(P){a[l],0,l} ; return ; }
     int mid=(l+r)/2 ;
     build(l,mid,2*id) ;
     build(mid+1,r,2*id+1) ;
     pull(id) ;
}

void add(int l,int r,int L,int R,int id,int val)
{
     if(l==L && r==R) { ST[id].val+=val ; ST[id].tag+=val ; return ; }
     push(id) ;
     int mid=(L+R)/2 ;
     if(r<=mid) add(l,r,L,mid,2*id,val) ;
     else if(l>mid) add(l,r,mid+1,R,2*id+1,val) ;
     else add(l,mid,L,mid,2*id,val) ,
          add(mid+1,r,mid+1,R,2*id+1,val) ;
     pull(id) ;
}

RET cal(const RET &x,const RET &y)
{
     RET r ;
     r.val=max(x.val,y.val) ;
     if(x.val > y.val) r.id=x.id ;
     else r.id=y.id ;
     return r ;
}

RET query(int l,int r,int L,int R,int id)
{
     if(l==L && r==R) return (RET){ST[id].val,ST[id].id} ;
     int mid=(L+R)/2 ;
     if(r<=mid) return query(l,r,L,mid,2*id) ;
     else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
     else return cal(query(l,mid,L,mid,2*id),
                     query(mid+1,r,mid+1,R,2*id+1)) ;
}

void modify2(int L,int R,int id,int pos)
{
     if(L==R) { ST2[id]++ ; return ; }
     int mid=(L+R)/2 ;
     if(pos<=mid) modify2(L,mid,2*id,pos) ;
     else modify2(mid+1,R,2*id+1,pos) ;
     ST2[id]++ ;
}

int query2(int l,int r,int L,int R,int id)
{
     if(l==L && r==R) return ST2[id] ;
     int mid=(L+R)/2 ;
     if(r<=mid) return query2(l,r,L,mid,2*id) ;
     else if(l>mid) return query2(l,r,mid+1,R,2*id+1) ;
     else return query2(l,mid,L,mid,2*id)+query2(mid+1,r,mid+1,R,2*id+1) ;
}

void inicjuj(int N,int K,int *D)
{
     n=N ; k=K ;
     for(int i=1;i<=n;i++) a[i]=D[i-1] ;
     build(1,n,1) ;
     while(1)
     {
          RET tmp=query(1,n,1,n,1) ;
          if(tmp.val < k) break ;
          modify2(1,n,1,tmp.id) ;
          add(tmp.id,tmp.id,1,n,1,-INF) ;
     }
}

void podlej(int l,int r)
{
     l++ ; r++ ;
     add(l,r,1,n,1,1) ;
     while(1)
     {
          RET tmp=query(l,r,1,n,1) ;
          if(tmp.val < k) break ;
          modify2(1,n,1,tmp.id) ;
          add(tmp.id,tmp.id,1,n,1,-INF) ;
     }
}

int dojrzale(int l,int r)
{
     return query2(l+1,r+1,1,n,1) ;
}
