#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=500+10 ;
struct Edge{int from,to ; LL cap,flow,cost ; int type ;};
vector<Edge> edge ;
vector<int> G[maxn] ;
int fa[maxn] ;
LL a[maxn],d[maxn],flow,cost ;
bool inq[maxn] ;

void init()
{
    edge.clear() ;
    for(int i=0;i<maxn;i++) G[i].clear() ;
    cost=0 ; flow=0 ;
}

void add_edge(int from,int to,LL cap,LL cost,int type)
{
    edge.push_back((Edge){from,to,cap,0,cost,type}) ;
    edge.push_back((Edge){to,from,0,0,-cost,type}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

int Bellman_Ford(int st,int ed)
{
    queue<int> q ;
    for(int i=0;i<maxn;i++) {a[i]=0 ; d[i]=INF ;}
    memset(inq,0,sizeof(inq)) ;
    a[st]=INF ; d[st]=0 ; inq[st]=1 ; q.push(st) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<G[u].size();i++)
        {
            Edge e=edge[G[u][i]] ;
            if(e.flow<e.cap && d[e.to]>d[u]+e.cost)
            {
                d[e.to]=d[u]+e.cost ;
                a[e.to]=min(a[u],e.cap-e.flow) ;
                fa[e.to]=G[u][i] ;
                if(!inq[e.to]) {q.push(e.to) ; inq[e.to]=1 ;}
            }
        }
    }
    if(d[ed]==INF) return false ;
    for(int j=ed;j!=st;j=edge[fa[j]].from)
    {
        edge[fa[j]].flow += a[ed] ;
        edge[fa[j]^1].flow -= a[ed] ;
    }
    flow += a[ed] ;
    cost += a[ed]*d[ed] ;
    return true ;
}

LL MCMF(int st,int ed)
{
    flow=cost=0 ;
    while(Bellman_Ford(st,ed)) ;
    return flow ;
}

int in[maxn],out[maxn] ;
LL dis[maxn][maxn] ;
main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        init() ;
        memset(in,0,sizeof(in)) ;
        memset(out,0,sizeof(out)) ;
        int n,m ; scanf("%d%d",&n,&m) ;

        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            dis[i][j]=INF ; /// Floyd Warshall

        LL all=0LL ;
        bool have_res=0 ;
        while(m--)
        {
            int x,y ; LL p,s ; int tp ;
            scanf("%d%d%lld%lld%d",&x,&y,&p,&s,&tp) ;
            dis[x][y]=min(dis[x][y],p-s) ;
            if(tp)
            {
                all+=p ;
                out[x]++ ; in[y]++ ;
                have_res=1 ;
                continue ;
            }
            if(s>=p)
            {
                add_edge(x,y,1,s-p,0) ;
                out[x]++ ; in[y]++ ;
                all+=p ;
            }
            else
            {
                add_edge(y,x,1,p-s,1) ;
                all+=s ;
            }
        }

        LL maxf=0 ;
        for(int i=1;i<=n;i++) if(in[i]!=out[i])
        {
            LL dif=in[i]-out[i] ;
            if(dif>0) add_edge(i,n+1,dif,0,maxn) , maxf+=dif ;
            else add_edge(0,i,-dif,0,maxn) ;
        }
        printf("Case %d: ",++tc) ;
        if(MCMF(0,n+1)!=maxf) printf("impossible\n") ;
        else
        {
            bool full=1 ;
            for(int i=0;i<edge.size();i+=2)
                if(edge[i].type<=1 &&
                   edge[i].type==edge[i].flow)
                {full=0 ; break ;}

            if(have_res || !full)
                {printf("%lld\n",all+cost) ; continue ;}

            for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;

            LL add=INF ;
            for(int i=1;i<=n;i++) add=min(add,dis[i][i]) ;
            if(add==INF) printf("impossible\n") ;
            else printf("%lld\n",all+cost+add) ;
        }
    }
}
