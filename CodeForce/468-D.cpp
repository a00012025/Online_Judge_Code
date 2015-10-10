#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct RET{int id,val;};
RET operator + (const RET &a,const RET &b)
{
    return a.val>=b.val ? a : b ;
}

struct node
{
    node *l,*r ;
    RET p ;
    node(int id,int val){l=r=NULL ; p=(RET){id,val} ;}
};

node *build(int l,int r)
{
    if(l==r) return new node(l,0) ;
    int mid=(l+r)/2 ;
    node *u=new node(l,0) ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

void modify(int l,int r,node *u,int pos,int add)
{
    if(l==r){u->p.val+=add ; return ;}
    int mid=(l+r)/2 ;
    if(pos<=mid) modify(l,mid,u->l,pos,add) ;
    else modify(mid+1,r,u->r,pos,add) ;
    u->p=u->l->p+u->r->p ;
}

struct P{int to,dis;};
vector<P> v[maxn] ;
int n ;
LL d[maxn] ;
int dfs(int x,int f,int &id,int &mi)
{
    int sz=1,maxs=0 ;
    for(auto i : v[x]) if(i.to!=f)
    {
        d[i.to]=d[x]+i.dis ;
        int tmp=dfs(i.to,x,id,mi) ;
        sz+=tmp ; maxs=max(maxs,tmp) ;
    }
    int val=max(maxs,n-sz) ;
    if(val<mi) mi=val , id=x ;
    return sz ;
}
void dfs(int x)
{
    int id,mi ;
    dfs(x,-1,id,mi) ; /// calculate dis
}

void dfs2(int x,int f,set<int> &s)
{
    s.insert(x) ;
    for(auto i : v[x]) if(i.to!=f)
        dfs2(i.to,x,s) ;
}

node *root ;
int cent ;
set<int> st[maxn],st2 ;
int id[maxn],sz ;
bool ruse=0 ;
int solve(int x)
{
    if(x!=cent) modify(0,sz-1,root,id[x],-1) ;
    RET r=root->p ;
    if(r.val==n-x+1)
    {
        int pos=r.id , ret=*st[pos].begin() ;
        st2.erase(*st[pos].begin()) ;
        st[pos].erase(st[pos].begin()) ;
        if(!st[pos].empty()) st2.insert(*st[pos].begin()) ;
        modify(0,sz-1,root,pos,-1) ;
        return ret ;
    }
    int tmp=-1 ;
    if(x!=cent && !st[id[x]].empty()) st2.erase(tmp = *st[id[x]].begin()) ;
    int ret=st2.empty() ? cent : *st2.begin() ;
    if(!ruse && cent<ret) ruse=1 , ret=cent ;
    if(tmp!=-1) st2.insert(tmp) ;

    if(ret==cent) return ret ;
    int pos=id[ret] ;
    modify(0,sz-1,root,pos,-1) ;
    st2.erase(*st[pos].begin()) ;
    st[pos].erase(st[pos].begin()) ;
    if(!st[pos].empty()) st2.insert(*st[pos].begin()) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    int mi=n ;
    dfs(1,-1,cent,mi) ;
    d[cent]=0 ; dfs(cent) ;

    LL ans=0LL ;
    for(int i=1;i<=n;i++) ans+=d[i] ;
    printf("%I64d\n",2*ans) ;
    if(n==1){printf("1\n") ; return 0 ;}
    if(n==2){printf("2 1\n") ; return 0 ;}

    sz=v[cent].size() ;
    for(int i=0;i<sz;i++)
    {
        dfs2(v[cent][i].to,cent,st[i]) ;
        for(auto j : st[i]) id[j]=i ;
    }
    for(int i=0;i<sz;i++) st2.insert(*st[i].begin()) ;
    root=build(0,sz-1) ;
    for(int i=0;i<sz;i++) modify(0,sz-1,root,i,2*st[i].size()) ;
    for(int i=1;i<=n;i++) printf("%d%c",solve(i),i==n?'\n':' ') ;
}
