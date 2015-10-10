#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int val ;
    node(int v)
    {
        val=v ;
        l=r=NULL ;
    }
};

node *build(int L,int R)
{
    if(L==R) return ( new node(0) ) ;
    int mid=(L+R)/2 ;
    node *u=new node(0) ;
    u->l = build(L,mid) ;
    u->r = build(mid+1,R) ;
    return u ;
}

node *modify(int L,int R,node *u,int pos)
{
    if(L==R) return ( new node( u->val+1 ) ) ;
    int mid=(L+R)/2 ;
    node *v=new node(0) ;
    if(pos<=mid)
    {
        v->r = u->r ;
        v->l = modify(L,mid,u->l,pos) ;
    }
    else
    {
        v->l = u->l ;
        v->r = modify(mid+1,R,u->r,pos) ;
    }
    v->val = v->l->val + v->r->val ;
    return v ;
}

int query(int l,int r,int L,int R,node *u1,node *u2)
{
    if(l==L && r==R) return (u2->val - u1->val) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u1->l,u2->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u1->r,u2->r) ;
    else return query(l,mid,L,mid,u1->l,u2->l) +
                query(mid+1,r,mid+1,R,u1->r,u2->r) ;
}

node *root[maxn] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    root[0]=build(1,n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        root[i]=modify(1,n,root[i-1],x) ;
    }
    while(Q--)
    {
        int p,k ; scanf("%d%d",&p,&k) ; p++ ;
        int l=0 , r=n ;
        while(r-l>1)
        {
            int mid=(l+r)/2 , lo=max(1,p-mid) , hi=min(n,p+mid) ;
            if( query(1,mid,1,n,root[lo-1],root[hi]) >= k) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
