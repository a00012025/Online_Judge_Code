#include<bits/stdc++.h>
#define INF 1000000000
#define DB double
using namespace std;
struct P{int ed,dis;};
struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

vector<P> v[3001] ;

int n,k,d[3001] ;
bool done[3001] ;
void dijkstra()
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    memset(done,0,sizeof(done)) ;
    priority_queue<Q> pq ;
    while(k--)
    {
        int x ; scanf("%d",&x) ;
        d[x]=0 ; pq.push((Q){x,0}) ;
    }
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].ed] > d[u.id]+v[u.id][i].dis)
            {
                d[v[u.id][i].ed] = d[u.id]+v[u.id][i].dis ;
                pq.push((Q){v[u.id][i].ed,d[u.id]+v[u.id][i].dis}) ;
            }
        }
    }
}

main()
{
    int m ; scanf("%d%d%d",&n,&m,&k) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    dijkstra() ;
    DB ans=0.0 ;
    for(int i=1;i<=n;i++)
    {
        int x=d[i] ; //printf("d[%d]=%d\n",i,x) ;
        ans=max(ans,(DB)x) ;
        for(int j=0;j<v[i].size();j++)
        {
            int y=d[v[i][j].ed] , dis=v[i][j].dis ;
            ans=max(ans, ((DB)x+y+dis)/2 ) ;
        }
    }
    printf("%.0lf\n",ans) ;
}
