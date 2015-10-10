#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1001] ;
main()
{
    int n,m ;
    scanf("%d %d",&n,&m) ;
    for(int i=0;i<=n;i++) dp[i]=2100000000 ;
    dp[0]=0 ;
    for(int i=1;i<=m;i++)
    {
        int c;
        scanf("%d",&c) ;
        for(int j=1;j<=n;j++)
        {
            if(j>=c) dp[j]=min(dp[j-c]+1,dp[j]) ;
        }
    }
    printf("%d\n",dp[n]) ;

}
