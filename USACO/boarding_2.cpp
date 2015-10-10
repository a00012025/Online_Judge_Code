#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

struct node
{
    node *l,*r ;
    int x,y ;
    int val,tag,fix ;
    node(int _x,int _y)
    {
        l=r=NULL ;
        x=_x ; y=_y ;
        val=y ;
        tag=0 ;
        fix=rand() ;
    }
};

void push(node *u)
{
    if(!u || !u->tag) return ;
    if(u->l)
    {
        u->l->x -= u->tag ;
        u->l->y += u->tag ;
        u->l->tag += u->tag ;
        u->l->val += u->tag ;
    }
    if(u->r)
    {
        u->r->x -= u->tag ;
        u->r->y += u->tag ;
        u->r->tag += u->tag ;
        u->r->val += u->tag ;
    }
    u->tag=0 ;
}

void pull(node *u)
{
    if(!u) return ;
    u->val=u->y ;
    if(u->l) u->val=max(u->val,u->l->val) ;
    if(u->r) u->val=max(u->val,u->r->val) ;
}

node *merge(node *a,node *b)
{
    if(!a || !b) return a ? a : b ;
    if(a->fix < b->fix)
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
    if(u->x <= k)
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

void split2(node *u,node *&a,node *&b,int k)
{
    if(!u) { a=b=NULL ; return ; }
    push(u) ;
    if(u->y <= k)
    {
        a=u ;
        split2(u->r,a->r,b,k) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split2(u->l,a,b->l,k) ;
        pull(b) ;
    }
}

int p[maxn],t[maxn],n ;
node *root=NULL ;
main()
{
    if(fopen("boarding.in","r"))
    {
        freopen("boarding.in","r",stdin);
        freopen("boarding.out","w",stdout);
    }
    srand(time(NULL)) ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&t[i]) ;

    int ans=0 ;
    root=merge(root,new node(0,0)) ;
    for(int i=n;i>=1;i--)
    {
        node *a,*b,*c ;
        split(root,a,b,p[i]) ;
        int val=a->val+p[i]+t[i] ;
        ans=max(ans,val) ;
        a->tag++ ; a->x-- ; a->y++ ; a->val++ ;
        split2(b,b,c,val+1-p[i]) ;
        root=merge(merge(a,new node(p[i],val+1-p[i])),c) ;
    }
    printf("%d\n",ans) ;
}
