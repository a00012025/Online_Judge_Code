#include<bits/stdc++.h>
using namespace std;
bool G[30][30] ;
int sum[30][30],d[405][405] ;

int find_sum(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1][y2]-sum[x2][y1]+sum[x1][y1] ;
}

const int INF=100000000 ;
int n,m ;
int dp(int x1,int y1,int x2,int y2)
{
    int id1=x1*(m+1)+y1 , id2=x2*(m+1)+y2 ;
    if(d[id1][id2]!=-1) return d[id1][id2] ;
    int &ans=d[id1][id2] ; ans=INF ;
    if(find_sum(x1,y1,x2,y2)==1) {ans=0 ; return 0 ;}
    for(int i=x1+1;i<x2;i++) if(find_sum(x1,y1,i,y2) && find_sum(i,y1,x2,y2))
        ans=min(ans,dp(x1,y1,i,y2)+dp(i,y1,x2,y2)+y2-y1) ;
    for(int i=y1+1;i<y2;i++) if(find_sum(x1,y1,x2,i) && find_sum(x1,i,x2,y2))
        ans=min(ans,dp(x1,y1,x2,i)+dp(x1,i,x2,y2)+x2-x1) ;
    return ans ;
}

main()
{
    int tc=0 ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int num ; scanf("%d",&num) ;
        memset(G,0,sizeof(G)) ;
        memset(sum,0,sizeof(sum)) ;
        while(num--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            G[x][y]=1 ;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+G[i][j] ;
        memset(d,-1,sizeof(d)) ;
        printf("Case %d: %d\n",++tc,dp(0,0,n,m)) ;
    }
}
