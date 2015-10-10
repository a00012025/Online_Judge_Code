#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=2000+10 ;

DB dp[maxn][maxn] ;

main()
{
    int n,t ; DB p ;
    scanf("%d%lf%d",&n,&p,&t) ;
    dp[0][0]=1.0 ;
    for(int i=1;i<=t;i++) for(int j=0;j<=n;j++)
    {
        if(j==n) dp[i][j]=p*dp[i-1][j-1]+dp[i-1][j] ;
        else dp[i][j]= j ? p*dp[i-1][j-1]+(1-p)*dp[i-1][j] :
            (1-p)*dp[i-1][j] ;
    }
    DB ans=0.0 ;
    for(int i=1;i<=n;i++) ans+=dp[t][i]*i ;
    printf("%.9f\n",ans) ;
}
