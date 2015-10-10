#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[101],a[101],b[101] ;
main()
{
    int n,m,cnt=0 ;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n && !m) break ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
        memset(dp,0,sizeof(dp)) ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int tem=dp[j] ;
                if(a[i]==b[j]) dp[j]=dp[m+1]+1 ;
                else dp[j]=max(dp[j-1],dp[j]) ;
                dp[m+1]= j==m ? 0 : tem ;
            }
        }
        if(cnt) printf("\n") ;
        printf("Twin Towers #%d\nNumber of Tiles : %d\n",++cnt,dp[m]) ;
    }
}
