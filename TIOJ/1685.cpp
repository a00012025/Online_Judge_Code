#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
const int maxn=200+10 ;
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
priority_queue<Q> pq ;
bool done[maxn] ;
int n,val[maxn] ;
void Dijkstra(int st,int *d)
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    while(!pq.empty()) pq.pop() ;
    memset(done,0,sizeof(done)) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id])
            if(val[i.to]<=val[st] && d[i.to]>d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

int dis[maxn][maxn] ;

main()
{
    int m,Q,tc=0 ;
    while(scanf("%d%d%d",&n,&m,&Q)==3 && n+m+Q)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]) , v[i].clear() ;
        while(m--)
        {
            int x,y,d ; scanf("%d%d%d",&x,&y,&d) ;
            v[x].push_back((P){y,d}) ;
            v[y].push_back((P){x,d}) ;
        }
        for(int i=1;i<=n;i++) Dijkstra(i,dis[i]) ;

        if(tc) printf("\n") ;
        printf("Case #%d\n",++tc) ;
        while(Q--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            int ans=INF ;
            for(int i=1;i<=n;i++)
                if(dis[i][x]!=INF && dis[i][y]!=INF)
                ans=min(ans,dis[i][x]+dis[i][y]+val[i]) ;
            printf("%d\n",ans==INF ? -1 : ans) ;
        }
    }
}
