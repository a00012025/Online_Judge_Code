#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=10000000;
struct P {int from,to,cap,flow,cost;};
vector<P> edge ;
vector<int> G[10101] ;
int n,cost;
int a[10101],d[10101],fa[10101] ;
bool inq[10101] ;

void init()
{
    edge.clear() ;
    for(int i=0;i<=n+1;i++) G[i].clear() ;
}

void add_edge(int from,int to,int cap,int cost)
{
    edge.push_back((P){from,to,cap,0,cost}) ;
    edge.push_back((P){to,from,0,0,-cost}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

bool Bellman_Ford(int st,int ed)
{
    queue<int> q ;
    for(int i=0;i<=n+1;i++) {a[i]=0 ; d[i]=INF ;}
    memset(inq,0,sizeof(inq)) ;
    a[st]=INF ; d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<G[u].size();i++)
        {
            P e=edge[G[u][i]] ;
            if(d[e.to] > d[u]+e.cost && e.cap>e.flow)
            {
                d[e.to]=d[u]+e.cost ;
                a[e.to]=min(a[u],e.cap-e.flow) ;
                fa[e.to]=G[u][i] ;
                if(!inq[e.to]) q.push(e.to) ;
                inq[e.to]=1 ;
            }
        }
    }
    if(d[ed]==INF) return 0;
    cost += a[ed]*d[ed] ;
    for(int j=ed;j!=st;j=edge[fa[j]].from)
    {
        edge[fa[j]].flow += a[ed] ;
        edge[fa[j]^1].flow -= a[ed] ;
    }
    return 1;
}

int MCMF(int st,int ed)
{
    cost=0 ;
    while(Bellman_Ford(st,ed)) ;
    return cost ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        init() ;
        for(int i=1;i<=n;i++)
        {
            int a,num,k ;
            scanf("%d%d%d",&a,&num,&k) ;
            add_edge(a,n+1,1,0) ;
            if(num) add_edge(0,a,num,0) ;
            while(k--)
            {
                int b;
                scanf("%d",&b) ;
                add_edge(a,b,n+2,1) ;
                add_edge(b,a,n+2,1) ;
            }
        }
        printf("%d\n",MCMF(0,n+1)) ;
    }
}
