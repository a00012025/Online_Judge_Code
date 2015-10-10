#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=100000+10 ;
struct P{int to,dis;};
struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

vector<P> v[maxn] ;
vector<int> v2[maxn] ;
int fa[maxn] ;
int n,d[maxn] ;
bool done[maxn] ;
priority_queue<Q> pq ;

void Dijkstra(int st)
{
    fill(d+1,d+n+1,INF) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        if(u.id!=st) v2[fa[u.id]].push_back(u.id) ;
        for(auto i : v[u.id]) if(d[i.to] > d[u.id]+i.dis)
        {
            fa[i.to]=u.id ;
            d[i.to]=d[u.id]+i.dis ;
            pq.push((Q){i.to,d[i.to]}) ;
        }
    }
}

int in[maxn],out[maxn],t=0 ;
void dfs0(int x)
{
    in[x]=++t ;
    for(auto i : v2[x]) dfs0(i) ;
    out[x]=++t ;
}

bool is_fa(int x,int y) /** x is fa of y , x = y -> return true */
{
    return in[x]<=in[y] && out[x]>=out[y] ;
}

int ans[maxn] ;
priority_queue<Q> pq2[maxn] ;
int id[maxn] ;

int merge(int x,int y)
{
    if(pq2[x].size()<pq2[y].size()) swap(x,y) ;
    while(!pq2[y].empty())
        pq2[x].push(pq2[y].top()) , pq2[y].pop() ;
    return x ;
}

void dfs1(int x)
{
    id[x]=x ;
    for(auto i : v2[x]) dfs1(i) , id[x]=merge(id[x],id[i]) ;
    for(auto i : v[x]) if(i.to!=fa[x])
        pq2[id[x]].push((Q){i.to,d[i.to]+d[x]+i.dis}) ;
    while(!pq2[id[x]].empty() && is_fa(x,pq2[id[x]].top().id)) pq2[id[x]].pop() ;
    ans[x]= pq2[id[x]].empty() ? -1 : (pq2[id[x]].top().dis - d[x]) ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    Dijkstra(1) ;
    dfs0(1) ;
    dfs1(1) ;
    for(int i=2;i<=n;i++) printf("%d\n",ans[i]) ;
}
