#include<bits/stdc++.h>
using namespace std;

struct node
{
    node *l,*r ;
    int val,pri,size ;
    node(int v)
    {
        l=r=NULL ;
        val=v ; size=1 ;
        pri=rand() ;
    }
};

inline int lsize(node *u) { return u->l ? u->l->size : 0 ; }
inline int rsize(node *u) { return u->r ? u->r->size : 0 ; }
inline int size(node *u) { return u ? u->size : 0 ; }
inline void pull(node *u){ if(u) u->size = lsize(u)+rsize(u)+1 ; }

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

void split(node *u,node *&a,node *&b,int value)
{
    if(!u) { a=b=NULL ; return ; }
    if(u->val <= value)
    {
        a=u ;
        split(u->r,a->r,b,value) ;
        pull(a) ;
    }
    else
    {
        b=u ;
        split(u->l,a,b->l,value) ;
        pull(b) ;
    }
}

int getmax(node *u)
{
    return u->r ? getmax(u->r) : u->val ;
}

node *root ;
void insert(int x)
{
    node *a,*b ;
    split(root,a,b,x) ;
    if(a && getmax(a)==x) root=merge(a,b) ;
    else root= merge( merge(a,new node(x)) , b ) ;
}

void erase(node *&u,int value)
{
    if(!u) return ;
    if(u->val==value) u=merge(u->l,u->r) ;
    else if(u->val>value) erase(u->l,value) ;
    else erase(u->r,value) ;
    pull(u) ;
}

int kth(node *u,int k)
{
    if(lsize(u)+1==k) return u->val ;
    else if(lsize(u)+1>k) return kth(u->l,k) ;
    else return kth(u->r,k-lsize(u)-1) ;
}

main()
{
    srand(time(NULL)) ;
    root=NULL ;
    char s[100] ;
    int x ;
    while(scanf("%s%d",s,&x)!=EOF)
    {
        if(s[0]=='e') break ;
        if(s[0]=='i') insert(x) ;
        if(s[0]=='a')
        {
            if(x<1 || x>size(root)) printf("error\n") ;
            else printf("%d\n",kth(root,x)) ;
        }
        if(s[0]=='r') erase(root,x) ;
    }
}
