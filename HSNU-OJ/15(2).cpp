#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
int n,adj[101][101],d[101][101] ;
main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=adj[i][j]= i==j?0:INF ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        if(dis<adj[x][y]) adj[x][y]=adj[y][x]=d[x][y]=d[y][x]=dis ;
    }
    int ans=INF ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++) for(int k=j+1;k<i;k++)
            ans=min(ans,adj[i][j]+adj[i][k]+d[j][k]) ;
        for(int j=1;j<i;j++) if(adj[i][j] < d[i][j]) d[i][j]=d[j][i]=adj[i][j] ;
        for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
            d[j][k]=min(d[j][k],d[j][i]+d[i][k]) ;
    }
    if(ans==INF) printf("No solution.\n") ;
    else printf("%d\n",ans) ;
}
