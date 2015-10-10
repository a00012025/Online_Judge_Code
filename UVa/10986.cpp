#include<stdio.h>
#include<vector>
#include<map>
#include<string.h>
#define INF 2000000000
using namespace std;
typedef struct {int id,w ;} P ;
int ans[20010] ;
bool vis[20010] ;
vector<P> v[20010] ;

void dfs(int n,int w)
{
    ans[n]=w ;
    for(int i=0;i<v[n].size();i++)
    {
        int cost=v[n][i].w ;
        if(ans[n]+cost<ans[v[n][i].id]) dfs(v[n][i].id,ans[n]+cost) ;
    }
}

void dfs2(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++)
        if(!vis[v[n][i].id]) dfs2(v[n][i].id);
}

main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,st,ed ;
        scanf("%d%d%d%d",&n,&m,&st,&ed) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=m;i++)
        {
            int a,b,cost ;
            scanf("%d%d%d",&a,&b,&cost);
            v[a].push_back((P){b,cost}) ;
            v[b].push_back((P){a,cost}) ;
        }
        dfs2(st) ;
        if(!vis[ed]) {printf("Case #%d: unreachable\n",++tc) ;continue ;}
        for(int i=0;i<n;i++) ans[i]=INF ;
        dfs(st,0) ;
        printf("Case #%d: %d\n",++tc,ans[ed]) ;
    }
}
