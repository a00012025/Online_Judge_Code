#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
#define debugf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int maxn=300000+10,maxq=1000000+10 ;
const LL X=123LL ;
LL xpow[maxn],ixpow[maxn] ;

int getint()
{
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar() ;
    int ret=0 ;
    while(1)
    {
        ret=ret*10+c-'0' ;
        c=getchar() ;
        if(c<'0'||c>'9') return ret ;
    }
}

char cc[12] ;
void printint(int x)
{
    int cnt=0 ;
    while(x) cc[cnt++]='0'+x%10 , x/=10 ;
    if(!cnt) cc[cnt++]='0' ;
    for(int i=cnt-1;i>=0;i--) putchar(cc[i]) ;
    putchar('\n') ;
}

LL pow(LL x,int n)
{
    if(n<=1) return n ? x : 1LL ;
    LL tmp=pow(x,n/2) ;
    if(n&1) return (tmp*tmp%MOD)*x%MOD ;
    return tmp*tmp%MOD ;
}

LL inv(LL x)
{
    return pow(x,MOD-2) ;
}

int bs[maxn] ;
int getbs(int x)
{
    return x==bs[x] ? x : bs[x]=getbs(bs[x]) ;
}

vector<int> v[maxn] ;

int n,fa[maxn],dep[maxn] ;
char s[maxn] ;
LL h1[maxn],h2[maxn] ;
void dfs(int x,int f,int d=0)
{
    dep[x]=d ; fa[x]=f ;
    if(x)
        h1[x]=(h1[f]*X+s[x]-'a')%MOD ,
        h2[x]=(h2[f]+xpow[d]*(s[x]-'a'))%MOD ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x,d+1) ;
}

struct P{int val,id;};
vector<P> v2[maxn] ;
int ansval[2*maxq] ;

bool vis[maxn] ;
void dfs_solve_lca(int x,int f)
{
    vis[x]=1 ;
    for(auto i : v2[x]) if(vis[i.val])
        ansval[i.id]=getbs(i.val) ;
    v2[x].clear() ;
    for(auto i : v[x]) if(i!=f)
        dfs_solve_lca(i,x) , bs[getbs(i)]=x ;
}

int sta[maxn],top=0 ;
void dfs_solve_fa(int x,int f)
{
    sta[top++]=x ;
    for(auto i : v2[x]) ansval[i.id]=sta[top-1-i.val] ;
    v2[x].clear() ;
    for(auto i : v[x]) if(i!=f)
        dfs_solve_fa(i,x) ;
    top-- ;
}

struct query
{
    int x1,y1,x2,y2,lca1,lca2,l,r ;
    void get(int qid)
    {
        x1=getint() , y1=getint() ;
        x2=getint() , y2=getint() ;
        v2[x1].push_back((P){y1,2*qid-1}) ;
        v2[y1].push_back((P){x1,2*qid-1}) ;
        v2[x2].push_back((P){y2,2*qid}) ;
        v2[y2].push_back((P){x2,2*qid}) ;
    }
    void get2(int qid)
    {
        if(s[x1]!=s[x2]) {l=0 , r=1 ; return ;}
        lca1=ansval[2*qid-1] ;
        lca2=ansval[2*qid] ;
        l=1 ; r=min(dep[x1]+dep[y1]-2*dep[lca1],
                    dep[x2]+dep[y2]-2*dep[lca2])+2 ;
    }
}q[maxq];
int Qnum ;

void precal_query()
{
    dfs_solve_lca(0,0) ;
    for(int i=1;i<=Qnum;i++) q[i].get2(i) ;
}

LL gethash(int x,int y,int lca,int len,int query_pos)
{
    LL ret ;
    if(dep[x]-dep[lca]+1 >= len)
        ret=h1[x]-h1[query_pos]*xpow[len] ; /// = getfa(x.len)
    else
    {
        y=query_pos ; /// = getfa(y,dep[x]+dep[y]-2*dep[lca]+1-len) ;
        int a=dep[x]-dep[lca] ;
        ret=h1[x]-h1[fa[lca]]*xpow[a+1] ;
        int b=a+dep[y]-dep[lca] ;
        LL add=h2[y]-h2[fa[lca]] ;
        if(b>dep[y]) add*=xpow[b-dep[y]] ;
        else if(b<dep[y]) add*=ixpow[dep[y]-b] ;
        ret+=add-(s[lca]-'a')*xpow[a] ;
    }
    ret%=MOD ;
    if(ret<0) ret+=MOD ;
    return ret ;
}

bool process_query()
{
    bool ok=1 ;
    for(int i=1;i<=Qnum;i++) if(q[i].l+1!=q[i].r)
    {
        ok=0 ;
        int len=(q[i].l+q[i].r)>>1 ;
        int x1=q[i].x1 , y1=q[i].y1 , lca1=q[i].lca1 ;
        int x2=q[i].x2 , y2=q[i].y2 , lca2=q[i].lca2 ;
        if(dep[x1]-dep[lca1]+1>=len)
            v2[x1].push_back((P){len,2*i-1}) ;
        else
            v2[y1].push_back((P){dep[x1]+dep[y1]-2*dep[lca1]+1-len,2*i-1}) ;
        if(dep[x2]-dep[lca2]+1>=len)
            v2[x2].push_back((P){len,2*i}) ;
        else
            v2[y2].push_back((P){dep[x2]+dep[y2]-2*dep[lca2]+1-len,2*i}) ;
    }
    if(ok) return 1 ;
    dfs_solve_fa(0,0) ;
    for(int i=1;i<=Qnum;i++) if(q[i].l+1!=q[i].r)
    {
        int mid=(q[i].l+q[i].r)>>1 ;
        if(gethash(q[i].x1,q[i].y1,q[i].lca1,mid,ansval[2*i-1])
           ==gethash(q[i].x2,q[i].y2,q[i].lca2,mid,ansval[2*i]))
            q[i].l=mid ;
        else q[i].r=mid ;
    }
    return 0 ;
}

main()
{
    n=getint() ; for(int i=1;i<=n;i++) s[i]=getchar() ;
    LL IX=inv(X) ;
    for(int i=0;i<=n;i++)
    {
        xpow[i]= i ? xpow[i-1]*X%MOD : 1LL ;
        ixpow[i]= i ? ixpow[i-1]*IX%MOD : 1LL ;
        bs[i]=i ;
    }
    for(int i=1;i<n;i++)
    {
        int x=getint() , y=getint() ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    v[0].push_back(1) ;
    dfs(0,0,0) ;

    Qnum=getint() ;
    for(int i=1;i<=Qnum;i++) q[i].get(i) ;
    precal_query() ;

    while(!process_query()) ;
    for(int i=1;i<=Qnum;i++) printint(q[i].l) ;
}
