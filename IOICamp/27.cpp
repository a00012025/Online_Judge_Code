#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l,*r ;
    int val,sum,size,fix ;
    node(int value)
    {
        l=r=NULL ;
        val=sum=value ;
        size=1 ;
        fix=rand() ;
    }
};

struct Treap
{
    inline int size(node *u){ return u ? u->size : 0 ; }
    inline int sum(node *u){ return u ? u->sum : 0 ; }

    void pull(node *u)
    {
        if(u)
            u->sum = sum(u->l)+sum(u->r)+u->val ,
            u->size = size(u->l)+size(u->r)+1 ;
    }

    node *merge(node *a,node *b)
    {
        if(!a || !b) return a?a:b ;
        if(a->fix > b->fix)
        {
            a->r = merge(a->r,b) ;
            pull(a) ;
            return a ;
        }
        else
        {
            b->l = merge(a,b->l) ;
            pull(b) ;
            return b ;
        }
    }

    void split(node *u,int k,node *&a,node *&b)
    {
        if(!u) { a=b=NULL ; return ; }
        if(size(u->l)+1 <= k)
        {
            a=u ;
            split(u->r,k-size(u->l)-1,a->r,b) ;
            pull(a) ;
        }
        else
        {
            b=u ;
            split(u->l,k,a,b->l) ;
            pull(b) ;
        }
    }
}trp;

main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        node *root = NULL ;
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            root=trp.merge(root , new node(x)) ;
        }
        while(m--)
        {
            int x,l,r ; scanf("%d%d%d",&x,&l,&r) ;
            if(x==1)
            {
                node *tl,*t,*tr ;
                trp.split(root,l-1,tl,tr) ;
                trp.split(tr,r-l+1,t,tr) ;
                root = trp.merge( trp.merge(t,tl),tr ) ;
            }
            else
            {
                node *tl,*tr ;
                trp.split(root,l-1,tl,tr) ;
                trp.split(tr,r-l+1,root,tr) ;
                printf("%d\n",root->sum) ;
                root = trp.merge( trp.merge(tl,root),tr ) ;
            }
        }
    }
}
