#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int cost[31][301] ;
int tmp1[301],tmp2[301],num[301] ;
int dp[301][301],ans[301] ;
main()
{
    int T1,T2 ;
    while(scanf("%d%d",&T1,&T2)!=EOF)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]) ;
            tmp1[0]=tmp2[0]=0 ;
            for(int j=1;j<=num[i];j++) scanf("%d",&tmp1[j]) ;
            for(int j=1;j<=num[i];j++) scanf("%d",&tmp2[j]) ;
            for(int j=0;j<=num[i];j++) cost[i][j]=tmp1[j]+tmp2[num[i]-j] ;
        }
        for(int i=0;i<=n;i++) for(int j=0;j<=T1;j++) dp[i][j]=INF ;
        dp[0][0]=0 ;
        for(int i=1;i<=n;i++) for(int j=0;j<=T1;j++)
        {
            for(int k=0;k<=j && k<=num[i];k++)
                dp[i][j]=min(dp[i][j],dp[i-1][j-k]+cost[i][k]) ;
        }
        printf("%d\n",dp[n][T1]) ;
        int j=T1 , now=dp[n][T1] ;
        for(int i=n;i>=1;i--)
        {
            int j2 ;
            for(j2=0;j2<=j && j2<=num[i];j2++)
                if(dp[i-1][j-j2]+cost[i][j2] == now) break ;
            ans[i]=j2 ;
            now -= cost[i][j2] ;
            j -= j2 ;
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
        printf("\n") ;
    }
}
