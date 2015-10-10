#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[110] ;
main()
{
    int cnt=0,n,m ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        printf("Case #%d :\n",++cnt) ;
        memset(dp,0,sizeof(dp)) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a) ;
            if(i>1 && j>1) dp[j]=a+min(dp[j],dp[j-1]);
            else if(i>1) dp[j]=a+dp[j] ;
            else if(j>1) dp[j]=a+dp[j-1] ;
        }
        printf("%d\n",dp[m]) ;
    }
}
