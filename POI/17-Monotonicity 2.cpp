#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;

struct node
{
    node *l,*r ;
    pii p ;
    node(){l=r=NULL ; p=pii(1,0) ;}
};

node *build(int l,int r)
{
    if(l==r) return new node ;
    node *u=new node ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

inline void up(pii &p,const pii &q){p=max(p,q);}
void modify(int l,int r,int L,int R,node *u,const pii &p)
{
    if(l==L && r==R){up(u->p,p) ; return ;}
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,u->l,p) ;
    else if(l>mid) modify(l,r,mid+1,R,u->r,p) ;
    else modify(l,mid,L,mid,u->l,p) ,
        modify(mid+1,r,mid+1,R,u->r,p) ;
}
pii query(int L,int R,node *u,int pos)
{
    if(L==R) return u->p ;
    int mid=(L+R)/2 ;
    if(pos<=mid) return max(u->p,query(L,mid,u->l,pos)) ;
    else return max(u->p,query(mid+1,R,u->r,pos)) ;
}

int last[maxn],a[maxn],type[maxn] ;
void print(int x,int t)
{
    if(!x) return ;
    print(last[x],t+1) ;
    printf("%d%c",a[x],t?' ':'\n') ;
}

pii equ[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=k;i++)
    {
        char s[3] ; scanf("%s",s) ;
        type[i]=(s[0]=='<' ? -1 : (s[0]=='=' ? 0 : 1)) ;
    }
    for(int i=k+1;i<n;i++) type[i]=type[i-k] ;
    for(int i=0;i<maxn;i++) equ[i]=pii(-1,-1) ;

    node *root=build(0,maxn) ;
    int ed=-1 , ans=-1 ;
    for(int i=1;i<=n;i++)
    {
        pii p=max(query(0,maxn,root,a[i]),equ[a[i]]) ;
        int len=p.F ; last[i]=p.S ;
        if(len>ans) ans=len , ed=i ;
        if(type[len]==0) up(equ[a[i]],pii(len+1,i)) ;
        else if(type[len]==-1) modify(a[i]+1,maxn,0,maxn,root,pii(len+1,i)) ;
        else modify(0,a[i]-1,0,maxn,root,pii(len+1,i)) ;
    }
    printf("%d\n",ans) ;
    print(ed,0) ;
}
