#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l,*r ;
    int val,size,pri ;
    node(int value)
    {
        l=r=NULL ;
        val=value ;
        size=1 ;
        pri=rand() ;
    }
};

inline int size(node *u) { return u ? u->size : 0 ; }
void pull(node *u) { if(u) u->size=1+size(u->l)+size(u->r) ; }

node *merge(node *a,node *b)
{
    if(!a || !b) return a ? a : b ;
    if(a->pri < b->pri)
    {
        a->r=merge(a->r,b) ;
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

void split(node *u,node *&a,node *&b,int k)
{
    if(!u) { a=b=NULL ; return ; }
    if(u->val <= k)
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

node *root ;
void insert(int x)
{
    node *a,*b ;
    split(root,a,b,x) ;
    root=merge(merge(a,new node(x)),b) ;
}

int kth(node *u,int k)
{
    if(k==size(u->l)+1) return u->val ;
    else if(k<size(u->l)+1) return kth(u->l,k) ;
    else return kth(u->r,k-size(u->l)-1) ;
}

main()
{
    srand(time(NULL)) ;
    while(1)
    {
        root=NULL ;
        char ch[10] ;
        int num=0 ;
        while(scanf("%s",ch)!=EOF)
        {
            if(ch[1]=='N') return 0 ;
            else if(ch[1]=='X') break ;
            if(ch[0]=='P')
            {
                int x ; scanf("%d",&x) ;
                insert(x) ;
            }
            else if(size(root)>=num+1)
                printf("%d\n",kth(root,num+1)) , num++ ;
        }
    }
}
