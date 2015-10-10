#include<bits/stdc++.h>
#define INF 1000000
#define FOR(x,y) for(int x=0;x<(y).size();x++)
using namespace std;
const int maxn=600+10 ;
struct P{int to,dis;};
vector<P> v[maxn] ;

int n,d[maxn],cnt[maxn] ;
bool inq[maxn] ;
queue<int> q ;
int BellmanFord()
{
    for(int i=1;i<=n;i++)
        v[n+1].push_back((P){i,0}) , d[i]=INF ;
    d[n+1]=0 ; q.push(n+1) ; inq[n+1]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        FOR(j,v[u]) if(d[v[u][j].to] > d[u]+v[u][j].dis)
        {
             P i=v[u][j] ;
             d[i.to]=d[u]+i.dis ;
             if(++cnt[i.to] > n+1) return -1 ;
             if(!inq[i.to]) q.push(i.to) ;
             inq[i.to]=1 ;
        }
    }
    return 1 ;
}

vector<int> scc[maxn],v1[maxn],v2[maxn] ;
int topo[maxn] , t , scnt , gp[maxn] ;
bool vis[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    FOR(i,v1[x]) if(!vis[v1[x][i]])
        dfs1(v1[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[scnt].push_back(x) ; gp[x]=scnt ;
    FOR(i,v2[x]) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

void SCC()
{
    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    scnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]])
        scnt++ , dfs2(topo[i]) ;
}

int dis[maxn][maxn] ;
int cal(int id)
{
     FOR(x,scc[id])
     {
          int i=scc[id][x] ;
          FOR(y,v[i])
          {
               P j=v[i][y] ;
               if(gp[j.to]==id) dis[i][j.to]=min(dis[i][j.to],j.dis) ;
          }
     }

     FOR(x,scc[id])
     {
          int k=scc[id][x] ;
          FOR(y,scc[id])
          {
               int i=scc[id][y] ;
               FOR(z,scc[id])
               {
                    int j=scc[id][z] ;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
               }
          }
     }



    int ret=0 ;
    FOR(x,scc[id])
     {
          int i=scc[id][x] ;
          FOR(y,scc[id])
          {
               int j=scc[id][y] ;
               ret=max(ret,dis[i][j]) ;
          }
     }

    return ret ;
}

main()
{
    int m1,m2 ; scanf("%d%d%d",&n,&m1,&m2) ;
    while(m1--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ; v1[y].push_back(x) ;
        v2[x].push_back(y) ; v2[y].push_back(x) ;
        v[x].push_back((P){y,-1}) ;
        v[y].push_back((P){x,1}) ;
    }
    while(m2--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ; v2[y].push_back(x) ;
        v[x].push_back((P){y,0}) ;
    }

    if(BellmanFord()==-1) { printf("NIE\n") ; return 0 ; }

    SCC() ;

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dis[i][j]= (i==j ? 0 : INF) ;

    int ans=0 ;
    for(int i=1;i<=scnt;i++) ans+=cal(i)+1 ;
    printf("%d\n",ans) ;
}
