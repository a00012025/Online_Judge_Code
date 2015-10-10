#include<bits/stdc++.h>
#define LL long long
#define VAL(u) ((u)?((u)->val):0LL)
using namespace std;

struct node2
{
    node2 *l,*r ;
    int key,pri ;
    LL gcd,val ;
    node2(int _key,LL _v)
    {
        l=r=NULL ;
        val=gcd=_v ;
        key=_key ;
        pri=rand() ;
    }
};

inline LL gcd(node2 *u) { return u ? u->gcd : 0LL ; }
inline void pull(node2 *u)
{ if(u) u->gcd= __gcd(u->val,__gcd(gcd(u->l),gcd(u->r))) ; }
node2 *merge(node2 *a,node2 *b)
{
    if(!a || !b) return a ? a : b ;
    if(a->pri < b->pri)
    {
        a->r = merge(a->r,b) ;
        pull(a) ;
        return a ;
    }
    else
    {
        b->l=merge(a,b->l) ;
        pull(b) ;
        return b ;
    }
}

inline void split(node2 *u,node2 *&a,node2 *&b,int k)
{
    if(!u) { a=b=NULL ; return ; }
    if(u->key <= k)
    {
        a=u ;
        split(u->r,a->r,b,k) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split(u->l,a,b->l,k) ;
        pull(b) ;
    }
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

int N,M ;

inline bool find_max(node2 *u,int k,LL val)
{
    if(!u) return 0 ;
    if(u->key == k) { u->val=u->gcd=val ; return 1 ; }

    bool res=find_max(u->r,k,val ) ;
    if(res) pull(u) ;
    return res ;
}

inline void modify2(node2 *&u,int x,LL val)
{
    node2 *rt1,*rt2,*rt3 ;
    split(u,rt1,rt2,x-1) ;
    split(rt2,rt2,rt3,x) ;
    u=merge(merge(rt1,new node2(x,val)),rt3) ;
}

inline LL query2(int l,int r,node2 *&u)
{
    if(l==r)
    {
        if(!u) return 0LL ;
        if(u->key==l) return u->val ;
        return u->key>l ? query2(l,r,u->l) : query2(l,r,u->r) ;
    }
    node2 *rt1,*rt2,*rt3 ;
    split(u,rt1,rt2,l-1) ;
    split(rt2,rt2,rt3,r) ;
    LL ret=gcd(rt2) ;
    u=merge(merge(rt1,rt2),rt3) ;
    return ret ;
}

inline void modify1(int posx,int posy,int L,int R,node *u,LL val)
{
//    if(!u->st) u->st=new node2 ;
    if(L==R) { modify2(u->st,posy,val) ; return ; }
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

    if(u->l && u->r) modify2(u->st,posy,
            __gcd( query2(posy,posy,u->l->st) ,
                    query2(posy,posy,u->r->st) ) ) ;
    else if(u->l)
        modify2(u->st,posy,query2(posy,posy,u->l->st)) ;
    else if(u->r)
        modify2(u->st,posy,query2(posy,posy,u->r->st)) ;
}

inline LL query1(int x1,int x2,int y1,int y2,int L,int R,node *u)
{
    if(!u) return 0LL ;
    if(x1==L && x2==R) return query2(y1,y2,u->st) ;
    int mid=(L+R)/2 ;
    if(x2<=mid) return query1(x1,x2,y1,y2,L,mid,u->l) ;
    else if(x1>mid) return query1(x1,x2,y1,y2,mid+1,R,u->r) ;
    else return __gcd(query1(x1,mid,y1,y2,L,mid,u->l),
                    query1(mid+1,x2,y1,y2,mid+1,R,u->r)) ;
}

main()
{
    srand(time(NULL)) ;

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
