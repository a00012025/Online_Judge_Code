#include<bits/stdc++.h>
using namespace std;
const int INF=1000000 ;
int adj[30][30],a[20],dis[30][30],n,m ;

int bitcnt(int x){return x ? (x%2 ? 1+bitcnt(x/2) : bitcnt(x/2)) : 0 ; }
int d[1<<15][20] ;
int dp(int s,int now)
{
    if(d[s][now]!=-1) return d[s][now] ;
    int &ans=d[s][now] ; ans=INF ;
    if(!((1<<now) & s)) return ans ;
    if(bitcnt(s)==1)
    {
        ans=dis[1][a[now]] ;
        return ans ;
    }
    for(int i=0;i<m;i++) if((s&(1<<i)) && i!=now)
        ans=min(ans,dp(s-(1<<now),i)+dis[a[i]][a[now]]) ;
    return ans ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        scanf("%d",&adj[i][j]) ;
        if(i!=j && adj[i][j]==0) adj[i][j]=INF ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dis[i][j]= adj[i][j] ;
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
    int ans=INF ;
    memset(d,-1,sizeof(d)) ;
    for(int i=0;i<m;i++) ans=min(ans,dp((1<<m)-1,i)+dis[a[i]][n]) ;
    printf("%d\n",ans) ;
}
