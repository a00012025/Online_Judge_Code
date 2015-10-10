#include<stdio.h>
#include<string.h>
bool dp[100001] ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m ;
        memset(dp,0,sizeof(dp)) ;
        dp[0]=1 ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=m;i++)
        {
            int a[21],num ;
            scanf("%d",&num) ;
            for(int j=1;j<=num;j++) scanf("%d",&a[j]) ;
            for(int j=n;j>=0;j--)
            {
                dp[j]=0 ;
                for(int k=1;k<=num;k++) if(j>=a[k]) dp[j] |= dp[j-a[k]] ;
            }
        }
        int ans ;
        for(ans=n;ans>=0 && dp[ans]==0;ans--) ;
        if(ans==-1) printf("no solution\n") ;
        else printf("%d\n",ans) ;
    }
}
