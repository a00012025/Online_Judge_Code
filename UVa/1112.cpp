#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
const int INF=100000000 ;
struct P
{
    int id,w ;
    bool operator < (const P &rhs) const
    {
        return w>rhs.w ;
    }
};
int d[101],n ;
vector<P> v[101] ;

void dijkstra(int st)
{
    priority_queue<P> pq ;
    for(int i=1;i<=n;i++) d[i]=INF ;
    d[st]=0 ; pq.push((P){st,0}) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].id] > v[u.id][i].w+u.w)
            {
                d[v[u.id][i].id] = v[u.id][i].w+u.w ;
                pq.push((P){v[u.id][i].id,d[v[u.id][i].id]}) ;
            }
        }
    }

}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int st,t,m ;
        scanf("%d%d%d%d",&n,&st,&t,&m) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w) ;
            v[b].push_back((P){a,w}) ;
        }
        dijkstra(st) ;
        int ans=0 ;
        for(int i=1;i<=n;i++) if(d[i]<=t) ans++ ;
        printf("%d\n",ans) ;
        if(T)printf("\n");
    }
}
