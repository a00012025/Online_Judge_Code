#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    int sum,lnum,rnum,all ;
    node()
    {
        l=r=NULL ;
        sum=lnum=rnum=all=0 ;
    }
};

struct RET{int sum,lnum,rnum,all;};
RET inv(const RET &a)
{
    RET b=a ;
    swap(b.lnum,b.rnum) ;
    return b ;
}

node *build(int l,int r)
{
    if(l==r) return new node() ;
    node *u=new node() ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

int fun[maxn] ;
RET cal(RET a,RET b)
{
    RET u ;
    u.all=(a.all && b.all) ;
    u.lnum= a.all ? a.lnum+b.lnum : a.lnum ;
    u.rnum= b.all ? a.rnum+b.rnum : b.rnum ;
    u.sum=a.sum+b.sum ;
    if(!a.all && !b.all) u.sum+=fun[a.rnum+b.lnum] ;
    return u ;
}

void pull(node *u)
{
    RET tmp=cal((RET){u->l->sum,u->l->lnum,u->l->rnum,u->l->all},
                (RET){u->r->sum,u->r->lnum,u->r->rnum,u->r->all}) ;
    u->sum=tmp.sum ; u->lnum=tmp.lnum ;
    u->rnum=tmp.rnum ; u->all=tmp.all ;
}

void modify(int L,int R,node *u,int pos)
{
    if(L==R){u->lnum=u->rnum=u->all=1 ; return ;}
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,u->l,pos) ;
    else modify(mid+1,R,u->r,pos) ;
    pull(u) ;
}

RET query(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return (RET){u->sum,u->lnum,u->rnum,u->all} ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return cal(query(l,mid,L,mid,u->l)
                    ,query(mid+1,r,mid+1,R,u->r)) ;
}

vector<int> v[maxn] ;
int dep[maxn],anc[18][maxn] ;
int mson[maxn] ;
int pid[maxn],head[maxn],chid[maxn],chcnt ;
int chsz[maxn] ;
node *root[maxn] ;

int dfs(int x,int f,int d)
{
    dep[x]=d ; anc[0][x]=f ;
    for(int i=1;i<18;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
    int ret=1,ma=-1 ;
    for(auto i : v[x]) if(i!=f)
    {
        int tmp=dfs(i,x,d+1) ;
        if(tmp>ma) ma=tmp , mson[x]=i ;
        ret+=tmp ;
    }
    return ret ;
}

void dfs(int x,int f)
{
    if(x==f || mson[anc[0][x]]!=x)
    {
        pid[x]=0 ;
        head[x]=x ;
        chid[x]=chcnt++ ;
    }
    else
    {
        pid[x]=pid[f]+1 ;
        head[x]=head[f] ;
        chid[x]=chid[f] ;
    }
    chsz[chid[x]]=max(chsz[chid[x]],pid[x]+1) ;
    for(auto i : v[x]) if(i!=f) dfs(i,x) ;
}

int getfa(int x,int d)
{
    for(int i=0;i<18 && d;i++) if(d&(1<<i))
        x=anc[i][x] , d^=(1<<i) ;
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]!=dep[y]) return dep[x]>dep[y] ?
        LCA(getfa(x,dep[x]-dep[y]),y) : LCA(x,getfa(y,dep[y]-dep[x])) ;
    for(int i=17;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return x==y ? x : anc[0][x] ;
}

void build_HLD()
{
    dfs(1,1,0) ;
    dfs(1,1) ;
    for(int i=0;i<chcnt;i++) root[i]=build(0,chsz[i]-1) ;
}

RET query(int x,int y)
{
    int id=chid[x] ;
    if(chid[x]==chid[y]) return query(pid[y]+1,pid[x],0,chsz[id]-1,root[id]) ;
    RET tmp=query(0,pid[x],0,chsz[id]-1,root[id]) ;
    if(anc[0][head[x]]!=y)
        tmp=cal(query(anc[0][head[x]],y),tmp) ;
    return tmp ;
}

struct edge
{
    int x,y,dis ;
    bool operator < (const edge &rhs) const
    {
        return dis<rhs.dis ;
    }
}E[maxn];

struct que
{
    int x,y,val,id ;
    bool operator < (const que &rhs) const
    {
        return val<rhs.val ;
    }
}q[maxn];
int ans[maxn] ;

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<n;i++) scanf("%d",&fun[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        E[i]=(edge){x,y,dis} ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    build_HLD() ;
    for(int i=1;i<=Q;i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].val) , q[i].id=i ;
    sort(E+1,E+n) ;
    sort(q+1,q+Q+1) ;
    for(int i=Q,j=n-1;i>=1;i--)
    {
        while(j && E[j].dis>=q[i].val)
        {
            int x= dep[E[j].x]>dep[E[j].y] ? E[j].x : E[j].y ;
            int id=chid[x] ;
            modify(0,chsz[id]-1,root[id],pid[x]) ;
            j-- ;
        }
        int x=q[i].x , y=q[i].y , lca=LCA(x,y) ;
        RET res ;
        if(x==lca) res=query(y,x) ;
        else if(y==lca) res=query(x,y) ;
        else res=cal(inv(query(y,lca)),query(x,lca)) ;
        ans[q[i].id]=res.sum ;
        ans[q[i].id]+=(res.all ? fun[res.lnum] : fun[res.lnum]+fun[res.rnum]) ;
    }
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]) ;
}
