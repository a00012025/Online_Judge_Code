#include<bits/stdc++.h>
using namespace std;
int dp[4000] ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        dp[1]=2 ; dp[0]=1 ;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1] ;
            if(i>=m+1) dp[i]+=dp[i-m-1] ;
            else dp[i]++ ;
            dp[i]%=10000 ;
        }
        printf("%d\n",dp[n]) ;
    }
}
