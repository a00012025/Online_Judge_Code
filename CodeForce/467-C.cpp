#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL dp[5001][5001]={0} ;
main()
{
    LL a[6000],s[6000]={(LL)0} ;
    int n,m,k ;
    scanf("%d %d %d",&n,&m,&k) ;
    for(int i=1;i<=n;i++){scanf("%I64d",&a[i]) ; s[i]=s[i-1]+a[i];}
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++)
    {
        if(j>=m) dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+s[j]-s[j-m]) ;
        else dp[i][j]=dp[i][j-1] ;
    }
    printf("%I64d\n",dp[k][n]) ;
}
