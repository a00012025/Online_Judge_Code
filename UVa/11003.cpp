#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[10000] ;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        memset(dp,0,sizeof(dp)) ;
        for(int i=1;i<=n;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            for(int w=0;w<=3000;w++)
            {
                if(b==w) dp[w]=max(1,dp[w]) ;
                else if(b>w) dp[w]=max(dp[w],dp[w+a]+1) ;
            }
        }
        int ans=0 ;
        for(int i=0;i<=3000;i++) ans=max(ans,dp[i]) ;
        printf("%d\n",ans) ;
    }
}

