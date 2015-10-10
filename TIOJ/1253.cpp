#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int my[maxn] ;
int adj[maxn][maxn],n ;
bool vis[maxn] ;
bool dfs(int x)
{
    vis[x]=1 ;
    for(int i=1;i<=n;i++) if(adj[x][i])
    {
        if(my[i]==-1 || (!vis[my[i]] && dfs(my[i])))
        {
            my[i]=x ; return 1 ;
        }
    }
    return 0 ;
}

main()
{
    int k,tc=0 ;
    while(scanf("%d%d",&n,&k)==2 && n+k)
    {
        memset(adj,0,sizeof(adj)) ;
        while(k--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            adj[x][y]=1 ;
        }
        memset(my,-1,sizeof(my)) ;
        int ans=0 ;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis)) ;
            if(dfs(i)) ans++ ;
        }
        printf("Case #%d:%d\n",++tc,ans) ;
    }
}

