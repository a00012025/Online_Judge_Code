#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

struct node
{
    node *l,*r ;
    int val ;
    node(){l=r=NULL ; val=0 ;}
    node(int _v){l=r=NULL ; val=_v ;}
};

node *build(int l,int r)
{
    if(l==r) return new node() ;
    int mid=(l+r)/2 ;
    node *u=new node() ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

node *add(int l,int r,node *u,int pos)
{
    if(l==r) return new node(u->val+1) ;
    int mid=(l+r)/2 ;
    node *v=new node() ;
    if(pos<=mid) v->r=u->r , v->l=add(l,mid,u->l,pos) ;
    else v->l=u->l , v->r=add(mid+1,r,u->r,pos) ;
    v->val=v->l->val+v->r->val;
    return v ;
}

int querys(int l,int r,int L,int R,node *u1,node *u2) /// u1-u2
{
    if(l==L&&r==R) return u1->val-u2->val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return querys(l,r,L,mid,u1->l,u2->l) ;
    else if(l>mid) return querys(l,r,mid+1,R,u1->r,u2->r) ;
    else return querys(l,mid,L,mid,u1->l,u2->l)+
                querys(mid+1,r,mid+1,R,u1->r,u2->r) ;
}

int query(int l,int r,node *u1,node *u2,int val) /// u1-u2
{
    if(l==r) return l ;
    int lef=u1->l->val-u2->l->val , mid=(l+r)/2 ;
    if(lef>=val) return query(l,mid,u1->l,u2->l,val) ;
    else return query(mid+1,r,u1->r,u2->r,val-lef) ;
}

int a[maxn],ri[maxn],ri2[maxn] ;
map<int,int> mp ;
node *root[maxn] ;

int las[maxn],dp[maxn] ;
void printans(int x)
{
    if(!x) return ;
    printans(las[x]) ;
    if(las[x]!=x-1)
        printf("%d %d %d %d ",a[las[x]+1],a[x],a[las[x]+1],a[x]) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=n;i>=1;i--)
    {
        auto it=mp.find(a[i]) ;
        if(it==mp.end()) ri[i]=n+1 ;
        else ri[i]=it->second ;
        mp[a[i]]=i ;
    }
    root[0]=build(1,n+1) ;
    for(int i=1;i<=n;i++) root[i]=add(1,n+1,root[i-1],ri[i]) ;
    for(int i=n;i>=1;i--)
    {
        if(ri[i]==n+1){ri2[i]=n+1 ; continue ;}
        ri2[i]=ri2[ri[i]] ;
        if(ri[i]>i+1)
            ri2[i]=min(ri2[i],
            query(1,n+1,root[ri[i]-1],root[i],
            querys(1,ri[i],1,n+1,root[ri[i]-1],root[i])+1)) ;
    }
    ri[n+1]=n+1 ;
    for(int i=1;i<=n;i++) ri2[i]=min(ri2[i],ri[ri[ri[i]]]) ;

    fill(dp,dp+n+1,-1) ; dp[0]=0 ;
    for(int i=0;i<n;i++)
    {
        if(dp[i+1]<dp[i]) dp[i+1]=dp[i] , las[i+1]=i ;
        if(ri2[i+1]!=n+1 && dp[ri2[i+1]]<dp[i]+1)
            dp[ri2[i+1]]=dp[i]+1 , las[ri2[i+1]]=i ;
    }
    printf("%d\n",4*dp[n]) ;
    printans(n) ;
}
