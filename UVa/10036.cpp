#include<stdio.h>
#include<string.h>
bool dp[2][101] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,k ;
        scanf("%d %d",&n,&k) ;
        memset(dp,0,sizeof(dp)) ;
        dp[0][0]=1 ; dp[1][0]=1 ;
        for(int i=1;i<=n;i++)
        {
            int a ;
            scanf("%d",&a) ;
            for(int j=0;j<k;j++)
            {
                int p=(j+a)%k ; if(p<0) p+=k ;
                int q=(j-a)%k ; if(q<0) q+=k ;
                dp[(i+1)%2][j]=dp[i%2][p] | dp[i%2][q] ;
            }
        }
        if(dp[(n+1)%2][0]) printf("Divisible\n") ;
        else printf("Not divisible\n") ;
    }
}
