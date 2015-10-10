#include<bits/stdc++.h>
using namespace std;
const int maxn=524287 ;

struct node
{
    node *l,*r ;
    int val ;
    node()
    {
        l=r=NULL ;
        val=0 ;
    }
};

void build(int l,int r,node *u)
{
    if(l==r) return ;
    u->l = new node ;
    u->r = new node ;
    int mid=(l+r)/2 ;
    build(l,mid,u->l) ;
    build(mid+1,r,u->r) ;
}

void insert(int l,int r,node *oldp,node *newp,int pos)
{
    if(l==r) { newp->val=oldp->val+1 ; return ;  }
    int mid=(l+r)/2 ;
    if(pos<=mid)
    {
        newp->r = oldp->r ;
        newp->l = new node ;
        insert(l,mid,oldp->l,newp->l,pos) ;
    }
    else
    {
        newp->l = oldp->l ;
        newp->r = new node ;
        insert(mid+1,r,oldp->r,newp->r,pos) ;
    }
    newp->val = newp->l->val + newp->r->val ;
}

int query(int l,int r,int L,int R,node *treel,node *treer)
{
    if(l==L && r==R) return treer->val - treel->val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,treel->l,treer->l) ;
    else if(l>mid) return query(l,r,mid+1,R,treel->r,treer->r) ;
    else return query(l,mid,L,mid,treel->l,treer->l)
                +query(mid+1,r,mid+1,R,treel->r,treer->r) ;
}

int kth_small(int L,int R,node *treel,node *treer,int k)
{
    if(L==R) return L ;
    int mid=(L+R)/2 , lnum=treer->l->val - treel->l->val ;
    if(lnum>=k) return kth_small(L,mid,treel->l,treer->l,k) ;
    else return kth_small(mid+1,R,treel->r,treer->r,k-lnum) ;
}

void xorquery(int L,int R,node *treel,node *treer,int x,int &ans)
{
    if(L==R) return ;
    int len=R-L+1 , mid=(L+R)/2 ;
    if(x&(len/2))
    {
        if(treel->l->val == treer->l->val)
        {
            ans+=len/2 ;
            xorquery(mid+1,R,treel->r,treer->r,x,ans) ;
        }
        else xorquery(L,mid,treel->l,treer->l,x,ans) ;
    }
    else
    {
        if(treel->r->val != treer->r->val)
        {
            ans+=len/2 ;
            xorquery(mid+1,R,treel->r,treer->r,x,ans) ;
        }
        else xorquery(L,mid,treel->l,treer->l,x,ans) ;
    }
}

node *root[600000] ;

main()
{
    root[0]=new node ;
    build(0,maxn,root[0]) ;

    int T ;scanf("%d",&T) ;
    int cnt=0 ;
    while(T--)
    {
        int type ; scanf("%d",&type) ;
        if(type==0)
        {
            int x ; scanf("%d",&x) ;
            root[++cnt]=new node ;
            insert(0,maxn,root[cnt-1],root[cnt],x) ;
        }
        else if(type==1)
        {
            int l,r,x ; scanf("%d%d%d",&l,&r,&x) ;
            int ans=0 ;
            xorquery(0,maxn,root[l-1],root[r],x,ans) ;
            printf("%d\n",ans) ;
        }
        else if(type==2)
        {
            int k ; scanf("%d",&k) ;
            cnt-=k ;
        }
        else if(type==3)
        {
            int l,r,x ; scanf("%d%d%d",&l,&r,&x) ;
            printf("%d\n",query(0,x,0,maxn,root[l-1],root[r])) ;
        }
        else if(type==4)
        {
            int l,r,k ; scanf("%d%d%d",&l,&r,&k) ;
            printf("%d\n",kth_small(0,maxn,root[l-1],root[r],k)) ;
        }
    }
}
