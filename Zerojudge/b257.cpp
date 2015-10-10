#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000,INF=100000000 ;
struct P{int from,to,flow,cap,cost;};
vector<P> edge ;
vector<int> G[maxn] ;
int a[maxn],d[maxn],fa[maxn] ;

void init()
{
    for(int i=0;i<maxn;i++) G[i].clear() ;
    edge.clear() ;
}

void add_edge(int from,int to,int cap,int cost)
{
    edge.push_back((P){from,to,0,cap,cost}) ;
    edge.push_back((P){to,from,0,0,-cost}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

bool inq[maxn] ;
void MCMF(int st,int ed,int &flow,int &cost)
{
    flow=cost=0 ;
    while(1)
    {
        for(int i=0;i<maxn;i++) a[i]=0 , d[i]=INF , inq[i]=0 ;
        a[st]=INF ; d[st]=0 ;
        queue<int> q ; q.push(st) ; inq[st]=1 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ; inq[u]=0 ;
            for(int i=0;i<G[u].size();i++)
            {
                P e=edge[G[u][i]] ;
                if(d[e.to]>d[u]+e.cost && e.flow<e.cap)
                {
                    d[e.to]=d[u]+e.cost ;
                    a[e.to]=min(a[u],e.cap-e.flow) ;
                    fa[e.to]=G[u][i] ;
                    if(!inq[e.to]) q.push(e.to) ; inq[e.to]=1 ;
                }
            }
        }
        if(d[ed]==INF) break ;
        flow+=a[ed] ; cost+=a[ed]*d[ed] ;
        for(int j=ed;j!=st;j=edge[fa[j]].from)
        {
            edge[fa[j]].flow +=a[ed] ;
            edge[fa[j]^1].flow -=a[ed] ;
        }
    }
    return ;
}

char c[30][30] ;
int n,m,id[30][30],cnt ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) scanf("%s",c[i]) ;
        init() ; cnt=0 ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(c[i][j]=='.') id[i][j]=cnt++ ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(c[i][j]=='.')
        {
            add_edge(2*cnt,id[i][j],2,0) ;
            add_edge(id[i][j]+cnt,2*cnt+1,2,0) ;
            if(i==0 || j==0 || i==n-1 || j==m-1)
                add_edge(id[i][j],id[i][j]+cnt,1,1) ;
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z] , ny=j+dy[z] ;
                if(nx<0 || nx>=n || ny<0 || ny>=m || c[nx][ny]!='.') continue ;
                add_edge(id[i][j],id[nx][ny]+cnt,1,0) ;
            }
        }
        int flow,cost ;
        MCMF(2*cnt,2*cnt+1,flow,cost) ;
        if(flow!=2*cnt) printf("-1\n") ;
        else if(cnt==0) printf("-1\n") ;
        else printf("%d\n",cost/2) ;
    }
}
