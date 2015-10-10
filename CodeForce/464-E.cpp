#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define MOD 1000000007
using namespace std;
const int maxn=100000+100 ;

LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1LL ;
    LL t=power(x,n/2) ;
    if(n%2) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}

ULL Rand()
{
    static ULL _r[5] ;
    for(int i=0;i<5;i++) _r[i]=rand() ;
    return (_r[0]<<49)^(_r[1]<<34)^(_r[2]<<19)^(_r[3]<<4)^(_r[4]>>11) ;
}
ULL rval[maxn] ;

struct node
{
    node *l,*r ;
    int len ;
    ULL h ; /// hash value
    node(int _l=0,ULL _h=0)
        {l=r=NULL ; len=_l ; h=_h ;}
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

void pull(int l,int r,node *u)
{
    int mid=(r+l)/2 ;
    u->len=(u->r->len==r-mid ?
            r-mid+u->l->len : u->r->len) ;
    u->h=u->l->h^u->r->h ;
}

void push(node *u)
{
    if(u->l) return ;
    u->l=new node() ;
    u->r=new node() ;
}

node *modify(int l,int r,node *u,int pos)
{
    if(l==r) return new node(1,rval[l]) ;
    push(u) ;
    int mid=(l+r)/2 ;
    node *v=new node() ;
    if(pos<=mid) v->r=u->r , v->l=modify(l,mid,u->l,pos) ;
    else v->l=u->l , v->r=modify(mid+1,r,u->r,pos) ;
    pull(l,r,v) ; return v ;
}

node *reset(int l,int r,int L,int R,node *u)
{
    if(l==L && r==R) return new node() ;
    push(u) ;
    int mid=(L+R)/2 ;
    node *v=new node() ;
    if(r<=mid) v->r=u->r , v->l=reset(l,r,L,mid,u->l) ;
    else if(l>mid) v->l=u->l , v->r=reset(l,r,mid+1,R,u->r) ;
    else
        v->l=reset(l,mid,L,mid,u->l) ,
        v->r=reset(mid+1,r,mid+1,R,u->r) ;
    pull(L,R,v) ; return v ;
}

int query_r(int l,int r,node *u,int pos)
{
    if(l==r) return l ;
    int mid=(l+r)/2 ;
    push(u) ;
    if(pos<=mid && u->l->len<mid-pos+1)
        return query_r(l,mid,u->l,pos) ;
    else return query_r(mid+1,r,u->r,max(pos,mid+1)) ;
}

node *add(node *u,int pos)
{
    int pos2=query_r(0,maxn-1,u,pos) ;
    node *u2=modify(0,maxn-1,u,pos2) ;
    if(pos2>pos) return reset(pos,pos2-1,0,maxn-1,u2)  ;
    else return u2 ;
}

bool query(int l,int r,node *u1,node *u2) /// return u1<u2
{
    if(l==r) return u1->len<u2->len ;
    push(u1) ; push(u2) ;
    int mid=(l+r)/2 ;
    if(u1->r->h == u2->r->h) return query(l,mid,u1->l,u2->l) ;
    else return query(mid+1,r,u1->r,u2->r) ;
}

int cmp(node *a,node *b) /// a-b
{
    if(!b) return -1 ;
    if(a->h==b->h) return 0 ;
    return query(0,maxn-1,a,b) ? -1 : 1 ;
}

struct Q
{
    int id ; node *val ;
    bool operator < (const Q &rhs) const
    {
        return cmp(val,rhs.val)==1 ;
    }
};
priority_queue<Q> pq ;

struct P{int to,dis;};
vector<P> v[maxn] ;
node *d[maxn] ;
bool done[maxn] ;
int las[maxn] ;
void Dijkstra(int st,int ed)
{
    d[st]=build(0,maxn-1) ;
    pq.push((Q){st,d[st]}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id==ed) return ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(!done[i.to])
        {
            node *nd=add(d[u.id],i.dis) ;
            if(cmp(nd,d[i.to])==-1)
            {
                las[i.to]=u.id ;
                d[i.to]=nd ;
                pq.push((Q){i.to,nd}) ;
            }
        }
    }
}

vector<int> ans ;
LL ansd ;
void getans(int st,int x)
{
    if(st==x){ans.push_back(x) ; return ;}
    getans(st,las[x]) ;
    ans.push_back(x) ;
    for(auto i : v[las[x]]) if(i.to==x)
        ansd=(ansd+power(2,i.dis))%MOD ;
}

main()
{
    srand(time(NULL)) ;
    for(int i=0;i<maxn;i++) rval[i]=Rand() ;
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    int st,ed ; scanf("%d%d",&st,&ed) ;
    Dijkstra(st,ed) ;
    if(!d[ed]){printf("-1\n") ; return 0 ;}

    getans(st,ed) ;
    printf("%I64d\n%d\n",ansd,ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
