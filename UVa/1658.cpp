#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF=100000000 ;
struct P {int from,to,cap,flow,cost;};
vector<P> edge ;
vector<int> G[2001] ;
int a[2001],d[2001],fa[2001],ans ;
bool inq[2001] ;

void init()
{
    for(int i=0;i<=2000;i++) G[i].clear() ;
    edge.clear() ;
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
    for(int i=0;i<=2000;i++) {a[i]=0 ; d[i]=INF ; inq[i]=0 ;}
    queue<int> q ;
    a[st]=INF ; d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<G[u].size();i++)
        {
            P e=edge[G[u][i]] ;
            if(e.cap>e.flow && d[u]+e.cost < d[e.to])
            {
                a[e.to]=min(a[u],e.cap-e.flow) ;
                d[e.to]=d[u]+e.cost ;
                fa[e.to]=G[u][i] ;
                if(!inq[e.to]) q.push(e.to) ;
                inq[e.to]=1 ;
            }
        }
    }
    if(d[ed]==INF) return false ;
    for(int j=ed;j!=st;j=edge[fa[j]].from)
    {
        edge[fa[j]].flow += a[ed] ;
        edge[fa[j]^1].flow -= a[ed] ;
    }
    ans+=a[ed]*d[ed] ;
    return true ;
}

int MCMF(int st,int ed)
{
    ans=0 ;
    while(Bellman_Ford(st,ed)) ;
    return ans ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init() ;
        for(int i=2;i<n;i++) add_edge(i,i+n,1,0) ;
        while(m--)
        {
            int a,b,cost ;
            scanf("%d%d%d",&a,&b,&cost) ;
            if(a!=1 && a!=n) add_edge(n+a,b,1,cost) ;
            else if(a==1) add_edge(1,b,1,cost) ;
            else add_edge(n,b,1,cost) ;
        }
        add_edge(0,1,2,0) ;
        printf("%d\n",MCMF(0,n)) ;
    }
}
