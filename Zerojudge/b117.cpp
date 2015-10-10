#include<bits/stdc++.h>
#define LL long long
#define INF 1100000000
using namespace std;
struct P{int to,dis;};
const int maxn=1000000+10 ;
vector<P> v[2][maxn] ;
int n ;

struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};
priority_queue<Q> pq ;
bool done[maxn] ;
int d[maxn] ;
LL dijkstra(int st,int id)
{
    for(int i=1;i<=n;i++) d[i]=INF ; d[st]=0 ;
    while(!pq.empty()) pq.pop() ;
    memset(done,0,sizeof(done)) ;
    pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[id][u.id].size();i++)
        {
            if( d[v[id][u.id][i].to] > d[u.id]+v[id][u.id][i].dis )
            {
                d[v[id][u.id][i].to] = d[u.id]+v[id][u.id][i].dis ;
                pq.push((Q){v[id][u.id][i].to,d[v[id][u.id][i].to]}) ;
            }
        }
    }
    LL ret=0LL ;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==INF) return -1 ;
        ret+=d[i] ;
    }
    return ret ;
}

main()
{
    int m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) v[0][i].clear() , v[1][i].clear() ;
        while(m--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v[0][x].push_back((P){y,dis}) ;
            v[1][y].push_back((P){x,dis}) ;
        }

        LL ans1=dijkstra(1,0) , ans2=dijkstra(1,1) ;
        if(ans1==-1 || ans2==-1) printf("0\n") ;
        else printf("%lld\n",ans1+ans2) ;
    }
}
