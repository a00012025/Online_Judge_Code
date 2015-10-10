#include<stdio.h>
#include<string.h>
bool dp[201][20001] ;
int a[201],fa[201][20001] ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,cnt=0 ;
        scanf("%d",&n) ; n*=100 ;
        while(scanf("%d",&m)==1 && m) if(cnt<200) a[++cnt]=m ;
        int sum=0 , i;
        memset(dp,0,sizeof(dp)) ;
        memset(fa,0,sizeof(fa)) ;
        dp[0][0]=1 ;
        for(i=1;i<=cnt;i++)
        {
            sum+=a[i] ;
            dp[i][0]=1 ;
            for(int j=sum;j>=1;j--)
            {
                fa[i][j]=j ; dp[i][j]=dp[i-1][j] ;
                if(j>=a[i] && dp[i-1][j-a[i]]) {dp[i][j]=1 ; fa[i][j]=j-a[i] ;}
            }
            if(sum<=n) continue ;
            int j ;
            for(j=(sum/2)-1 ; j<=sum && dp[i][j]==0 ; j++) ;
            //printf("j=%d\n",j) ;
            if(j>n) break ;
        }
        int ans=i-1 ;
        printf("%d\n",ans) ;
        bool port[201]={0} ;
        int j ;
        for(j=(sum-a[i])/2 ; dp[ans][j]==0 ; j++) ;
        i-- ;
        for(;j>0;i--)
        {
                //printf("%d,%d\n",i,j) ;
            if(fa[i][j]!=j) port[i]=1 ;
            j=fa[i][j] ;
        }
        for(int k=1;k<=ans;k++)
        {
            if(port[k]) printf("port\n") ;
            else printf("starboard\n") ;
        }
        if(T)printf("\n") ;
        //for(int i=1;i<=6;i++) printf("%d\n",fa[i][5000]) ;
    }
}
