#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100000+10 ;

struct line
{
    int a,b ; /// y=ax+b
    bool operator < (const line &rhs) const
    {
        return a==rhs.a ? b<rhs.b : a>rhs.a ;
    }
};

DB inter(const line &p,const line &q)
{
    return (q.b-p.b)*1.0/(p.a-q.a) ;
}

struct node
{
    node *l,*r ;
    vector<line> vl ;
    vector<DB> vx ;
    void build(int L,int R) ;
    int query(int x) ;
};

line li[maxn],tmp[maxn] ;
void node::build(int L,int R)
{
    for(int i=L;i<=R;i++) tmp[i-L]=li[i] ;
    int sz=R-L+1 ;
    sort(tmp,tmp+sz) ;
    for(int i=0;i<sz;i++)
    {
        if(!vl.empty() && vl.back().a==tmp[i].a)
            continue ;
        while(vl.size()>=2)
        {
            int s=vl.size() ;
            if(inter(vl[s-2],vl[s-1])<inter(vl[s-1],tmp[i]))
                break ;
            vl.pop_back() ; vx.pop_back() ;
        }
        if(!vl.empty()) vx.push_back(inter(vl.back(),tmp[i])) ;
        vl.push_back(tmp[i]) ;
    }
}

int node::query(int x)
{
    int id=lower_bound(vx.begin(),vx.end(),x)-vx.begin() ;
    int ret=vl[id].a*x+vl[id].b ;
    if(id+1<vl.size()) ret=min(ret,vl[id+1].a*x+vl[id+1].b) ;
    if(id-1>=0) ret=min(ret,vl[id-1].a*x+vl[id-1].b) ;
    return ret ;
}

node *build(int l,int r)
{
    node *u=new node ; u->build(l,r) ;
    if(l==r) return u ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

int query(int l,int r,int L,int R,int x,node *u)
{
    if(l==L && r==R) return u->query(x) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,x,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,x,u->r) ;
    else return min(query(l,mid,L,mid,x,u->l),
                    query(mid+1,r,mid+1,R,x,u->r)) ;
}

int a[maxn],s[maxn] ;
main()
{
    int n,Q ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) , s[i]=s[i-1]+a[i] ;
        li[i].a=-a[i] ;
        li[i].b=i*a[i]-s[i] ;
    }
    node *root=build(1,n) ;
    scanf("%d",&Q) ;
    while(Q--)
    {
        int i,j ; scanf("%d%d",&i,&j) ;
        printf("%d\n",query(j-i+1,j,1,n,j-i,root)+s[j]) ;
    }
}
