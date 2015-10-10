#include<stdio.h>
#include<string.h>
bool dp[5001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int goal,n,sum=0 ;
        scanf("%d%d",&goal,&n) ;
        memset(dp,0,sizeof(dp)) ;
        dp[0]=1 ;
        for(int i=1;i<=n;i++)
        {
            int a ; scanf("%d",&a) ;
            sum+=a ;
            for(int j=5000;j>=a;j--) dp[j] |= dp[j-a] ;
        }
        if(sum<goal) printf("NO SOLUTION\n") ;
        else
        {
            int ans ;
            for(ans=goal;!dp[ans];ans++) ;
            printf("%d\n",ans) ;
        }
    }
}

