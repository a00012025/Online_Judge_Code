#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=50+1 ;

DB dp[maxn][maxn] ;
int a[maxn] ;void solve()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    sort(a,a+n) ;
    for(int i=n-1;i>=0;i--) for(int j=i;j<n;j++)
    {
        if(i==j){dp[i][j]=a[i] ; continue ;}
        dp[i][j]=-1e9 ;
        for(int k=i;k<j;k++) dp[i][j]=max(dp[i][j],(dp[i][k]+dp[k+1][j])/2) ;
    }
    printf("%.10f\n",dp[0][n-1]) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
