#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,m ;
int a[4000],dp[4000] ;

int LIS()
{
    int num=0 ;
    dp[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+m>=dp[num])
        {
            dp[num+1]=max(dp[num],a[i]) ; num++ ;
            for(int j=num;j>=1;j--) dp[j]=min(dp[j],max(dp[j-1],a[i])) ;
        }
        else if(a[i]<dp[num])
        {
            int id=upper_bound(dp,dp+num+1,a[i]+m)-dp ;
            for(int j=id;j>=1;j--) dp[j]=min(dp[j],max(dp[j-1],a[i])) ;
        }
    }
    return num ;
}

main()
{
    int T ;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        while(T--)
        {
            scanf("%d",&m) ;
            printf("%d%c",LIS(),T?' ':'\n') ;
        }
    }
}
