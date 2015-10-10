#include<bits/stdc++.h>
#define INF (1LL<<60)
#define LL long long
using namespace std;
const int maxn=50000+10 ;
struct P{int to,dis;};
vector<P> v[maxn] ;
int n ;

struct Q
{
    int id ; LL dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

priority_queue<Q> pq ;
LL d[maxn] ;
bool done[maxn] ;
void Dijkstra(int st)
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    d[st]=0 ; pq.push((Q){st,0LL}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id])
            if(d[i.to] > d[u.id]+i.dis)
        {
            d[i.to]=d[u.id]+i.dis ;
            pq.push((Q){i.to,d[i.to]}) ;
        }
    }
}

int w[maxn] ;
main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    Dijkstra(1) ;
    for(int i=1;i<=n;i++) if(d[i]==INF)
        { printf("No Answer\n") ; return 0 ; }
    LL ans=0LL ;
    for(int i=1;i<=n;i++) ans+=((LL)w[i])*d[i] ;
    printf("%I64d\n",ans) ;
}
