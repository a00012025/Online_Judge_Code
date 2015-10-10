#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10 ;

int p[maxn],t[maxn] ;
int dp[maxn][maxn] ;
int ma[maxn] ;
main()
{
    freopen("boarding.in","r",stdin) ;
    freopen("boarding.out","w",stdout) ;
    srand(7122) ;
    int n ; scanf("%d",&n) ;
    if(n>=maxn) abort() ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&t[i]) ;
    int ans=0 ;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=p[i];j++)
        {
            dp[i][j]=max(dp[i][j-1]+1,ma[j+1]) ;
            ma[j]=max(ma[j],dp[i][j]) ;
        }
        ans=max(ans,dp[i][p[i]]+t[i]) ;
        dp[i][p[i]+1]=dp[i][p[i]]+t[i]+1 ;
        ma[p[i]+1]=max(ma[p[i]+1],dp[i][p[i]+1]) ;
    }
    printf("%d\n",ans) ;
}

