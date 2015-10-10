#include<bits/stdc++.h>
#define DB double
using namespace std;
struct node
{
    node *l,*r ;
    int size ;
    char c ;
    node()
    {
        l=r=NULL ;
        size=1 ;
    }
    int lsize(){ return l ? l->size : 0 ; }
    int rsize(){ return r ? r->size : 0 ; }
};

char s[1000100] ;
struct Treap
{
    void maintain(node *u) { u->size=u->lsize()+u->rsize()+1 ; }

    void build(node *&u,int l,int r)
    {
        if(l>r) return ;
        u=new node ;
        if(l==r) {u->c=s[l] ;  return ;}
        int mid=(l+r)/2 ;
        u->c=s[mid] ;
        build(u->l,l,mid-1) ;
        build(u->r,mid+1,r) ;
        maintain(u) ;
    }

    void remove(node *u)
    {
        if(u==NULL) return ;
        remove(u->l) ;
        remove(u->r) ;
        delete u ;
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
        if(randchoice(((DB)a->size)/(a->size+b->size)))
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

    void split(node *u,int sz,node *&a,node *&b)
    {
        if(!u) {a=b=NULL ; return ; }
        node *p=new node ; p->c=u->c ;
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

int c_num=0 ;
void print_ans(node *u)
{
    if(u==NULL) return ;
    print_ans(u->l) ;
    printf("%c",u->c) ; if(u->c == 'c') c_num++ ;
    print_ans(u->r) ;
}

Treap trp ;
node *root[60001] ;
main()
{
    int n ; scanf("%d",&n) ;
    root[0]=new node ;
    int nowv=0 ;
    for(int i=1;i<=n;i++)
    {
        int tp ; scanf("%d",&tp) ;
        if(tp==1)
        {
            nowv++ ;
            int pos ; scanf("%d%s",&pos,s) ; pos-=c_num ;
            node *rt2 ; trp.build(rt2,0,strlen(s)-1) ;
            if(i==1) {root[nowv]=rt2 ; continue ; }
            node *rt1,*rt3 ; trp.split(root[nowv-1],pos,rt1,rt3) ;
            root[nowv]=trp.merge(rt1,rt2) ;
            root[nowv]=trp.merge(root[nowv],rt3) ;
                //print_ans(root[nowv]) ; printf("\n") ;
        }
        else if(tp==2)
        {
            nowv++ ;
            int pos,len ; scanf("%d%d",&pos,&len) ;
            pos-=c_num ; len-=c_num ;
            node *rt1,*rt2,*tmp ;
            trp.split(root[nowv-1],pos-1,rt1,rt2) ;
            trp.split(rt2,len,tmp,rt2) ;
            root[nowv]=trp.merge(rt1,rt2) ;
                //print_ans(root[nowv]) ; printf("\n") ;
        }
        else
        {
            int v,pos,len ; scanf("%d%d%d",&v,&pos,&len) ;
            v-=c_num ; pos-=c_num ; len-=c_num ;
            node *rt1,*rt2,*rt3 ;
            trp.split(root[v],pos-1,rt1,rt2) ;
            trp.split(rt2,len,rt2,rt3) ;
            print_ans(rt2) ; printf("\n") ;
        }
    }
}
