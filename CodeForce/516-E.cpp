#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=200000+10 ;

struct P{int to ; LL dis;};
vector<P> v[2*maxn] ;
LL d[2*maxn] ;
void init(int Max)
{
    for(int i=0;i<=Max;i++) d[i]=INF , v[i].clear() ;
}

void add_edge(int x,int y,LL dis)
{
    v[x].push_back((P){y,dis}) ;
    v[y].push_back((P){x,dis}) ;
}

struct Q
{
    int id ; LL val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};
bool cmp(const Q &a,const Q &b){return a.val<b.val ;}

priority_queue<Q> pq ;
void Dijkstra(int st)
{
    pq.push((Q){st,0}) ; d[st]=0 ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.val!=d[u.id]) continue ;
        for(auto i : v[u.id]) if(d[i.to]>d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

void gcd(LL a,LL b,LL &x,LL &y,LL c)
{
    if(b==0){x=c/a ; y=0 ; return ;}
    gcd(b,a%b,y,x,c) ; y-=(a/b)*x ;
}

LL inv(LL a,LL mod)
{
    LL x,y ; gcd(a,mod,x,y,1) ;
    x%=mod ; if(x<0) x+=mod ;
    return x ;
}

inline void norm(vector<int> &v0)
{
    sort(v0.begin(),v0.end()) ;
    v0.resize(unique(v0.begin(),v0.end())-v0.begin()) ;
}

vector<int> u1,u2 ;
inline int ID1(int x){return lower_bound(u1.begin(),u1.end(),x)-u1.begin() ;}
inline int ID2(int x){return lower_bound(u2.begin(),u2.end(),x)-u2.begin() ;}
inline bool in(int x,vector<int> &v0)
{return !v0.empty() && x==*lower_bound(v0.begin(),v0.end(),x) ;}

int X,Y ;
LL invx , invy ;
Q t1[maxn],t2[maxn] ;
LL solve(vector<int> &vb,vector<int> &vg)
{
    if(vb.size()==X && vg.size()==Y) return -1 ;
    u1.clear() ; u2.clear() ;
    for(auto i : vb) u1.push_back(i) , u2.push_back(i%Y) ;
    for(auto i : vg) u2.push_back(i) , u1.push_back(i%X) ;
    norm(u1) ; norm(u2) ;
    int n=u1.size() , m=u2.size() , tot=n+m ;
    init(tot) ;
    for(auto i : vb) add_edge(tot,ID1(i),i) , add_edge(tot,n+ID2(i%Y),i) ;
    for(auto i : vg) add_edge(tot,n+ID2(i),i) , add_edge(tot,ID1(i%X),i) ;

    for(int i=0;i<n;i++)
        t1[i]=(Q){u1[i],((u1[i]-u1[0])*invy)%X} ;
    for(int i=0;i<m;i++)
        t2[i]=(Q){u2[i],((u2[i]-u2[0])*invx)%Y} ;
    sort(t1,t1+n,cmp) ; sort(t2,t2+m,cmp) ;
    t1[n]=(Q){t1[0].id,X} ;
    t2[m]=(Q){t2[0].id,Y} ;

    for(int i=0;i<n;i++)
        add_edge(ID1(t1[i].id),ID1(t1[i+1].id),Y*(t1[i+1].val-t1[i].val)) ;
    for(int i=0;i<m;i++)
        add_edge(n+ID2(t2[i].id),n+ID2(t2[i+1].id),X*(t2[i+1].val-t2[i].val)) ;
    Dijkstra(tot) ;

    LL ret=0LL ;
    for(int i=0;i<n;i++)
        if(t1[i+1].val!=t1[i].val+1 || !in(t1[i].id,vb))
        ret=max(ret,d[ID1(t1[i].id)]+Y*(t1[i+1].val-t1[i].val-1)) ;
    for(int i=0;i<m;i++)
        if(t2[i+1].val!=t2[i].val+1 || !in(t2[i].id,vg))
        ret=max(ret,d[n+ID2(t2[i].id)]+X*(t2[i+1].val-t2[i].val-1)) ;
    return ret ;
}

vector<int> vb[maxn],vg[maxn] ;
main()
{
    scanf("%d%d",&X,&Y) ;
    int g=__gcd(X,Y) ; X/=g ; Y/=g ;
    if(g>=maxn){printf("-1\n") ; return 0 ;}

    invx=inv(X,Y) ; invy=inv(Y,X) ;

    int n ; scanf("%d",&n) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        vb[x%g].push_back(x/g) ;
    }
    scanf("%d",&n) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        vg[x%g].push_back(x/g) ;
    }
    LL ans=0LL ;
    for(int i=0;i<g;i++)
    {
        if(vb[i].empty() && vg[i].empty())
            {printf("-1\n") ; return 0 ;}
            norm(vb[i]) ; norm(vg[i]) ;
        LL tmp=solve(vb[i],vg[i]) ;
        if(tmp!=-1) ans=max(ans,tmp*g+i) ;
    }
    printf("%I64d\n",ans) ;
}
