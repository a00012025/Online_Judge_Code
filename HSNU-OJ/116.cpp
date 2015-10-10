#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000+10 ;

char G[maxn][maxn] ;
int dp[maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    LL ans=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]=='1')
    {
        if(!i || !j){dp[i][j]=1 ; ans++ ; continue ;}
        dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1 ;
        ans+=dp[i][j] ;
    }
    printf("%lld\n",ans) ;
}
