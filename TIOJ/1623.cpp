#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;

int dp[maxn],w[maxn] ;
int a[maxn] ;

main()
{
    int n,k,m ; scanf("%d%d%d",&n,&k,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;

    fill(dp,dp+maxn,maxn+1) ; dp[0]=0 ;
    for(int i=1;i<=n;i++) for(int j=i;j>=1;j--)
    {
        if(a[i]>m) continue ;
        if(w[j-1]>=a[i])
        {
            if(dp[j-1]<dp[j]) dp[j]=dp[j-1] , w[j]=w[j-1]-a[i] ;
            else if(dp[j-1]==dp[j]) w[j]=max(w[j],w[j-1]-a[i]) ;
        }
        else
        {
            if(dp[j-1]+1<dp[j]) dp[j]=dp[j-1]+1 , w[j]=m-a[i] ;
            else if(dp[j-1]+1==dp[j]) w[j]=max(w[j],m-a[i]) ;
        }
    }
    for(int i=1;i<=n;i++) if(dp[i]>k)
    {
        printf("%d\n",i-1) ;
        return 0 ;
    }
}
