#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l,*r ;
    int val,size,pri,inv ;
    node(int v)
    {
        l=r=NULL ;
        val=v ; size=1 ;
        pri=rand() ;
        inv=0 ;
    }
};

void push(node *u)
{
    if(!u || !u->inv) return ;
    swap(u->l,u->r) ;
    u->inv = 0 ;
    if(u->l) u->l->inv ^= 1 ;
    if(u->r) u->r->inv ^= 1 ;
}

inline int size(node *u) { return u ? u->size : 0 ; }
inline void pull(node *u) { if(u) u->size=size(u->l)+size(u->r)+1 ; }

node *merge(node *a,node *b)
{
    if(!a || !b) return a ? a : b ;
    if(a->pri < b->pri)
    {
        push(a) ;
        a->r=merge(a->r,b) ;
        pull(a) ;
        return a ;
    }
    else
    {
        push(b) ;
        b->l=merge(a,b->l) ;
        pull(b) ;
        return b ;
    }
}

void split(node *u,node *&a,node *&b,int k)
{
    if(!u) { a=b=NULL ; return ; }
    push(u) ;
    if(k>=size(u->l)+1)
    {
        a=u ;
        split(u->r,a->r,b,k-size(u->l)-1) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split(u->l,a,b->l,k) ;
        pull(b) ;
    }
}

void print(node *u)
{
    if(!u) return ;
    push(u) ;
    print(u->l) ;
    printf("%d ",u->val) ;
    print(u->r) ;
}

node *root=NULL ;

main()
{
    srand(time(NULL)) ;
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) root=merge(root,new node(i)) ;
    while(Q--)
    {
        char s[20] ; scanf("%s",s) ;
        if(s[0]=='R')
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            node *t1,*t2,*t3 ;
            split(root,t1,t2,l-1) ;
            split(t2,t2,t3,r-l+1) ;
            t2->inv ^= 1 ;
            root=merge(merge(t1,t2),t3) ;
        }
        else
        {
            int a,b,c,d ; scanf("%d%d%d%d",&a,&b,&c,&d) ;
            node *t1,*t2,*t3,*t4,*t5 ;
            split(root,t1,t2,a-1) ;
            split(t2,t2,t3,b-a+1) ;
            split(t3,t3,t4,c-b-1) ;
            split(t4,t4,t5,d-c+1) ;
            root=merge( merge(t1,t4),merge(merge(t3,t2),t5) ) ;
        }
    }

    print(root) ;
}
