#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=200000+10 ;

struct P{LL a,b,c;};
P operator + (const P &x,const P &y){return (P){(x.a+y.a)%MOD,(x.b+y.b)%MOD,(x.c+y.c)%MOD} ;}
void operator += (P& x, const P& y){x=x+y;}

struct node
{
    node *l,*r ;
    P tag ;
    LL sum ;
    node(){l=r=NULL ; sum=0 ; tag.a=tag.b=tag.c=0 ;}
};

inline LL get1(int l,int r)
{
    return ((LL)(r+l)*(r-l+1)/2)%MOD ;
}
inline LL get2(int l,int r)
{
    return ((LL)r*(r+1)*(2*r+1)/6-(LL)(l-1)*l*(2*l-1)/6)%MOD ;
}

void pull(node *u){u->sum=(u->l->sum+u->r->sum)%MOD;}
void push(int l,int r,node *u)
{
    LL a=u->tag.a , b=u->tag.b , c=u->tag.c ;
    if(!a && !b && !c) return ;
    int mid=(l+r)/2 ;
    u->l->sum += a*get2(l,mid)%MOD + b*get1(l,mid)%MOD + c*(mid-l+1) ;
    u->l->sum %= MOD ;
    u->r->sum += a*get2(mid+1,r)%MOD + b*get1(mid+1,r)%MOD + c*(r-mid) ;
    u->r->sum %= MOD ;
    u->l->tag+=u->tag ;
    u->r->tag+=u->tag ;
    u->tag=(P){0,0,0} ;
}

node *build(int l,int r)
{
    if(l==r) return new node ;
    node *u=new node ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

void modify(int l,int r,int L,int R,node *u,int x)
{
    if(L==l && r==R)
    {
        LL a=1 , b=-2*x+3+MOD , c=(LL)(x-1)*(x-2)%MOD ;
        u->sum += a*get2(l,r)%MOD + b*get1(l,r)%MOD + c*(r-l+1)%MOD ;
        u->sum %= MOD ;
        u->tag+=(P){a,b,c} ;
        return ;
    }
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,u->l,x) ;
    else if(l>mid) modify(l,r,mid+1,R,u->r,x) ;
    else modify(l,mid,L,mid,u->l,x) ,
        modify(mid+1,r,mid+1,R,u->r,x) ;
    pull(u) ;
}

LL query(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return u->sum ;
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return (query(l,mid,L,mid,u->l)+query(mid+1,r,mid+1,R,u->r))%MOD ;
}

int main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    node *root=build(1,n) ;
    while(Q--)
    {
        int t,x,y ; scanf("%d%d%d",&t,&x,&y) ;
        if(t==1) modify(x,y,1,n,root,x) ;
        else printf("%lld\n",query(x,y,1,n,root)) ;
    }
}
