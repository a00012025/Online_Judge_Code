#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=100000+10 ;

struct P{int to,dis ;};
vector<P> v[maxn] ;

struct Q
{
    int id ; LL val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};
priority_queue<Q> pq ;

LL d[maxn] ;
bool done[maxn] ;
void Dijkstra(int st)
{
    fill(d,d+maxn,INF) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i.to]>d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

int dis0[maxn] ;
int ind[maxn] ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    int ans=0 ;
    for(int i=1;i<=k;i++)
    {
        int x,dis ; scanf("%d%d",&x,&dis) ;
        if(dis0[x]) ans++ , dis0[x]=min(dis0[x],dis) ;
        else dis0[x]=dis ;
    }
    for(int i=1;i<=n;i++) if(dis0[i])
        v[1].push_back((P){i,dis0[i]}) ,
        v[i].push_back((P){1,dis0[i]}) ;

    Dijkstra(1) ;
    for(int i=1;i<=n;i++) for(auto j : v[i]) if(d[i]+j.dis==d[j.to])
        ind[j.to]++ ;
    for(int i=1;i<=n;i++) if(dis0[i])
    {
        if(d[i]==dis0[i] && ind[i]>1) ans++ ;
        else if(d[i]!=dis0[i]) ans++ ;
    }
    printf("%d\n",ans) ;
}
