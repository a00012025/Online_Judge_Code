#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=15 ;

LL dp[maxn][1<<maxn] ;
int n,m ;

LL dfs(int now,int S,int col,int x)
{
    if(x==m) return dp[col-1][now] ;
    if(!(S&(1<<x))) return dfs(now,S,col,x+1) ;
    LL ret=dfs(now^(1<<x),S,col,x+1) ;
    if(S&(1<<(x+1))) ret+=dfs(now,S,col,x+2) ;
    return ret ;
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        fill(dp[0],dp[0]+(1<<m),0) ;
        dp[0][(1<<m)-1]=1 ;
        for(int i=1;i<=n;i++) for(int j=0;j<(1<<m);j++)
            dp[i][j]=dfs((1<<m)-1,j,i,0) ;
        printf("%lld\n",dp[n][(1<<m)-1]) ;
    }
}
