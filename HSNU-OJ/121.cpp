#include<bits/stdc++.h>
#include"interactive/121.h"
using namespace std;
struct node
{
    node *l,*r ;
    int x ;
};

void build(int l,int r,node *u)
{
    if(l==r) { u->x=l ; return ; }
    int mid=(l+r)/2 ;
    u->l=new node ;
    u->r=new node ;
    build(l,mid,u->l) ;
    build(mid+1,r,u->r) ;
}

void modify(int l,int r,node *oldp,node *newp,int x1,int val1,int x2,int val2)
{
    if(l==r)
    {
        if(x1==l) newp->x = oldp->x+val1 ;
        else newp->x = oldp->x+val2 ;
        return ;
    }
    int mid=(l+r)/2 ;
    if(x1<=mid && x1>=l && x2<=mid && x2>=l)
    {
        newp->r = oldp->r ;
        newp->l = new node ;
        modify(l,mid,oldp->l,newp->l,x1,val1,x2,val2) ;
    }
    else if(x1>mid && x1<=r && x2>mid && x2<=r)
    {
        newp->l = oldp->l ;
        newp->r = new node ;
        modify(mid+1,r,oldp->r,newp->r,x1,val1,x2,val2) ;
    }
    else if((x1>=l && x1<=mid && x2>mid && x2<=r) || (x2>=l && x2<=mid && x1>mid && x1<=r))
    {
        newp->l = new node ;
        modify(l,mid,oldp->l,newp->l,x1,val1,x2,val2) ;
        newp->r = new node ;
        modify(mid+1,r,oldp->r,newp->r,x1,val1,x2,val2) ;
    }
    else if((x1>=l && x1<=mid) || (x2>=l && x2<=mid))
    {
        newp->r = oldp->r ;
        newp->l = new node ;
        modify(l,mid,oldp->l,newp->l,x1,val1,x2,val2) ;
    }
    else if((x1>mid && x1<=r) || (x2>mid && x2<=r))
    {
        newp->l = oldp->l ;
        newp->r = new node ;
        modify(mid+1,r,oldp->r,newp->r,x1,val1,x2,val2) ;
    }
}

int query(int l,int r,node *u,int x)
{
    if(l==r) return u->x ;
    int mid=(l+r)/2 ;
    if(x<=mid) return query(l,mid,u->l,x) ;
    else return query(mid+1,r,u->r,x) ;
}

node *root[300010] ;
int pos[300010],now[300010] ;
main()
{
    int n,m,Q ;
    Init(n,m,pos) ;
    for(int i=1;i<=n;i++) now[i]=i ;

    root[0]=new node ;
    build(1,n,root[0]) ;
    for(int i=1;i<=m;i++)
    {
        int p1=now[pos[i]] , p2=now[pos[i]+1] ; /// which number
        root[i]=new node ;
        modify(1,n,root[i-1],root[i],p1,1,p2,-1) ;
        now[pos[i]+1]=p1 ;
        now[pos[i]]=p2 ;
    }

    Q=getNumQuestions() ;
    while(Q--)
    {
        int id,num ;
        getQuestion(id,num) ;
        answer(query(1,n,root[num],id)) ;
    }
}
