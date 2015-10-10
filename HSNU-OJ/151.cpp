#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct node
{
    node *l,*r ;
    LL val ;
    int tag ;
    node()
    {
        l=r=NULL ;
        val=tag=0 ;
    }
};

node *build(int l,int r)
{
    if(l==r) return new node() ;
    node *u=new node() ;
    int mid=(l+r)/2 ;
    u->l=build(l,mid) ;
    u->r=build(mid+1,r) ;
    return u ;
}

void push(int L,int R,node *u)
{
    if(!u->tag) return ;
    int mid=(L+R)/2 ;
    u->l->tag+=u->tag ;
    u->l->val+=(LL)(mid-L+1)*u->tag ;
    u->r->tag+=u->tag ;
    u->r->val+=(LL)(R-mid)*u->tag ;
    u->tag=0 ;
}

void modify(int l,int r,int L,int R,node *u,int add)
{
    if(l==L && r==R)
    {
        u->val+=(LL)(r-l+1)*add ;
        u->tag+=add ;
        return ;
    }
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) modify(l,r,L,mid,u->l,add) ;
    else if(l>mid) modify(l,r,mid+1,R,u->r,add) ;
    else modify(l,mid,L,mid,u->l,add) ,
        modify(mid+1,r,mid+1,R,u->r,add) ;
    u->val=u->l->val+u->r->val ;
}

LL query(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return u->val ;
    push(L,R,u) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,u->l) ;
    else if(l>mid) return query(l,r,mid+1,R,u->r) ;
    else return query(l,mid,L,mid,u->l)
                +query(mid+1,r,mid+1,R,u->r) ;
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

void modify(int x,int y,int add)
{
    if(x==y) return ;
    int id=chid[x] ;
    if(chid[x]==chid[y])
    {
        modify(pid[y]+1,pid[x],0,chsz[id]-1,root[id],add) ;
        return ;
    }
    modify(0,pid[x],0,chsz[id]-1,root[id],add) ;
    modify(anc[0][head[x]],y,add) ;
}

LL query(int x,int y)
{
    if(x==y) return 0 ;
    int id=chid[x] ;
    if(chid[x]==chid[y])
        return query(pid[y]+1,pid[x],0,chsz[id]-1,root[id]) ;
    return query(0,pid[x],0,chsz[id]-1,root[id])
            +query(anc[0][head[x]],y) ;
}

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    build_HLD() ;
    while(Q--)
    {
        char s[5] ; int x,y ;
        scanf("%s%d%d",s,&x,&y) ;
        int lca=LCA(x,y) ;
        if(s[0]=='P') modify(x,lca,1) , modify(y,lca,1) ;
        else printf("%lld\n",query(x,lca)+query(y,lca)) ;
    }
}
