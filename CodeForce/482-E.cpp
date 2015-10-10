#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=50000+10 ;

struct query{int type,x,y;}qu[maxn];

int n,fa[maxn] ;
LL val[maxn],sz[maxn] ;
vector<int> v[maxn] ;
bool mark[maxn],have[maxn] ;
LL d[maxn] ; /// d[x] = (size[fa[x]]-size[x]) * val[fa[x]]
int dfs(int x)
{
    sz[x]=1 ;
    int ret=0 ;
    for(auto i : v[x])
        ret+=dfs(i) , sz[x]+=sz[i] ;
    for(auto i : v[x]) d[i]=(sz[x]-sz[i])*val[x] ;

    have[x]=( (ret||mark[x]) ? 1 : 0 ) ;
    if(ret>=2 || mark[x]) {mark[x]=1 ; return 1 ;}
    else return ret ;
}

struct P{int to ; LL ssz,dsum;}; /// son's size & sum of d[i] on the path
vector<P> v2[maxn] ; /// new tree
int fa2[maxn] ; /// sz2sum[x] = sum_{i is son of x && have[i]==0} sz[i]^2
LL sz2sum[maxn] ;
LL pnum[maxn] ; /// how many pairs of node whose LCA = x
void dfs2(int x,bool isfir=0)
{
    if(v2[x].empty())
    {
        if(!isfir) return ;
        pnum[x]=sz[x]*sz[x] ;
        for(auto i : v[x]) pnum[x]-=sz[i]*sz[i] ;
        return ;
    }

    pnum[x]=sz[x]*sz[x]-sz2sum[x] ;
    for(auto i : v2[x])
        dfs2(i.to,isfir) ,
        pnum[x]-=i.ssz*i.ssz ;
}

int getid(int x,int y)
{
    for(int i=0;;i++) if(v2[x][i].to==y)
        return i ;
}

void build_graph(int num)
{
    fill(mark,mark+n+1,0) ;
    fill(have,have+n+1,0) ;
    for(int i=1;i<=n;i++) v[i].clear() , v2[i].clear() ;
    for(int i=2;i<=n;i++) v[fa[i]].push_back(i) ;
    for(int i=0;i<num;i++)
    {
        mark[qu[i].x]=1 ;
        if(qu[i].type==1) mark[qu[i].y]=1 ;
    }
    mark[1]=1 ; dfs(1) ; /// 1 is root of new tree

    for(int i=1;i<=n;i++) if(mark[i])
    {
        sz2sum[i]=0 ;
        for(auto j : v[i]) if(!have[j])
            sz2sum[i]+=sz[j]*sz[j] ;
        if(i==1) continue ;

        int j ; LL ssz=0LL,dsum=0LL ;
        for(j=i;;j=fa[j])
        {
            dsum+=d[j] ;
            if(mark[fa[j]]) break ;
        }
        ssz=sz[j] ; j=fa[j] ;
        v2[j].push_back((P){i,ssz,dsum}) ;
        fa2[i]=j ;
    }
}

LL nowans ;
void process_query(int qid)
{
    if(qu[qid].type==2)
    {
        int x=qu[qid].x , nval=qu[qid].y ;
        nowans+=pnum[x]*(nval-val[x]) ;
        for(auto &i : v2[x])
            i.dsum+=(sz[x]-i.ssz)*(nval-val[x]) ;
        val[x]=nval ;
        printf("%.15f\n",((DB)nowans)/n/n) ;
        return ;
    }
    int x=qu[qid].y , y=qu[qid].x , id ;
    for(int i=x;i!=1;i=fa2[i]) if(i==y || y==1)
        {swap(x,y) ; break ;}
    fa[y]=x ;

    LL dif=0LL ;
    for(int i=y;i!=1;i=fa2[i]) /// update dsum and ssz value of needed edge after
    { /// removing the subtree rooted at y , and calculate answer
        sz[fa2[i]]-=sz[y] ;
        for(auto &k : v2[fa2[i]])
            if(k.to!=i) k.dsum-=val[fa2[i]]*sz[y] ;
            else dif-=k.dsum , k.ssz-=sz[y] ;
    }

    int f=fa2[y] ; P &e=v2[f][getid(f,y)] ;
    sz2sum[f]+=e.ssz*e.ssz ;
    swap(e,v2[f].back()) ; v2[f].pop_back() ;
    v2[x].push_back((P){y,0,val[x]*sz[x]}) ; fa2[y]=x ;
    if(v2[f].empty()) pnum[f]=sz[f]*sz[f]-sz2sum[f] ; /// !!!!!!!!!!!!!!!!!!!

    for(int i=y;i!=1;i=fa2[i]) /// update dsum ans ssz value of needed edge after
    { /// linking the subtree rooted at y to x , and calculate answer
        sz[fa2[i]]+=sz[y] ;
        for(auto &k : v2[fa2[i]])
            if(k.to!=i) k.dsum+=val[fa2[i]]*sz[y] ;
            else dif+=k.dsum , k.ssz+=sz[y] ;
    }

    nowans+=2*dif*sz[y] ;
    printf("%.15f\n",((DB)nowans)/n/n) ;
    dfs2(1) ; /// update pnum
}

bool first=1 ;
void process(int num)
{
    build_graph(num) ;
    nowans=0LL ;
    for(int i=1;i<=n;i++)
    {
        LL add=sz[i]*sz[i] ;
        for(auto j : v[i]) add-=sz[j]*sz[j] ;
        nowans+=add*val[i] ;
    }
    if(first) printf("%.15f\n",((DB)nowans)/n/n) , first=0 ;

    dfs2(1,1) ; /// calculate pnum
    for(int i=0;i<num;i++) process_query(i) ;
}

main()
{
    scanf("%d",&n) ;
    fa[1]=1 ; for(int i=2;i<=n;i++) scanf("%d",&fa[i]) ;
    for(int i=1;i<=n;i++) scanf("%lld",&val[i]) ;

    int Q ; scanf("%d",&Q) ;
    int sq=(int)sqrt(Q+0.5) ;
    for(int i=0;i<Q;i++)
    {
        char c[5] ;
        scanf("%s%d%d",c,&qu[i%sq].x,&qu[i%sq].y) ;
        qu[i%sq].type=(c[0]=='P' ? 1 : 2) ;
        if((i%sq)==sq-1 || i==Q-1) process(i%sq+1) ;
    }
}
