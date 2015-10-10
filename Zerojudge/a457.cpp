#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct P{int x,y;};
bool cmp(P p,P q)
{
    if(p.x!=q.x) return p.x<q.x ;
    return p.y<q.y ;
}

struct node
{
    node *l,*r ;
    int val,size,fix,weight ;
    node()
    {
        l=r=NULL ;
        size=weight=1 ; fix=rand() ;
    }
};

struct Treap
{
    inline int lsize(node *u) {return u->l ? u->l->size : 0 ; }
    inline int rsize(node *u) {return u->r ? u->r->size : 0 ; }
    void maintain(node *u) { u->size = lsize(u)+rsize(u)+u->weight ; }

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

    int insert(node *&u,int value)
    {
        if(!u) { u=new node , u->val=value ; return 0 ; }
        if(u->val > value)
        {
            int ret=u->weight + rsize(u) + insert(u->l,value) ;
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
        else
        {
            u->weight++ ; maintain(u) ;
            return rsize(u) ;
        }
    }
};

Treap trp ;
P a[100010] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].x) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].y) ;
    sort(a+1,a+n+1,cmp) ;
    LL ans=0LL ;
    node *root=NULL ;
    for(int i=1;i<=n;i++) ans+=trp.insert(root,a[i].y) ;
    printf("%lld\n",ans) ;
}
