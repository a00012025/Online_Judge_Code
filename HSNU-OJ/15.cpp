//#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
struct P{int ed,dis ;};
struct Q
{
    int x,id,dis;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};
vector<P> v[101] ;
int d[101][101],n ;
bool done[101][101] ;

int dijks(int st)
{
    memset(done,0,sizeof(done)) ;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) d[i][j]=INF ;
    priority_queue<Q> pq ;
    for(int i=0;i<v[st].size();i++)
        d[i][v[st][i].ed]=min(d[i][v[st][i].ed],v[st][i].dis) ,
        pq.push((Q){i,v[st][i].ed,d[i][v[st][i].ed]}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.x][u.id]) continue ;
        done[u.x][u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++) if(v[u.id][i].ed != v[st][u.x].ed && v[u.id][i].ed!=st)
        {
            if(d[u.x][v[u.id][i].ed] > d[u.x][u.id] + v[u.id][i].dis)
            {
                d[u.x][v[u.id][i].ed] = d[u.x][u.id] + v[u.id][i].dis ;
                pq.push((Q){u.x,v[u.id][i].ed,d[u.x][u.id] + v[u.id][i].dis}) ;
            }
        }
    }
    int ret=INF ;
    for(int i=0;i<v[st].size();i++) for(int j=i+1;j<v[st].size();j++)
        if(v[st][i].ed!=v[st][j].ed)
        ret=min(ret,d[i][v[st][j].ed]+v[st][j].dis) ;
    return ret ;
}

bool vis[101] ;
main()
{
    srand(time(NULL)) ;
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    //dijks(1) ;
    int ans=INF ;
    for(int i=1;i<=n && i<=14;i++)
    {
        int x ;
        while(1)
        {
            x=((rand()%n)+n)%n+1 ;
            if(!vis[x]) break ;
        }
        vis[x]=1 ; ans=min(ans,dijks(x)) ;
    }
    if(ans==INF) printf("No solution.\n") ;
    else printf("%d\n",ans) ;
}
