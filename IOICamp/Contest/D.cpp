#include<bits/stdc++.h>
#define CASE_T int __T ; scanf("%d",&__T) ; while(__T--)
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int s ;
    node()
    {
        l=r=NULL ; s=0 ;
    }
};


inline void pull(node *v)
{
    v->s = (v->l ? v->l->s : 0) + (v->r ? v->r->s : 0) ;
}

void modify(int l,int r,node *u,node *&v,int pos,int val)
{
//    printf("(%d,%d)\n",l,r) ;
    if(l>r) return ;
    if(l==r) { v=new node() ; v->s = (u ? u->s : 0) + val ; return ; }
    int mid=(l+r)/2 ;
    v=new node() ;
    if(pos<=mid)
    {
        v->r = u ? u->r : NULL ;
        modify(l,mid, u ? u->l : NULL ,v->l,pos,val) ;
        pull(v) ;
    }
    else
    {
        v->l = u ? u->l : NULL ;
        modify(mid+1,r, u ? u->r : NULL ,v->r,pos,val) ;
        pull(v) ;
    }
}

int query(int l,int r,int L,int R,node *u)
{
    if(!u) return 0 ;
    if(l==L && r==R) return u->s ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return query(l,mid,L,mid,u->l)+query(mid+1,r,mid+1,R,u->r) ;
}

node *root[maxn] ;
int a[maxn] ;
int tmp[maxn] ;

int last[maxn] ;
main()
{
    CASE_T
    {
        int n,Q ; scanf("%d%d",&n,&Q) ;

        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp[i]=a[i] ;
        sort(tmp+1,tmp+n+1) ;
        int m=unique(tmp+1,tmp+n+1)-tmp-1 ;
        for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+m+1,a[i])-tmp ;

        root[n+1]=NULL ;
        fill(last,last+m+1,-1) ;

        for(int i=n;i>=1;i--)
        {
            if(last[a[i]]!=-1)
            {
                node *tmp ;
                modify(1,n,root[i+1],tmp,last[a[i]],-1) ;
                modify(1,n,tmp,root[i],i,1) ;
                last[a[i]]=i ;
            }
            else
            {
                modify(1,n,root[i+1],root[i],i,1) ;
                last[a[i]]=i ;
            }
        }
        while(Q--)
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            printf("%d\n",query(l,r,1,n,root[l])) ;
        }
    }
}
