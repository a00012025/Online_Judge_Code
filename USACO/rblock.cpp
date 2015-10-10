#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=250+5,maxm=25000+10 ;

struct P{int x,y,dis ;};
vector<P> edge ;
bool can[maxm] ;
vector<int> v[maxn] ;

struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};
priority_queue<Q> pq ;
bool done[maxn] ;
int n,d[maxn],fa[maxn] ;
int Dijkstra(int st,int ed,int type)
{
    while(!pq.empty()) pq.pop() ;
    fill(d,d+n+1,INF) ; memset(done,0,sizeof(done)) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id==ed) return d[u.id] ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(can[i])
        {
            int to=edge[i].x==u.id ? edge[i].y : edge[i].x ;
            if(d[to] > d[u.id] + edge[i].dis)
            {
                d[to]=d[u.id]+edge[i].dis ;
                pq.push((Q){to,d[to]}) ;
                if(type) fa[to]=i ;
            }
        }
    }
    return INF ;
}

main()
{
    freopen("rblock.in","r",stdin) ;
    freopen("rblock.out","w",stdout) ;
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        edge.push_back((P){x,y,dis}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
        can[i]=1 ;
    }

    int old=Dijkstra(1,n,1) , ans=0 ;
    for(int i=n;i!=1;)
    {
        int x=fa[i] ;
        int from=edge[x].x==i ? edge[x].y : edge[x].x ;
        int val=edge[x].dis ;
        can[x]=0 ; val=min(val,Dijkstra(1,n,0)-old) ;
        ans=max(ans,val) ;
        can[x]=1 ; i=from ;
    }
    printf("%d\n",ans) ;
}
