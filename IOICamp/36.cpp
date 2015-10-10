#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

struct node
{
    node *l,*r ;
    int val,big,fix,size ;
    node(int value)
    {
        l=r=NULL ;
        val=big=value ;
        size=1 ;
        fix=rand() ;
    }
};

inline int size(node *u){ return u ? u->size : 0 ; }
inline int big(node *u){ return u ? u->big : -INF ; }
void pull(node *u)
{
    if(u)
        u->big = max(u->val,max(big(u->l),big(u->r))) ,
        u->size = size(u->l) + size(u->r) + 1 ;
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

main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        node *root=NULL ;
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            root= merge(root,new node(x)) ;
        }
        while(m--)
        {
            int tp,x,y ; scanf("%d%d%d",&tp,&x,&y) ;
            if(tp==1)
            {
                node *tl,*tr ;
                split(root,x-1,tl,tr) ;
                split(tr,y-x+1,root,tr) ;
                printf("%d\n",root->big) ;
                root=merge( merge(tl,root),tr ) ;
            }
            else
            {
                node *tl,*tr ;
                split(root,x-1,tl,tr) ;
                split(tr,1,root,tr) ;
                root->val = root->big = y+root->val ;
                root=merge( merge(tl,root),tr ) ;
            }
        }
    }
}
