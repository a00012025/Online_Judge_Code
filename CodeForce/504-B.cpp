#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;
int ST[10*maxn] ;

void build(int l,int r,int id)
{
    ST[id]=r-l+1 ;
    if(l==r) return ;
    int mid=(r+l)/2 ;
    build(l,mid,2*id) ;
    build(mid+1,r,2*id+1) ;
}

int query1(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query1(l,r,L,mid,2*id) ;
    else if(l>mid) return query1(l,r,mid+1,R,2*id+1) ;
    else return query1(l,mid,L,mid,2*id)+query1(mid+1,r,mid+1,R,2*id+1) ;
}

void modify(int L,int R,int id,int pos,int val)
{
    if(L==R){ ST[id]+=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    ST[id]=ST[2*id]+ST[2*id+1] ;
}

int n ;
void f(const int a[],int *b) /// per -> rank
{
    build(0,n-1,1) ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) b[i]=1 ;
        else b[i]=query1(0,a[i]-1,0,n-1,1)+1 ;
        modify(0,n-1,1,a[i],-1) ;
    }
}

int query2(int L,int R,int id,int x)
{
    if(L==R) return L ;
    int mid=(L+R)/2 ;
    if(ST[2*id]>=x) return query2(L,mid,2*id,x) ;
    else return query2(mid+1,R,2*id+1,x-ST[2*id]) ;
}

void g(const int a[],int *b) /// rank -> per
{
    build(0,n-1,1) ;
    for(int i=1;i<=n;i++)
    {
        b[i]=query2(0,n-1,1,a[i]) ;
        modify(0,n-1,1,b[i],-1) ;
    }
}

int p[maxn],q[maxn] ;
int p2[maxn],q2[maxn] ;
int r[maxn],r2[maxn] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&q[i]) ;
    f(p,p2) ; f(q,q2) ;
    for(int i=1;i<=n;i++) r[i]=p2[i]+q2[i]-2 ;
    for(int i=n;i>=1;i--)
    {
        if(r[i] >= n-i+1)
        {
            r[i-1]++ ;
            r[i] -= n-i+1 ;
        }
    }
    for(int i=1;i<=n;i++) r[i]++ ;
    g(r,r2) ;
    for(int i=1;i<=n;i++) printf("%d%c",r2[i],i==n?'\n':' ') ;
}
