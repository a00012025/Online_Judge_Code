#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=50000+10 ;

struct node
{
    node *l,*r ;
    char c ;
    int size ;
    bool inv ;
    node(char cc)
    {
        l=r=NULL ;
        c=cc ;
        size=1 ; inv=0 ;
    }
};

inline int size(node *u){ return u ? u->size : 0 ; }
inline void pull(node *u)
{
    u->size = size(u->l) + size(u->r) + 1 ;
}

node *copy(node *u)
{
    node *p=new node(u->c) ;
    p->l = u->l ;
    p->r = u->r ;
    p->size = u->size ;
    p->inv = u->inv ;
    return p ;
}

char s[maxn] ;
void build(int l,int r,node *&u)
{
    if(l>r) return ;
    if(l==r) { u=new node(s[l]) ; return ; }
    int mid=(l+r)/2 ;
    u=new node(s[mid]) ;
    build(l,mid-1,u->l) ;
    build(mid+1,r,u->r) ;
    pull(u) ;
}

DB randchoice(DB p)
{
    return ((DB)rand())/((DB)RAND_MAX) <= p ;
}

inline void push(node *u)
{
    if(u->inv==0) return ;

    swap(u->l,u->r) ; u->inv=0 ;
    if(u->l)
    {
        u->l = copy(u->l) ;
        u->l->inv ^= 1 ;
    }
    if(u->r)
    {
        u->r = copy(u->r) ;
        u->r->inv ^= 1 ;
    }
}

node *merge(node *a,node *b)
{
    if(!a || !b) return a?a:b ;

    node *p ;
    if(randchoice( ((DB)size(a))/((DB)size(a)+size(b)) ))
    {
        //a=copy(a) ;
        push(a) ;
        p=new node(a->c) ;
        p->l=a->l ;
        p->r=merge(a->r,b) ;
        pull(p) ; return p ;
    }
    else
    {
        //b=copy(b) ;
        push(b) ;
        p=new node(b->c) ;
        p->r=b->r ;
        p->l=merge(a,b->l) ;
        pull(p) ; return p ;
    }
}

void split(node *u,int k,node *&a,node *&b)
{
    if(!u) { a=b=NULL ; return ; }

    //u=copy(u) ;
    push(u) ;
    if(size(u->l)+1 <= k)
    {
        a=new node(u->c) ;
        a->l=u->l ;
        split(u->r,k-size(u->l)-1,a->r,b) ;
        pull(a) ;
    }
    else
    {
        b=new node(u->c) ;
        b->r=u->r ;
        split(u->l,k,a,b->l) ;
        pull(b) ;
    }
}

void print_ans(node *u,bool rot)
{
    if(!u) return ;
    rot  ^= u->inv ;

    if(!rot)
    {
        print_ans(u->l,rot) ;
        putchar(u->c) ;
        print_ans(u->r,rot) ;
    }
    else
    {
        print_ans(u->r,rot) ;
        putchar(u->c) ;
        print_ans(u->l,rot) ;
    }
}

main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d%s",&n,&m,s+1) ;
        node *root=NULL ;
        build(1,n,root) ;
        while(m--)
        {
            int op,l,r ; scanf("%d%d%d",&op,&l,&r) ;
            if(op==1)
            {
                node *t1 , *t2 , *t3 , *t4;
                split(root,r,t1,t2) ;
                split(t1,l-1,t3,t4) ;
                print_ans(t4,0) ; printf("\n") ;
            }
            else if(op==2)
            {
                node *t1 , *t2 , *t3 , *t4;
                split(root,r,t1,t2) ;
                split(t1,l-1,t3,t4) ;
                root=merge( merge(t1,t4),t2 ) ;
            }
            else
            {
                node *t1 , *t2 , *t3 , *t4;
                split(root,r,t1,t2) ;
                split(t1,l-1,t3,t4) ;
                t4->inv=1 ;
                root=merge( merge(t3,t4),t2 ) ;
            }
            //printf("root : ") ; print_ans(root) ; printf("\n") ;
        }
    }
}
