#include<bits/stdc++.h>
#define DB double
using namespace std;
struct node ;
struct ptr
{
    node *p ;
    ptr(const ptr &t) ;
    ptr(node *t) ;
    ~ptr() ;
};
struct node
{
    ptr l,r ;
    int size,di ;
    char c ;
    node()
    {
        l=r=(ptr){NULL} ;
        di=0 ; size=1 ;
    }
    node(const node &t)
    {
        l=t.l ; r=t.r ; c=t.c ;
        di=0 ; size=1 ;
    }
    int lsize(){ return l.p ? l.p->size : 0 ; }
    int rsize(){ return r.p ? r.p->size : 0 ; }
};

ptr::ptr(const ptr &t)
{
    t.p->di++ ;
    p=t.p ;
}

ptr::ptr(node *t)
{
    t->di++ ;
    p=t ;
}

ptr::~ptr()
{
    if(p && --p->di==0) delete p ;
}

char s[1000100] ;
struct Treap
{
    void maintain(node *u) { u->size=u->lsize()+u->rsize()+1 ; }

    void build(node *&u,int l,int r)
    {
        if(l>r) return ;
        u=new node ;
        if(l==r) {u->c=s[l] ; return ;}
        int mid=(l+r)/2 ;
        u->c=s[mid] ;
        build(u->l,l,mid-1) ;
        build(u->r,mid+1,r) ;
        maintain(u) ;
    }

    bool randchoice(DB p)
    {
        return ((DB)rand())/((DB)RAND_MAX) <= p ;
    }

    node *merge(node *a,node *b)
    {
        if(!a) return b ;
        if(!b) return a ;
        node *p=new node ;
        if(randchoice(((DB)a->size)/(a->size+b->size)))
        {
            p->c=a->c ;
            p->l=a->l ;
            p->r=merge(a->r,b) ;
            maintain(p) ;
        }
        else
        {
            p->c=b->c ;
            p->r=b->r ;
            p->l=merge(a,b->l) ;
            maintain(p) ;
        }
        return p ;
    }

    void split(node *u,int sz,node *&a,node *&b)
    {
        if(!u) {a=b=NULL ; return ; }
        node *p=new node ; p->c=u->c ;
        if(sz >= u->lsize()+1)
        {
            split(u->r,sz-u->lsize()-1,a,b) ;
            p->l=u->l ; p->r=a ;
            maintain(p) ;
            a=p ;
        }
        else
        {
            split(u->l,sz,a,b) ;
            p->l=b ; p->r=u->r ;
            maintain(p) ;
            b=p ;
        }
    }
};

void print_ans(node *u)
{
    if(!u) return ;
    print_ans(u->l) ;
    printf("%c",u->c) ;
    print_ans(u->r) ;
}

Treap trp ;
main()
{
    int m,Q ; scanf("%d%s%d",&m,s,&Q) ;

    node *root ;
    trp.build(root,0,strlen(s)-1) ;
    //print_ans(root) ;
    while(Q--)
    {
        int l,r,t ; scanf("%d%d%d",&l,&r,&t) ;
        node *rt1,*rt2,*rt3,*rt4,*rt5 ;
        trp.split(root,l,rt1,rt2) ;
        trp.split(rt2,r-l+1,rt2,rt3) ;
        trp.split(root,t,rt4,rt5) ;
        root=trp.merge(rt4,rt2) ;
        root=trp.merge(root,rt5) ;
        if(root->size > m) trp.split(root,m,root,rt5) ;
        //trp.remove(rt1) ; trp.remove(rt3) ;
    }
    print_ans(root) ; printf("\n") ;
}

