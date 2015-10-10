#include<bits/stdc++.h>
#define LL long long
using namespace std;

inline LL gcd(LL x,LL y)
{
    return y ? gcd(y,x%y) : x ;
}

struct node2
{
    node2 *l,*r ;
    LL val ;
    node2()
    {
        l=r=NULL ;
        val=0LL ;
    }
};

struct node
{
    node *l,*r ;
    node2 *st ;
    LL val ;
    node()
    {
        l=r=NULL ;
        st=NULL ;
        val=0LL ;
    }
};

inline LL gcd(node *x,node *y)
{
    if(!x) return y?y->val:0 ;
    if(!y) return x->val ;
    return gcd(x->val,y->val) ;
}

inline LL gcd(node2 *x,node2 *y)
{
    if(!x) return y?y->val:0 ;
    if(!y) return x->val ;
    return gcd(x->val,y->val) ;
}

int N,M ;

void modify2(int L,int R,node2 *u,int pos,LL val)
{
    if(L==R) { u->val=val ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid)
    {
        if(!u->l) u->l=new node2 ;
        modify2(L,mid,u->l,pos,val) ;
    }
    else
    {
        if(!u->r) u->r=new node2 ;
        modify2(mid+1,R,u->r,pos,val) ;
    }
    u->val=gcd( u->l?u->l->val:0 , u->r?u->r->val:0 ) ;
}

void maintain(int L,int R,int pos,node2 *u,node2 *ul,node2 *ur)
{
    if(L==R)
    {
        u->val=gcd(ul,ur) ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(pos<=mid)
    {
        if(!u->l) u->l=new node2 ;
        maintain(L,mid,pos,u->l, ul?ul->l:NULL , ur?ur->l:NULL ) ;
        u->val=gcd(ul,ur) ;
    }
    else
    {
        if(!u->r) u->r=new node2 ;
        maintain(mid+1,R,pos,u->r, ul?ul->r:NULL , ur?ur->r:NULL ) ;
        u->val=gcd(ul,ur) ;
    }
}

void modify1(int posx,int posy,int L,int R,node *u,LL val)
{
    if(!u->st) u->st=new node2 ;
    if(L==R) { modify2(0,M-1,u->st,posy,val) ; return ; }
    int mid=(L+R)/2 ;
    if(posx<=mid)
    {
        if(!u->l) u->l=new node ;
        modify1(posx,posy,L,mid,u->l,val) ;
    }
    else
    {
        if(!u->r) u->r=new node ;
        modify1(posx,posy,mid+1,R,u->r,val) ;
    }
    maintain(0,M-1,posy,u->st, u->l?u->l->st:NULL , u->r?u->r->st:NULL ) ;
}

LL query2(int l,int r,int L,int R,node2 *u)
{
    if(!u) return 0LL ;
    if(l==L && r==R) return u->val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query2(l,r,L,mid,u->l) ;
    else if(l>mid) return query2(l,r,mid+1,R,u->r) ;
    else return gcd(query2(l,mid,L,mid,u->l),query2(mid+1,r,mid+1,R,u->r)) ;
}

LL query1(int x1,int x2,int y1,int y2,int L,int R,node *u)
{
    if(!u) return 0LL ;
    if(x1==L && x2==R) return query2(y1,y2,0,M-1,u->st) ;
    int mid=(L+R)/2 ;
    if(x2<=mid) return query1(x1,x2,y1,y2,L,mid,u->l) ;
    else if(x1>mid) return query1(x1,x2,y1,y2,mid+1,R,u->r) ;
    else return gcd(query1(x1,mid,y1,y2,L,mid,u->l),
                    query1(mid+1,x2,y1,y2,mid+1,R,u->r)) ;
}

main()
{
    int Q ; scanf("%d%d%d",&N,&M,&Q) ;
    node *root=new node ;
    while(Q--)
    {
        int type ; scanf("%d",&type) ;
        if(type==1)
        {
            int x,y ; LL val ; scanf("%d%d%I64d",&x,&y,&val) ;
            modify1(x,y,0,N-1,root,val) ;
        }
        else
        {
            int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
            printf("%I64d\n",query1(x1,x2,y1,y2,0,N-1,root)) ;
        }
    }
}
