#include<stdio.h>
#include<algorithm>
#define LL int
using namespace std;
LL a[200001],ST[1600008] ;

void build_tree(int l,int r,int id)
{
    if(l==r) {ST[id]=a[l] ; return ; }
    int mid=(l+r)/2 ;
    build_tree(l,mid,2*id) ;
    build_tree(mid+1,r,2*id+1) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

void modify(int l,int r,int id,int x,int val)
{
    if(l==r) {ST[id]=val ; return ; }
    int mid=(l+r)/2 ;
    if(x<=mid) modify(l,mid,2*id,x,val) ;
    else modify(mid+1,r,2*id+1,x,val) ;
    ST[id]=max(ST[2*id],ST[2*id+1]) ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return max(query(l,mid,L,mid,2*id),query(mid+1,r,mid+1,R,2*id+1)) ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build_tree(1,n,1) ;
        while(m--)
        {
            char c[5] ; LL x,y ;
            scanf("%s%d%d",c,&x,&y) ;
            if(c[0]=='Q') printf("%d\n",query(x,y,1,n,1)) ;
            else modify(1,n,1,x,y) ;
        }
    }
}
