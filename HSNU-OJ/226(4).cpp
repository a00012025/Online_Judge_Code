#include<bits/stdc++.h>
#define DB double

#ifndef REFERENCE_POINTER
#define REFERENCE_POINTER
template<typename T>
struct _RefCounter{
	T data;
	int ref;
	_RefCounter(const T&d=0):data(d),ref(0){}
};
template<typename T>
struct reference_pointer{
	_RefCounter<T> *p;
	T *operator->(){return &(*p).data;}
	T &operator*(){return p->data;}
	operator int(){return(int)(long long)p;}
	reference_pointer&operator=(const reference_pointer &t){
		if(p&&--(*p).ref==0)delete p;
		p=t.p;
		p&&(*p).ref++;
		return*this;
	}
	reference_pointer(_RefCounter<T> *t=0):p(t){
		p&&(*p).ref++;
	}
	reference_pointer(const reference_pointer &t):p(t.p){
		p&&(*p).ref++;
	}
	~reference_pointer(){
		if(p&&--(*p).ref==0)delete p;
	}
};
template<typename T,typename... _Args>
inline reference_pointer<T>
new_reference(_Args... __args){
	return reference_pointer<T>
	(new _RefCounter<T>(T(__args)...));
}
#endif
using namespace std;
struct node ;
typedef reference_pointer<node> pt;

char s[1000100] ;
struct node
{
    pt l,r ;
    int size,fix ;
    char c ;
    node()
    {
        l=r=NULL ;
        size=1 ;
    }
    node(const node&t):size(t.size),l(t.l),r(t.r),c(t.c){}
	node(const char &d){
		size=1;
		c=d;
	}
    int lsize(){ return l ? l->size : 0 ; }
    int rsize(){ return r ? r->size : 0 ; }
};

struct Treap
{
    void maintain(pt u) { u->size=u->lsize()+u->rsize()+1 ; }

    void build(pt &u,int l,int r)
    {
        if(l>r) return ;
        u=new_reference<node>() ;
        if(l==r) {u->c=s[l] ; return ;}
        int mid=(l+r)/2 ;
        u->c=s[mid] ;
        build(u->l,l,mid-1) ;
        build(u->r,mid+1,r) ;
        maintain(u) ;
    }

    pt merge(pt a,pt b)
    {
        if(!a) return b ;
        if(!b) return a ;
        pt p=new_reference<node>() ;
        static int x ;
        if(x++%(a->size+b->size)<a->size)
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

    void split(pt u,int sz,pt &a,pt &b)
    {
        if(!u) {a=b=NULL ; return ; }
        pt p=new_reference<node>() ; p->c=u->c ;
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

void print_ans(pt u)
{
    if(!u) return ;
    print_ans(u->l) ;
    putchar(u->c) ;
    print_ans(u->r) ;
}

node *root ;
Treap trp ;
main()
{
    int m,Q ; scanf("%d%s%d",&m,s,&Q) ;
    pt root ;
    trp.build(root,0,strlen(s)-1) ;

    while(Q--)
    {
        int l,r,t ; scanf("%d%d%d",&l,&r,&t) ;
        pt rt1,rt2,rt3,rt4,rt5 ;
        trp.split(root,l,rt1,rt2) ;
        trp.split(rt2,r-l+1,rt2,rt3) ;
        trp.split(root,t,rt4,rt5) ;
        root=trp.merge(rt4,rt2) ;
        root=trp.merge(root,rt5) ;
        if(root->size > m) trp.split(root,m,root,rt5) ;
    }
    print_ans(root) ; printf("\n") ;
}
