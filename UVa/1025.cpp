#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 100000000
int dp[211][61],tmd[60],n,t ;
bool go[201][51][2] ;

bool init()
{
    scanf("%d",&n) ; if(n==0) return 0 ;
    memset(go,0,sizeof(go)) ;

    scanf("%d",&t) ;
    for(int i=1;i<n;i++) scanf("%d",&tmd[i]) ;
    int m1,m2 ;
    scanf("%d",&m1) ;
    while(m1--)
    {
        int d ; scanf("%d",&d) ;
        for(int i=1;i<n;i++) {go[d][i][0]=1 ; d+=tmd[i] ; if(d>t) break ;}
    }
    scanf("%d",&m2) ;
    while(m2--)
    {
        int d ; scanf("%d",&d) ;
        for(int i=n;i>1;i--) {go[d][i][1]=1 ; d+=tmd[i-1] ; if(d>t) break ;}
    }
    return 1;
}

main()
{
    int tc=0 ;
    while(init())
    {
        for(int i=0;i<=t;i++) for(int j=1;j<=n;j++) dp[i][j]=INF ;
        dp[0][1]=0 ;
        for(int i=0;i<=t;i++) for(int j=1;j<=n;j++) if(dp[i][j]!=INF)
        {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1) ;
            if(go[i][j][0] && i+tmd[j]<=t)
                dp[i+tmd[j]][j+1]=min(dp[i+tmd[j]][j+1],dp[i][j]) ;
            if(go[i][j][1] && i+tmd[j-1]<=t)
                dp[i+tmd[j-1]][j-1]=min(dp[i+tmd[j-1]][j-1],dp[i][j]) ;
        }
        if(dp[t][n]==INF) printf("Case Number %d: impossible\n",++tc) ;
        else printf("Case Number %d: %d\n",++tc,dp[t][n]) ;
    }
}
