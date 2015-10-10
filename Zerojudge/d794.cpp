#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct node
{
    node *l,*r ;
    LL val ; int size,fix ;
    node(LL v)
    {
        l=r=NULL ;
        val=v ; size=1 ; fix=rand() ;
    }
};

struct Treap
{
    inline int lsize(node *u) {return u->l ? u->l->size : 0 ;}
    inline int rsize(node *u) {return u->r ? u->r->size : 0 ;}
    void maintain(node *u) {u->size = lsize(u)+rsize(u)+1 ; }

    void left_rotate(node *&u)
    {
        node *v=u->r ;
        u->r=v->l ;
        v->l=u ;
        u=v ; v=u->l ;
        maintain(v) ; maintain(u) ;
    }

    void right_rotate(node *&u)
    {
        node *v=u->l ;
        u->l=v->r ;
        v->r=u ;
        u=v ; v=u->r ;
        maintain(v) ; maintain(u) ;
    }

    int insert(node *&u,LL value)
    {
        if(!u) { u=new node(value) ; return 0 ; }
        if(u->val > value)
        {
            int ret=insert(u->l,value)+rsize(u)+1 ;
            maintain(u) ;
            if(u->l->fix < u->fix) right_rotate(u) ;
            return ret ;
        }
        else if(u->val < value)
        {
            int ret=insert(u->r,value) ;
            maintain(u) ;
            if(u->r->fix < u->fix) left_rotate(u) ;
            return ret ;
        }
    }
};

Treap trp ;
main()
{
    srand(time(NULL)) ;
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        node *root=NULL ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%lld",&x) ;
            printf("%d\n",trp.insert(root,x)+1) ;
        }
    }
}
