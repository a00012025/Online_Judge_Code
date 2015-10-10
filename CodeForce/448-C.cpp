#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=5000+10 ;
inline void up(LL &a,LL b){a=min(a,b) ;}
int a[maxn] ;
LL dp[2][maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    dp[1][0]=1 ; dp[1][1]=a[1] ;
    int cur=1 ;
    for(int i=1;i<n;i++,cur^=1)
    {
        fill(dp[cur^1],dp[cur^1]+maxn,INF) ;
        for(int j=0;j<=i;j++) if(dp[cur][j]!=INF)
        {
            if(a[j]>a[i+1]) up(dp[cur^1][i+1],dp[cur][j]) ;
            else up(dp[cur^1][j],dp[cur][j]+1) ,
                up(dp[cur^1][i+1],dp[cur][j]+a[i+1]-a[j]) ;
        }
    }
    LL ans=INF ;
    for(int i=0;i<=n;i++) ans=min(ans,dp[cur][i]) ;
    printf("%I64d\n",ans) ;
}
