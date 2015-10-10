#include<bits/stdc++.h>
#define LL long long
#define VAL(x) ((x)?(x->val):(0))
using namespace std;

struct node2
{
    node2 *l,*r ;
    LL val ;
    int tag ;
    node2(LL _v)
    {
        l=r=NULL ;
        val=_v ;
        tag=-1 ;
    }
};

void push(int L,int R,node2 *u)
{
    if(u->tag < 0 || L==R) return ;
    int mid=(L+R)/2 ;
    if(u->tag <= mid)
    {
        u->l = new node2(u->val) ;
        u->l->tag = u->tag ;
    }
    else
    {
        u->r = new node2(u->val) ;
        u->r->tag = u->tag ;
    }
    u->tag = -2 ;
}

void modify2(int L,int R,node2 *u,int pos,LL val)
{
    if(u->tag==-1 || (u->tag>=0 && u->tag==pos))
    {
        u->tag=pos ;
        u->val=val ;
        return ;
    }
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(pos<=mid)
    {
        if(!u->l) u->l=new node2(0) ;
        modify2(L,mid,u->l,pos,val) ;
    }
    else
    {
        if(!u->r) u->r=new node2(0) ;
        modify2(mid+1,R,u->r,pos,val) ;
    }
    u->val=__gcd(VAL(u->l),VAL(u->r)) ;
}

LL query2(int l,int r,int L,int R,node2 *u)
{
    if(!u) return 0 ;
    if(l==L && r==R) return u->val ;
    if(u->tag>=0) return ( u->tag>=l && u->tag<=r ) ? u->val : 0 ;

    int mid=(L+R)/2 ;
    if(r<=mid) return query2(l,r,L,mid,u->l) ;
    else if(l>mid) return query2(l,r,mid+1,R,u->r) ;
    else return __gcd(query2(l,mid,L,mid,u->l),query2(mid+1,r,mid+1,R,u->r)) ;
}

struct node
{
    node *l,*r ;
    node2 *st ;
    node()
    {
        l=r=NULL ;
        st=NULL ;
    }
};

int R,C ;

void modify1(int L,int R,node *u,int posx,int posy,LL val)
{
    if(!u->st) u->st=new node2(0) ;
    if(L==R)
    {
        modify2(0,C-1,u->st,posy,val) ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(posx<=mid)
    {
        if(!u->l) u->l=new node ;
        modify1(L,mid,u->l,posx,posy,val) ;
    }
    else
    {
        if(!u->r) u->r=new node ;
        modify1(mid+1,R,u->r,posx,posy,val) ;
    }

    LL tmp=0 ;
    if(u->l) tmp=__gcd(tmp,query2(posy,posy,0,C-1,u->l->st)) ;
    if(u->r) tmp=__gcd(tmp,query2(posy,posy,0,C-1,u->r->st)) ;
    modify2(0,C-1,u->st,posy,tmp) ;
}

LL query1(int x1,int x2,int y1,int y2,int L,int R,node *u)
{
    if(!u) return 0 ;
    if(x1==L && x2==R) return query2(y1,y2,0,C-1,u->st) ;
    int mid=(L+R)/2 ;
    if(x2<=mid) return query1(x1,x2,y1,y2,L,mid,u->l) ;
    else if(x1>mid) return query1(x1,x2,y1,y2,mid+1,R,u->r) ;
    else return __gcd(query1(x1,mid,y1,y2,L,mid,u->l),
                      query1(mid+1,x2,y1,y2,mid+1,R,u->r)) ;
}

node *root ;
main()
{
    int Q ; scanf("%d%d%d",&R,&C,&Q) ;
    root=new node ;
    while(Q--)
    {
        int t ; scanf("%d",&t) ;
        if(t==1)
        {
            int x,y ; LL val ;
            scanf("%d%d%lld",&x,&y,&val) ;
            modify1(0,R-1,root,x,y,val) ;
        }
        else
        {
            int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
            printf("%lld\n",query1(x1,x2,y1,y2,0,R-1,root)) ;
        }
    }
}
