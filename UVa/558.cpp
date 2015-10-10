#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#define INF 200000000
using namespace std;
struct P {int to,w ;}  ;
vector<P> v[2000] ;
queue<int> q ;
int cnt[2000],d[2000],n ;
bool inq[2000] ;

bool bellmanford(int s)
{
    memset(cnt,0,sizeof(cnt)) ;
    memset(inq,0,sizeof(inq)) ;
    while(!q.empty()) q.pop() ;
    for(int i=0;i<=n;i++) d[i]=INF ;
    d[s]=0 ; q.push(s) ; inq[s]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++) if(d[v[u][i].to] > d[u]+v[u][i].w)
        {
            d[v[u][i].to] = d[u]+v[u][i].w ;
            if(!inq[v[u][i].to]) q.push(v[u][i].to) ;
            inq[v[u][i].to]=1 ;
            if(++cnt[v[u][i].to] > n+1) return 0 ;
        }
    }
    return 1 ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m ;
        scanf("%d %d",&n,&m) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=m;i++)
        {
            int a,b,w ;
            scanf("%d %d %d",&a,&b,&w) ;
            v[a].push_back((P){b,w}) ;
        }
        for(int i=0;i<n;i++) v[n].push_back((P){i,1}) ;
        if(!bellmanford(n)) printf("possible\n") ;
        else printf("not possible\n") ;
    }
}
