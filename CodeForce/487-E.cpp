#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=200000+10 ;

namespace seg_t
{
    struct node
    {
        node *l,*r ;
        int val ;
        node(){l=r=NULL ;}
    };

    void pull(node *u){u->val=min(u->l->val,u->r->val) ;}

    node *build(int l,int r)
    {
        if(l==r) return new node() ;
        node *u=new node() ;
        int mid=(l+r)/2 ;
        u->l=build(l,mid) ;
        u->r=build(mid+1,r) ;
        return u ;
    }

    void modify(int L,int R,node *u,int pos,int val)
    {
        if(L==R){ u->val=val ; return ; }
        int mid=(L+R)/2 ;
        if(pos<=mid) modify(L,mid,u->l,pos,val) ;
        else modify(mid+1,R,u->r,pos,val) ;
        pull(u) ;
    }

    int query(int l,int r,int L,int R,node *u)
    {
        if(l==L && r==R) { return u->val ; }
        int mid=(L+R)/2 ;
        if(r<=mid) return query(l,r,L,mid,u->l) ;
        else if(l>mid) return query(l,r,mid+1,R,u->r) ;
        else return min(query(l,mid,L,mid,u->l),
                        query(mid+1,r,mid+1,R,u->r)) ;
    }
}

namespace hld
{
    const int LOG=int(log2(maxn)+1) ;
    vector<int> v[maxn] ;
    int n ;
    int dep[maxn],anc[LOG][maxn] ;
    int tin[maxn],tout[maxn],tick ;
    int mson[maxn] ;
    int pid[maxn],head[maxn],chid[maxn],chcnt ;
    int chsz[maxn] ;
    int weight[maxn] ;
    seg_t::node *root[maxn] ;

    void add_edge(int x,int y)
    {
        v[y].push_back(x) ;
        v[x].push_back(y) ;
    }

    int dfs(int x,int f,int d)
    {
        tin[x]=tick++ ;
        dep[x]=d ; anc[0][x]=f ;
        for(int i=1;i<LOG;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
        int ret=1,ma=-1 ;
        for(auto i : v[x]) if(i!=f)
        {
            int tmp=dfs(i,x,d+1) ;
            if(tmp>ma) ma=tmp , mson[x]=i ;
            ret+=tmp ;
        }
        tout[x]=tick++ ;
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

    inline bool isfa(int x,int y)
    {
        return tin[x]<=tin[y] && tout[x]>=tout[y] ;
    }

    int LCA(int x,int y)
    {
        if(isfa(x,y)) return x ;
        if(isfa(y,x)) return y ;
        for(int i=LOG-1;i>=0;i--) if(!isfa(anc[i][x],y))
            x=anc[i][x] ;
        return anc[0][x] ;
    }

    void build_HLD()
    {
        dfs(1,1,0) ;
        dfs(1,1) ;
        for(int i=0;i<chcnt;i++) root[i]=seg_t::build(0,chsz[i]-1) ;
        for(int i=1;i<=n;i++)
        {
            int id=chid[i] ;
            seg_t::modify(0,chsz[id]-1,root[id],pid[i],weight[i]) ;
        }
    }

    inline void modify(int x,int val)
    {
        int id=chid[x] ;
        seg_t::modify(0,chsz[id]-1,root[id],pid[x],val) ;
    }

    int query(int x,int y) /// y is fa of x
    {
        assert(isfa(y,x)) ;
        int id=chid[x] ;
        if(id==chid[y]) return
            seg_t::query(pid[y],pid[x],0,chsz[id]-1,root[id]) ;
        return min(seg_t::query(0,pid[x],0,chsz[id]-1,root[id]),
                   query(anc[0][head[x]],y)) ;
    }
}

vector<int> v[maxn] ;
int w[maxn] ;
int lev[maxn] ;
int cutid[maxn],bcc[maxn],ccnt,bcnt ;
vector<int> vb[maxn] ;
multiset<int> st[maxn] ;
stack<int> s ;
int dfs(int x,int f,int l)
{
    int low ; lev[x]=low=l ;
    s.push(x) ;
    int iscut=0,son=0 ;
    for(auto i : v[x]) if(i!=f)
    {
        if(lev[i]!=-1){low=min(low,lev[i]) ; continue ;}
        son++ ;
        int tmp=dfs(i,x,l+1) ; low=min(low,tmp) ;
        if(tmp>=l)
        {
            iscut=1 ; bcnt++ ;
            int top ;
            do
            {
                bcc[top=s.top()]=bcnt ;
                vb[bcnt].push_back(top) ;
                s.pop() ;
            }while(top!=i) ;
            bcc[x]=bcnt ; vb[bcnt].push_back(x) ;
        }
    }
    if((x!=f && iscut) || (x==f && son>1)) cutid[x]=++ccnt ;
    return low ;
}

int fa[maxn] ;
void dfs2(int x,int f) /// on new graph which is a tree
{
    fa[x]=f ;
    for(auto i : hld::v[x]) if(i!=f)
        dfs2(i,x) ;
}

main()
{
    int n,m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    memset(lev,-1,sizeof(lev)) ;
    dfs(1,1,0) ;

    hld::n=ccnt+bcnt ;
    for(int i=1;i<=bcnt;i++) for(auto j : vb[i]) if(cutid[j])
        hld::add_edge(cutid[j],i+ccnt) ;
    dfs2(1,1) ;
    for(int i=1;i<=n;i++) if(cutid[i])
        hld::weight[cutid[i]]=w[i] ;
    for(int i=1;i<=bcnt;i++)
    {
        for(auto j : vb[i]) if(!cutid[j] || fa[i+ccnt]!=cutid[j])
            st[i].insert(w[j]) ;
        hld::weight[i+ccnt]= *st[i].begin() ;
    }
    hld::build_HLD() ;

    while(Q--)
    {
        char c[5] ; int x,y ;
        scanf("%s%d%d",c,&x,&y) ;
        if(c[0]=='A')
        {
            if(x==y){printf("%d\n",w[x]) ; continue ;}
            x=(cutid[x] ? cutid[x] : bcc[x]+ccnt) ;
            y=(cutid[y] ? cutid[y] : bcc[y]+ccnt) ;
            int lca=hld::LCA(x,y) ;
            int ans=min(hld::query(x,lca),hld::query(y,lca)) ;
            if(lca!=1 && lca>ccnt)
                ans=min(ans,hld::query(fa[lca],fa[lca])) ;
            printf("%d\n",ans) ;
        }
        else if(cutid[x])
        {
            w[x]=y ; x=cutid[x] ;
            int tmp=hld::query(x,x) ;
            hld::modify(x,y) ;
            if(x==1) continue ;
            int bid=fa[x]-ccnt ;
            st[bid].erase(st[bid].find(tmp)) ;
            st[bid].insert(y) ;
            hld::modify(bid+ccnt,*st[bid].begin()) ;
        }
        else
        {
            int old=w[x] ; w[x]=y ;
            x=bcc[x] ;
            st[x].erase(st[x].find(old)) ;
            st[x].insert(y) ;
            hld::modify(x+ccnt,*st[x].begin()) ;
        }
    }
}
