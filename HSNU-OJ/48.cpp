#include<bits/stdc++.h>
using namespace std;

int G[1010][1010] ;
int dp[1010][1010] ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&G[i][j]) ;

    memset(dp,0,sizeof(dp)) ;
    dp[1][1]=k ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(i!=1 || j!=1)
    {
        dp[i][j]=0 ;
        if(i>1) dp[i][j]+= G[i-1][j]==0 ? (dp[i-1][j]+1)/2 : dp[i-1][j]/2 ;
        if(j>1) dp[i][j]+= G[i][j-1]==1 ? (dp[i][j-1]+1)/2 : dp[i][j-1]/2 ;
        //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
    }

    int x=1 , y=1 ;
    while(x!=n+1 && y!=m+1)
    {
        int tp=G[x][y] ;
        if(dp[x][y]%2==0) tp=!tp ;
        if(tp==1) y++ ;
        else x++ ;
    }
    printf("%d %d\n",x,y) ;
}
