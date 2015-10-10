#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
LL dp[2][101] ;
main()
{
    int n,m,st,len ;
    LL G[101][101] ;
    while(scanf("%d%d%d%d",&n,&st,&m,&len)==4)
    {
        if(!n && !st && !m && !len) break ;
        memset(dp,0,sizeof(dp)) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lld",&G[i][j]) ;
        for(int i=1;i<=n;i++) dp[0][i]=G[st][i] ;
        for(int i=1;i<len;i++)
        {
            for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
                dp[i%2][j]=max(dp[i%2][j],dp[(i+1)%2][k]+G[k][j]) ;
        }
        LL ans=0 ;
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a) ;
            ans=max(ans,dp[(len-1)%2][a]);
        }
        printf("%lld\n",ans) ;
    }
}
