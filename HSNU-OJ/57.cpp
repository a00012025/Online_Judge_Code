#include<bits/stdc++.h>
#define DB double
#define INF 100000000
using namespace std;
const int maxn=2010 ;
const DB eps=1e-10 ;
struct P{int from,to ; DB dis ; };
vector<int> v[maxn] ;
vector<P> edge ;
int n,vis[maxn] ;
DB w[maxn] ;

bool dfs(int x)
{
    vis[x]=0 ;
    for(int i=0;i<v[x].size();i++)
    {
        int to= edge[v[x][i]].to  ;
        if(vis[to]==0 || (vis[to]==-1 && !dfs(to))) return 0 ;
    }
    vis[x]=1 ;
    return 1 ;
}

bool have_cycle()
{
    memset(vis,-1,sizeof(vis)) ;
    for(int i=1;i<=2*n+1;i++) if(vis[i]==-1 && !dfs(i)) return 1 ;
    return 0 ;
    /// point : 1~2*n+1
}

DB d[maxn] ;
bool inq[maxn] ;
int cnt[maxn] ;
bool BellmanFord(int st)
{
    for(int i=1;i<=2*n+1;i++) d[i]=INF ;
    d[st]=0.0 ;
    memset(inq,0,sizeof(inq)) ;
    memset(cnt,0,sizeof(cnt)) ;
    queue<int> q ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
        {
            int to= edge[v[u][i]].to ;
            if(d[to]>d[u]+edge[v[u][i]].dis+eps)
            {
                d[to]=d[u]+edge[v[u][i]].dis ;
                if(++cnt[to]>2*n+2) return 1 ;
                if(!inq[to]) q.push(to) ;
                inq[to]=1 ;
            }
        }
    }
    return 0 ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%lf",&w[i]) ;
    for(int i=1;i<=n;i++)
    {
        edge.push_back((P){i,n+i,w[i]}) ;
        v[i].push_back(i-1) ;
    }
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        edge.push_back((P){x+n,y,(DB)dis}) ;
        int sz=edge.size() ;
        v[x+n].push_back(sz-1) ;
    }

    for(int i=1;i<=n;i++)
    {
        edge.push_back((P){2*n+1,i,0}) ;
        int sz=edge.size() ;
        v[2*n+1].push_back(sz-1) ;
    }

    for(int i=0;i<n;i++) edge[i].dis=-INF ;
    if(!BellmanFord(2*n+1)){ printf("0\n") ; return 0 ; }

    //if(!have_cycle()) { printf("0\n") ; return 0 ; }
    DB l=-1.0 , r=10000000000.0 ;

    while(r-l>eps)
    {
        DB mid=(r+l)/2 ;
        for(int i=0;i<n;i++) edge[i].dis=-w[i+1]/mid ;
        if(BellmanFord(2*n+1)) l=mid ;
        else r=mid ;
    }
    printf("%.2f\n",r) ;
}
