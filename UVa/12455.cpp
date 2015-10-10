#include<bits/stdc++.h>
using namespace std;

bool dp[2000] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        memset(dp,0,sizeof(dp)) ; dp[0]=1 ;
        while(k--)
        {
            int x ; scanf("%d",&x) ;
            for(int i=n;i>=x;i--) dp[i]|=dp[i-x] ;
        }
        if(dp[n]==1) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
