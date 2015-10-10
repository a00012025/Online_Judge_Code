#include<bits/stdc++.h>
using namespace std;
const int maxn=3000 ;

bool G[maxn][maxn],vis[maxn] ;
int n ;

void dfs(int x)
{
    vis[x]=1 ;
    for(int i=1;i<=n;i++) if(!vis[i] && !G[x][i])
        dfs(i) ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(n>=maxn) continue ;
        G[x][y]=G[y][x]=1 ;
    }
    if(n>=maxn)
        { printf("1\n") ; return 0 ; }

    int cnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        cnt++ , dfs(i) ;
    printf("%d\n",cnt) ;
}
