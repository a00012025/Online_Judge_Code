#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=1010 ;
const DB eps=1e-8 ;
struct P{int ed ; DB dis ;};
vector<P> v[maxn] ;
int n ;
DB w[maxn] ;

int vis[maxn],dcnt=0 ;
bool dfs(int x)
{
    vis[x]=++dcnt ;
    for(int i=0;i<v[x].size();i++)
    {
        int to= v[x][i].ed  ;
        if(vis[to]!=-1 && vis[to]<vis[x]) return 0 ;
        if(vis[to]==-1 && !dfs(to)) return 0 ;
    }
    return 1 ;
}

bool have_cycle()
{
    memset(vis,-1,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(vis[i]==-1 && !dfs(i)) return 1 ;
    return 0 ;
}

DB d[maxn] ;
bool inq[maxn] ;
int cnt[maxn] ;
bool BellmanFord(DB mul)
{
    memset(inq,0,sizeof(inq)) ;
    memset(cnt,0,sizeof(cnt)) ;
    queue<int> q ;
    for(int i=1;i<=n;i++) d[i]=0.0 , q.push(i) , inq[i]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
        {
            int to= v[u][i].ed ;
            if(d[to]>d[u]+mul*v[u][i].dis-w[to])
            {
                d[to]=d[u]+mul*v[u][i].dis-w[to] ;
                if(++cnt[to]>n) return 1 ;
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
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,(DB)dis}) ;
    }

    if(!have_cycle()) { printf("0\n") ; return 0 ; }

    DB l=0.0 , r=100000000.0 ;
    while(r-l>eps)
    {
        DB mid=(r+l)/2 ;
        if(BellmanFord(mid)) l=mid ;
        else r=mid ;
    }
    printf("%.2f\n",r) ;
}
