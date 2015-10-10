#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=30 ;

int dp[1<<20],cost[1<<20] ;
char G[maxn][maxn] ;
int a[maxn][maxn] ;

int ma[maxn],bit[maxn],sum[maxn] ;
int F[maxn*maxn],S[maxn*maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]+1) ;
    for(int i=0;i<n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]) ;

    fill(cost,cost+(1<<n),INF) ;
    for(int i=0;i<n;i++) for(int j=1;j<=m;j++)
        cost[1<<i]=min(cost[1<<i],a[i][j]) ;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<26;j++) ma[j]=-1 , bit[j]=0 , sum[j]=0 ;
        for(int j=0;j<n;j++)
        {
            int c=G[j][i]-'a' ;
            bit[c]|=(1<<j) ;
            sum[c]+=a[j][i] ;
            ma[c]=max(ma[c],a[j][i]) ;
        }
        for(int j=0;j<26;j++) if(bit[j])
            cost[bit[j]]=min(cost[bit[j]],sum[j]-ma[j]) ;
    }

    int cnt=0 ;
    for(int i=0;i<(1<<n);i++) if(cost[i]!=INF)
        F[cnt]=i , S[cnt]=cost[i] , cnt++ ;
    fill(dp,dp+(1<<n),INF) ; dp[0]=0 ;
    for(int i=0;i<(1<<n)-1;i++) if(dp[i]!=INF)
        for(int j=0;j<cnt;j++) dp[i|F[j]]=min(dp[i|F[j]],dp[i]+S[j]) ;
    printf("%d\n",dp[(1<<n)-1]) ;
}
