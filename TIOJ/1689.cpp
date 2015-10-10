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
        for(auto i : v[u.id]) if(d[u.id]+i.dis < d[i.to])
            d[i.to]=d[u.id]+i.dis ,
            pq.push((Q){i.to,d[i.to]}) ;
    }
}

int ans[maxn] ;
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
    fill(ans+1,ans+n+1,INF) ;
    for(int i=1;i<=n;i++) for(auto j : v[i])
        if(d[j.to]+j.dis!=d[i] &&
           d[i]+j.dis != d[j.to])
        ans[j.to]=min(ans[j.to],d[i]+j.dis) ;
    for(int i=2;i<=n;i++) printf("%d\n",ans[i]==INF?-1:ans[i]) ;
}
