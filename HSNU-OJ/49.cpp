#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001] ;
int a[1001],b[1001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ; n-- ; m-- ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    sort(a+1,a+n+1,greater<int>()) ;
    sort(b+1,b+m+1,greater<int>()) ;
    dp[0][0]=0 ;
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) if(i||j)
    {
        if(!i) dp[i][j]=dp[i][j-1]+(i+1)*b[j] ;
        else if(!j) dp[i][j]=dp[i-1][j]+(j+1)*a[i] ;
        else dp[i][j]=min(dp[i-1][j]+(j+1)*a[i],dp[i][j-1]+(i+1)*b[j]) ;
    }
    printf("%d\n",dp[n][m]) ;
}
