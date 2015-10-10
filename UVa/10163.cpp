#include<bits/stdc++.h>
using namespace std;
const int INF=100000000 ;
int a[40],n,m ;
int dp[40][105] ;

int check(int val)
{
    for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) dp[i][j]=INF ; dp[0][0]=0 ;
    for(int i=1;i<=m;i++)
    {
        int num=a[i]/val ;
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]) ;
            dp[i][j]=min(dp[i][j],dp[i-1][max(j-num,0)]+a[i]) ;
        }
    }
    return dp[m][n]==INF ? -1 : dp[m][n] ;
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=1;i<=m;i++) scanf("%d",&a[i]) ;
        int l=0 , r=10000 , ans=0 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            int val=check(mid) ;
            if(val==-1) r=mid ;
            else l=mid , ans=val ;
            //printf("check(%d)=%d\n",mid,val) ;
        }
        printf("%d %d\n",l,ans) ;
    }
}
