#include<stdio.h>
#include<algorithm>
using namespace std;
struct book
{
    int h,w;
    bool operator < (const book &rhs) const
    {
        return h>rhs.h ;
    }
}a[71];

void update_ans(int &x,int val)
{
    if(val<x) x=val ;
}

int dp[2][2101][2101],sum[71] ;
const int INF=2000000000 ;
main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].h,&a[i].w) ;
        sort(a+1,a+n+1) ;
        sum[0]=0 ; for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].w ;

        dp[1][0][0]=a[1].h ;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum[i+1];j++) for(int k=0;a[1].w+j+k<=sum[i+1];k++)
                dp[(i+1)%2][j][k]=INF ;
            for(int j=0;j<=sum[i];j++) for(int k=0;a[1].w+j+k<=sum[i];k++)
            if(dp[i%2][j][k]!=INF)
            {
                //printf("dp[%d][%d][%d]=%d\n",i%2,j,k,dp[i%2][j][k]) ;
                update_ans(dp[(i+1)%2][j][k],dp[i%2][j][k]) ;
                int add2= j==0 ? a[i+1].h : 0 ;
                update_ans(dp[(i+1)%2][j+a[i+1].w][k],dp[i%2][j][k]+add2) ;
                int add3= k==0 ? a[i+1].h : 0 ;
                update_ans(dp[(i+1)%2][j][k+a[i+1].w],dp[i%2][j][k]+add3) ;
            }
        }
        int ans=INF ;
        for(int j=1;j<sum[n];j++) for(int k=1;a[1].w+j+k<=sum[n];k++)
        if(dp[n%2][j][k]!=INF)
        {
            int M=max(sum[n]-j-k,max(j,k)) ;
            ans=min(ans,dp[n%2][j][k]*M) ;
            //printf("[%d][%d] * %d\n",j,k,M) ;
        }
        printf("%d\n",ans) ;
    }
}
