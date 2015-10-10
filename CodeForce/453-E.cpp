#include<bits/stdc++.h>
#define LL long long
#define INF 2000000000
using namespace std;
const int maxn=100000+10 ;

struct P
{
    int m,ra,t ;
    inline void get(){t=(ra ? (m-1)/ra+1 : INF) ;}
    bool operator < (const P &rhs) const
    {
        return t<rhs.t ;
    }
};

struct node
{
    node *l,*r ;
    bool ok ;
    int last,s ;
    vector<int> t ;
    vector<LL> ms,ras ;
    node(int _s=0)
    {
        s=_s ; last=ok=0 ;
        l=r=NULL ;
    }
};

void push(node *u)
{
    if(!u->ok) return ;
    u->l->last=u->last , u->l->ok=1 ;
    u->r->last=u->last , u->r->ok=1 ;
    u->ok=0 ;
}

int s[maxn],ra[maxn],m[maxn] ;
P p[maxn] ;
node *build(int l,int r)
{
    int sz=r-l+2 ;
    node *u ;
    if(l==r) u=new node(s[l]) ;
    else
    {
        int mid=(l+r)/2 ;
        u=new node() ;
        u->l=build(l,mid) ;
        u->r=build(mid+1,r) ;
        sort(p+l,p+r+1) ;
    }
    u->ms.push_back(0) ;
    u->ras.push_back(0) ;
    for(int i=l;i<=r;i++)
        u->t.push_back(p[i].t) ,
        u->ms.push_back(u->ms.back()+p[i].m) ,
        u->ras.push_back(u->ras.back()+p[i].ra) ;
    return u ;
}

LL query(int l,int r,int L,int R,node *u,int t)
{
    if(L==R)
    {
        LL ret=min((LL)m[L],s[L]+(LL)(t-u->last)*ra[L]) ;
        u->ok=1 ; u->last=t ; s[L]=0 ;
        return ret ;
    }
    if(l==L && r==R && u->ok)
    {
        const vector<int> &v=u->t ;
        int id=upper_bound(v.begin(),v.end(),t-u->last)-v.begin()-1 ;
        LL ret=u->ms[id+1]+(u->ras.back()-u->ras[id+1])*(t-u->last) ;
        u->last=t ;
        return ret ;
    }
    push(u) ;
    int mid=(L+R)/2 ; LL ret ;
    if(r<=mid) ret=query(l,r,L,mid,u->l,t) ;
    else if(l>mid) ret=query(l,r,mid+1,R,u->r,t) ;
    else ret=query(l,mid,L,mid,u->l,t)+query(mid+1,r,mid+1,R,u->r,t) ;
    if(l==L && r==R) u->ok=1 , u->last=t ;
    return ret ;
}

main()
{
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&s[i],&m[i],&ra[i]) ,
        p[i].m=m[i] , p[i].ra=ra[i] , p[i].get() ;
    node *root=build(1,n) ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int t,l,r ; scanf("%d%d%d",&t,&l,&r) ;
        printf("%lld\n",query(l,r,1,n,root,t)) ;
    }
}
