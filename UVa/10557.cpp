#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#define INF 100000000
using namespace std;
vector<int> v[101] ;
queue<int> q ;
int d[101],w[101],cnt[101],n ;
bool inq[101],done[101] ;

bool bellmanford(int s)
{
    memset(inq,0,sizeof(inq)) ;
    memset(cnt,0,sizeof(cnt)) ;
    memset(done,0,sizeof(done)) ;
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) d[i]=-INF ;
    d[s]=100 ; q.push(s) ; inq[s]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        if(u==n) return 1 ;
        if(done[u]) continue ;
        if(d[u]==INF) done[u]=1 ;
        for(int i=0;i<v[u].size();i++)
            if(d[u]+w[v[u][i]]>0 && d[u]+w[v[u][i]]>d[v[u][i]])
            {
                d[v[u][i]]=d[u]+w[v[u][i]] ;
                if(++cnt[v[u][i]] > n+1) d[v[u][i]]=INF ;
                if(!inq[v[u][i]]) q.push(v[u][i]) ;
                inq[v[u][i]]=1 ;
            }
    }
    return 0 ;
}

main()
{
    while(scanf("%d",&n)==1 && n!=-1)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int num,a ;
            scanf("%d%d",&w[i],&num) ;
            while(num--) {scanf("%d",&a) ; v[i].push_back(a) ;}
        }
        if(bellmanford(1)) printf("winnable\n") ;
        else printf("hopeless\n") ;
    }
}
