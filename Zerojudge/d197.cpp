#include<stdio.h>
#include<string.h>
#include<vector>
#define N 100100
using namespace std;
vector<int> v1[N],v2[N],newv[N] ;
int topo[N],scc[N],t,cnt ;
bool vis[N],in[N] ;

void dfs1(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    for(int i=0;i<v1[n].size();i++) dfs1(v1[n][i]) ;
    topo[--t]=n ;
}

void dfs2(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    scc[n]=cnt ;
    for(int i=0;i<v2[n].size();i++) dfs2(v2[n][i]) ;
}

main()
{
    int T ;
    scanf("%d",&T);
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=0;i<=n;i++)
            {v1[i].clear() ; v2[i].clear() ; newv[i].clear() ;}
        memset(in,0,sizeof(in)) ;
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            v1[a].push_back(b) ;
            v2[b].push_back(a) ;
        }
        memset(vis,0,sizeof(vis)) ;
        t=n+1 ;
        for(int i=1;i<=n;i++) dfs1(i) ;
        //for(int i=1;i<=n;i++) printf("%d,",topo[i]);
        //printf("\n") ;
        memset(vis,0,sizeof(vis)) ;
        cnt=0 ;
        for(int i=1;i<=n;i++)
        {
            if(vis[topo[i]]) continue ;
            cnt++ ;
            dfs2(topo[i]) ;
        }
        for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
        {
            int a=i , b=v1[i][j] ;
            if(scc[a]==scc[b]) continue ;
            in[scc[b]]=1 ;
        }
        int ans=0 ;
        for(int i=1;i<=cnt;i++) if(!in[i]) ans++ ;
        printf("%d\n",ans) ;

    }
}
