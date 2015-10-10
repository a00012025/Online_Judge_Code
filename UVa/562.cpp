#include<stdio.h>
#include<string.h>
int dp[50001] ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,sum=0;
        scanf("%d",&n);
        memset(dp,0,sizeof(dp)) ;
        dp[0]=1 ;
        for(int i=1;i<=n;i++)
        {
            int a ;
            scanf("%d",&a) ; sum+=a ;
            for(int j=50000;j>=1;j--) if(j>=a) dp[j] |= dp[j-a] ;
        }
        int ans=(sum+1)/2 ;
        while(!dp[ans]) ans++ ;
        printf("%d\n",2*ans-sum) ;
    }
}
