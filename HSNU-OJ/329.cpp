#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int val,tag ;
    node(){l=r=NULL ; val=tag=0;}
};

node *build(int l,int r)
{
    if(l==r) return new node ;
    node *u=new node() ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

void push(node *u)
{
    if(!u || !u->tag) return ;
    u->l->val+=u->tag ; u->l->tag+=u->tag ;
    u->r->val+=u->tag ; u->r->tag+=u->tag ;
    u->tag=0 ;
}
void pull(node *u)
{
    u->val=max(u->l->val,u->r->val) ;
}

void modify(int l,int r,int L,int R,node *u,int add)
{
    if(l==L && r==R){u->tag+=add ; u->val+=add ; return ;}
    push(u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,u->l,add) ;
    else if(l>mid) modify(l,r,mid+1,R,u->r,add) ;
    else modify(l,mid,L,mid,u->l,add) ,
        modify(mid+1,r,mid+1,R,u->r,add) ;
    pull(u) ;
}

struct event
{
    int t,l,r,add ;
    bool operator < (const event &rhs) const
    {
        return t<rhs.t ;
    }
};

int a[maxn] ;
int x[maxn],idx[maxn],y[maxn],idy[maxn] ;
int used[maxn] ;
vector<event> ev ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        ev.clear() ;
        fill(used,used+n+1,0) ;
        int cntx=0 , cnty=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]) ;
            while(cntx && x[cntx-1]>a[i]) cntx-- ;
            x[cntx]=a[i] ; idx[cntx++]=i ;
            if(!cntx || y[cnty-1]<a[i])
                y[cnty]=a[i] , idy[cnty++]=i ;
        }
        if(cnty==n){printf("-1\n") ; continue ;}
        for(int i=0;i<cntx;i++) used[x[i]]=1 ;
        for(int i=0;i<cnty;i++) used[y[i]]=1 ;
        for(int i=1;i<=n;i++) if(!used[a[i]])
        {
            int l1=lower_bound(y,y+cnty,a[i])-y ;
            int r1=lower_bound(idy,idy+cnty,i)-idy-1 ;
            int l2=lower_bound(idx,idx+cntx,i)-idx ;
            int r2=lower_bound(x,x+cntx,a[i])-x-1 ;
            assert(r1>=l1 && r2>=l2) ;
            ev.push_back((event){l1,l2,r2,1}) ;
            ev.push_back((event){r1+1,l2,r2,-1}) ;
        }
        sort(ev.begin(),ev.end()) ;
        node *root=build(0,n-1) ;
        int ans=0 ;
        for(int i=0,j=0;i<n;i++)
        {
            for(;j<ev.size() && ev[j].t<=i;j++)
                modify(ev[j].l,ev[j].r,0,n-1,root,ev[j].add) ;
            ans=max(ans,root->val) ;
        }
        printf("%d\n",2*ans+1) ;
    }
}
