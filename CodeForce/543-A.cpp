#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

int a[maxn] ;
int dp[2][maxn][maxn] ;
int MOD ;
main()
{
    int n,m,b,MOD ; scanf("%d%d%d%d",&n,&m,&b,&MOD) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    dp[0][0][0]=1 ;
    for(int i=1;i<=n;i++) for(int j=0;j<=m;j++)
        for(int k=0;k<=b;k++)
    {
        dp[i%2][j][k]=dp[(i+1)%2][j][k] ;
        if(j>=1 && k>=a[i])
            dp[i%2][j][k]+=dp[i%2][j-1][k-a[i]] ,
            dp[i%2][j][k]%=MOD ;
    }
    int ans=0 ;
    for(int i=0;i<=b;i++) ans=(ans+dp[n%2][m][i])%MOD ;
    printf("%d\n",ans) ;
}
