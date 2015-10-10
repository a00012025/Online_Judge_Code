#include<bits/stdc++.h>
#define DB double
using namespace std;
struct node
{
    node *l,*r ;
    int val,size ;
    bool flip ;
    node()
    {
        l=r=NULL ;
        size=1 ; flip=0 ;
    }
    int lsize(){ return l ? l->size : 0 ; }
    int rsize(){ return r ? r->size : 0 ; }
};

void pushdown(node *a)
{
    if(a==NULL) return ;
    if(a->flip)
    {
        swap(a->l,a->r) ;
        if(a->l!=NULL) a->l->flip = !(a->l->flip) ;
        if(a->r!=NULL) a->r->flip = !(a->r->flip) ;
        a->flip=0 ;
    }
}

struct Treap
{
    void maintain(node *u) { u->size=u->lsize()+u->rsize()+1 ; }

    void build(node *&u,int l,int r)
    {
        if(l>r) return ;
        u=new node ;
        if(l==r) {u->val=l ;  return ;}
        int mid=(l+r)/2 ;
        u->val=mid ;
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
        pushdown(a) ; pushdown(b) ;
        if(randchoice(((DB)a->size)/((DB)a->size+b->size)))
        {
            p->val=a->val ;
            p->l=a->l ;
            p->r=merge(a->r,b) ;
            maintain(p) ;
        }
        else
        {
            p->val=b->val ;
            p->r=b->r ;
            p->l=merge(a,b->l) ;
            maintain(p) ;
        }
        return p ;
    }

    void split(node *u,int sz,node *&a,node *&b)
    {
        if(!u) {a=b=NULL ; return ; }
        pushdown(u) ;
        node *p=new node ; p->val=u->val ;
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
    if(u==NULL) return ;
    pushdown(u) ;
    print_ans(u->l) ;
    printf("%d\n",u->val) ;
    print_ans(u->r) ;
}

Treap trp ;
main()
{
        freopen("1.txt","r",stdin) ;
        freopen("2.txt","w",stdout) ;
    int n,m ; scanf("%d%d",&n,&m) ;
    node *root ;
    trp.build(root,1,n) ;
    while(m--)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        node *rt1,*rt2,*rt3 ;
        trp.split(root,l-1,rt1,rt2) ;
        trp.split(rt2,r-l+1,rt2,rt3) ;
        rt2->flip=1 ;
        root=trp.merge(rt1,rt3) ;
        root=trp.merge(root,rt2) ;
    }
    print_ans(root) ;
}
