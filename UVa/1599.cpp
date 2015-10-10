#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
struct P {
    int to,col;
    bool operator < (const P &rhs) const
    {
        return col<rhs.col ;
    }
};
vector<P> v[100001] ;
queue<int> q ;
P fa[100001] ;
bool vis[100001] ;
int lev[100001],ans[100001] ;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n>=2 && m>=1)
    {
        for(int i=0;i<=n;i++) {v[i].clear() ; lev[i]=INF ; ans[i]=INF ;}
        while(m--)
        {
            int a,b,c ;
            scanf("%d%d%d",&a,&b,&c) ;
            v[a].push_back((P){b,c}) ;
            v[b].push_back((P){a,c}) ;
        }
        memset(vis,0,sizeof(vis)) ;
        while(!q.empty()) q.pop() ;
        q.push(n) ; lev[n]=0 ; vis[n]=1 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<v[u].size();i++) if(!vis[v[u][i].to])
            {
                lev[v[u][i].to]=lev[u]+1 ;
                vis[v[u][i].to]=1 ;
                q.push(v[u][i].to) ;
            }
        }
        int k=lev[1] ;
        printf("%d\n",k) ;
        memset(vis,0,sizeof(vis)) ;
        q.push(1) ; vis[1]=1 ; ans[0]=0 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            int l=lev[u] ;
            if(u!=1 && fa[u].col>ans[k-l]) continue ;
            for(int i=0;i<v[u].size();i++) if(lev[v[u][i].to]==l-1)
            {
                if(v[u][i].col > ans[k-l+1]) continue ;
                ans[k-l+1]=v[u][i].col ;
                fa[v[u][i].to]=(P){u,v[u][i].col} ;
                if(!vis[v[u][i].to]) q.push(v[u][i].to) ;
                vis[v[u][i].to]=1 ;
            }
        }
        for(int i=1;i<=k;i++) printf("%d%c",ans[i],i==k?'\n':' ') ;
    }
}
