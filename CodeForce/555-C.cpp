#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=200000+10 ;

struct node
{
    node *l,*r ;
    int val ;
    node(int _v=INF){l=r=NULL ; val=_v ;}
};
void pull(node *u){u->val=min(u->l->val,u->r->val);}
node *build(int l,int r)
{
    if(l==r) return new node() ;
    node *u=new node() ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}
void modify(int l,int r,node *u,int pos,int val)
{
    if(l==r){u->val=val ; return ;}
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,u->l,pos,val) ;
    else modify(mid+1,r,u->r,pos,val) ;
    pull(u) ;
}
int query(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return u->val ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return min(query(l,mid,L,mid,u->l),
                    query(mid+1,r,mid+1,R,u->r)) ;
}

void norm(vector<int> &v)
{
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
}
int id(const vector<int> &v,int val)
{
    return lower_bound(v.begin(),v.end(),val)-v.begin() ;
}

set<int> s ;
int x[maxn],y[maxn],d[maxn] ;
vector<int> vx,vy ;
main()
{
    int n,q ; scanf("%d%d",&n,&q) ;
    vx.push_back(0) ; vy.push_back(0) ;
    for(int i=1;i<=q;i++)
    {
        char c[3] ; scanf("%d%d%s",&x[i],&y[i],c) ;
        d[i]=(c[0]=='L' ? 1 : 2) ;
        vx.push_back(x[i]) ;
        vy.push_back(y[i]) ;
    }
    norm(vx) ; norm(vy) ;
    int sz=vx.size() ;
    node *rx=build(0,sz-1) , *ry=build(0,sz-1) ;
    modify(0,sz-1,rx,0,0) ;
    modify(0,sz-1,ry,0,0) ;
    for(int i=1;i<=q;i++)
    {
        if(s.count(x[i])){printf("0\n") ; continue ;}
        s.insert(x[i]) ;
        if(d[i]==1)
        {
            int l=0 , r=id(vx,x[i]) , now=r ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(query(mid,now,0,sz-1,rx)<=y[i]) l=mid ;
                else r=mid ;
            }
            printf("%d\n",x[i]-vx[l]) ;
            modify(0,sz-1,ry,id(vy,y[i]),vx[l]) ;
        }
        else
        {
            int l=0 , r=id(vy,y[i]) , now=r ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(query(mid,now,0,sz-1,ry)<=x[i]) l=mid ;
                else r=mid ;
            }
            printf("%d\n",y[i]-vy[l]) ;
            modify(0,sz-1,rx,id(vx,x[i]),vy[l]) ;
        }
    }
}
