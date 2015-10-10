#include<bits/stdc++.h>
#define LL long long
#define VAL(u) ((u)?((u)->val):0LL)
using namespace std;

struct node2
{
    node2 *l,*r ;
    LL val ;
    int tag ;
    node2()
    {
        l=r=NULL ;
        val=0LL ;
        tag=-1 ;
    }
    node2(int _tag,LL _val)
    {
        l=r=NULL ;
        val=_val ;
        tag=_tag ;
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

int N,M ;

void push(int L,int R,node2 *u)
{
    if(!u || u->tag<0) return ;
    int mid=(L+R)/2 ;
    if(u->tag <= mid) u->l=new node2(u->tag,u->val) ;
    else u->r=new node2(u->tag,u->val) ;
    u->tag=-2 ;
}

void modify2(int L,int R,node2 *u,int pos,LL val)
{
    if(u->tag==-1 || L==R) { u->tag=pos ; u->val=val ; return ; }
    if(u->tag>=0 && pos==u->tag) { u->val=val ; return ; }

    push(L,R,u) ;
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
    u->val = __gcd(VAL(u->l),VAL(u->r)) ;
}

LL query2(int l,int r,int L,int R,node2 *u)
{
    if(!u) return 0LL ;
    if(l==L && r==R) return u->val ;
    if(u->tag >= 0)
    {
        if(l<=u->tag && r>=u->tag) return u->val ;
        else return 0LL ;
    }
    int mid=(L+R)/2 ;
    if(r<=mid) return query2(l,r,L,mid,u->l) ;
    else if(l>mid) return query2(l,r,mid+1,R,u->r) ;
    else return __gcd(query2(l,mid,L,mid,u->l),query2(mid+1,r,mid+1,R,u->r)) ;
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

    if(u->l && u->r) modify2(0,M-1,u->st,posy,
            __gcd( query2(posy,posy,0,M-1,u->l->st) ,
                    query2(posy,posy,0,M-1,u->r->st) ) ) ;
    else if(u->l)
        modify2(0,M-1,u->st,posy,query2(posy,posy,0,M-1,u->l->st)) ;
    else if(u->r)
        modify2(0,M-1,u->st,posy,query2(posy,posy,0,M-1,u->r->st)) ;
}

LL query1(int x1,int x2,int y1,int y2,int L,int R,node *u)
{
    if(!u) return 0LL ;
    if(x1==L && x2==R) return query2(y1,y2,0,M-1,u->st) ;
    int mid=(L+R)/2 ;
    if(x2<=mid) return query1(x1,x2,y1,y2,L,mid,u->l) ;
    else if(x1>mid) return query1(x1,x2,y1,y2,mid+1,R,u->r) ;
    else return __gcd(query1(x1,mid,y1,y2,L,mid,u->l),
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
            int x,y ; LL val ; scanf("%d%d%lld",&x,&y,&val) ;
            modify1(x,y,0,N-1,root,val) ;
        }
        else
        {
            int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
            printf("%lld\n",query1(x1,x2,y1,y2,0,N-1,root)) ;
        }
    }
}
