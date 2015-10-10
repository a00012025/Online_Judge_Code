#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[50000] ;
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,t ; scanf("%d%d",&n,&t) ;
        memset(dp,-1,sizeof(dp)) ; dp[0]=0 ;
        int ans=-1 , ansnum ;
        for(int i=1;i<=n;i++)
        {
            int a ; scanf("%d",&a) ;
            for(int j=t;j>=a;j--)
                if(dp[j-a]!=-1) dp[j]=max(dp[j],dp[j-a]+1) ;
        }
        for(int i=t-1;i>=0;i--) if(dp[i]>ans) ans=dp[ansnum=i] ;
        printf("Case %d: %d %d",++tc,ans+1,ansnum+678) ;
        printf("\n");
    }
}
