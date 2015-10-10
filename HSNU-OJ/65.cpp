#include<bits/stdc++.h>
#define INF 2000000000
#define LL int
using namespace std;

LL adj[101][101],d[101] ;
int n ;
bool vis[101] ;
void dijkstra(int st)
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    memset(vis,0,sizeof(vis)) ;
    d[st]=0 ;
    for(int i=1;i<=n;i++)
    {
        LL M=INF+1 ; int id ;
        for(int j=1;j<=n;j++) if(!vis[j] && d[j]<=M) M=d[id=j] ;
        vis[id]=1 ;
        if(d[id]==INF) break ;
        for(int j=1;j<=n;j++) if(adj[id][j]!=INF)
            d[j]=min(d[j],d[id]+adj[id][j]) ;
    }
}

main()
{
    int m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) adj[i][j]= i==j?0:INF ;
    while(m--)
    {
        int x,y ; LL w ; scanf("%d%d%d",&x,&y,&w) ;
        int t=min(adj[x][y],w) ;
        adj[x][y]=adj[y][x]=t ;
    }
    dijkstra(1) ;
    while(Q--)
    {
        int x,y ; LL w ; scanf("%d%d%d",&x,&y,&w) ;
        LL val=d[n] , old=adj[x][y] ;
        if(old<=w) {printf("0\n") ; continue ; }
        adj[x][y]=adj[y][x]=w ;
        dijkstra(1) ;
        if(d[n]<val) printf("1\n") ;
        else {printf("0\n") ; d[n]=val ; adj[x][y]=adj[y][x]=old ; }
    }
}
