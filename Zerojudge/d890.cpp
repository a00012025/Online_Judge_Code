#include<stdio.h>
#include<string.h>
bool dp[50001] ;
main()
{
    int n,k ;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        memset(dp,0,sizeof(dp)) ;
        dp[0]=1 ;
        int sum=0 ;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a) ; sum+=a ;
            for(int j=n*k;j>=1;j--) if(j>=a) dp[j]=dp[j]||dp[j-a];
        }
        int ans=sum/2 ;
        while(dp[ans]==0) ans-- ;
        printf("%d %d\n",ans,sum-ans) ;
    }
}
