#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=1000+10 ;
struct P{int to,dis;};

struct Q
{
    int id ;
    LL val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};

priority_queue<Q> pq ;
LL d[maxn] ;
bool done[maxn] ;

vector<P> v[maxn] ;
int n ;

LL Dijkstra(int st,int ed)
{
    while(!pq.empty()) pq.pop() ;
    for(int i=1;i<=n;i++) d[i]=INF , done[i]=0 ;
    d[st]=0 ; pq.push((Q){st,0LL}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i.to]>d[u.id]+i.dis)
        {
            d[i.to]=d[u.id]+i.dis ;
            pq.push((Q){i.to,d[i.to]}) ;
        }
    }
    return d[ed] ;
}

main()
{
    int m,st,ed ;
    while(scanf("%d%d%d%d",&n,&m,&st,&ed)!=EOF)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v[x].push_back((P){y,dis}) ;
            v[y].push_back((P){x,dis}) ;
        }
        LL ans=Dijkstra(st,ed) ;
        if(ans==INF) printf("He is very hot\n") ;
        else printf("%lld\n",ans) ;
    }
}
