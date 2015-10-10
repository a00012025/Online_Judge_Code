#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000] ;
bool G[301][301] ;
int n,m,vis[1000] ;

bool solve()
{
    for(int i=n;i<=2*n;i++) vis[i]=-1 ;
    for(int i=0;i<n;i++) if(v[i].size())
    {
        if(vis[v[i][0]]==-1)
            for(int j=0;j<v[i].size();j++)
            {
                if(vis[v[i][j]]!=-1) return 0;
                vis[v[i][j]]=i ;
            }
        else
        {
            int gp=vis[v[i][0]] ;
            if(v[gp].size()!=v[i].size()) return 0;
            for(int j=0;j<v[i].size();j++)
                if(vis[v[i][j]]!=gp) return 0;
        }
    }
    return 1;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        memset(G,0,sizeof(G)) ;
        while(m--)
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            if(!G[a][b]) v[b].push_back(a+n) ;
            G[a][b]=1 ;
        }
        if(solve()) printf("Case #%d: Yes",++tc) ;
        else printf("Case #%d: No",++tc) ;
        printf("\n");
    }
}

