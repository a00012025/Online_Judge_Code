#include<stdio.h>
#include<algorithm>
#define DB double
#define INF 1000000001.0
#define EPS 1e-6
using namespace std;
struct pt{double x,c,d ;}a[1100];
bool cmp(pt p,pt q){return p.x<q.x ; }

double sum[1100],dp[1100][1100][2] ;
main()
{
    int n ;
    double v,start ;
    while(scanf("%d%lf%lf",&n,&v,&start)==3 && (n+v+start != 0.0))
    {
        for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i].x,&a[i].c,&a[i].d) ;
        sort(a+1,a+n+1,cmp) ;
        sum[0]=0.0 ;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].d ;

        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
            dp[i][j][0]=dp[i][j][1]=INF ;
        int st ;
        for(st=1 ; st<=n && a[st].x<start ; st++) ;
        if(st>=2) dp[st-1][st-1][0]=dp[st-1][st-1][1]=
            a[st-1].c+((start-a[st-1].x)/v)*sum[n] ;
        if(st<=n) dp[st][st][0]=dp[st][st][1]=
            a[st].c+((a[st].x-start)/v)*sum[n] ;
        for(int len=1;len<=n;len++) for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1 ;
            double s=sum[i-1]+sum[n]-sum[j] ;
            //printf("dp[%d][%d] : %.3lf , %.3lf\n",i,j,dp[i][j][0],dp[i][j][1]) ;
            if(dp[i][j][0]!=INF)
            {
                if(i>1)
                {
                    double t=(a[i].x-a[i-1].x)/v ;
                    double &ans=dp[i-1][j][0] ;
                    ans=min(ans,dp[i][j][0]+t*s+a[i-1].c) ;
                }
                if(j<n)
                {
                    double t=(a[j+1].x-a[i].x)/v ;
                    double &ans=dp[i][j+1][1] ;
                    ans=min(ans,dp[i][j][0]+t*s+a[j+1].c) ;
                }
            }
            if(dp[i][j][1]!=INF)
            {
                if(i>1)
                {
                    double t=(a[j].x-a[i-1].x)/v ;
                    double &ans=dp[i-1][j][0] ;
                    ans=min(ans,dp[i][j][1]+t*s+a[i-1].c) ;
                }
                if(j<n)
                {
                    double t=(a[j+1].x-a[j].x)/v ;
                    double &ans=dp[i][j+1][1] ;
                    ans=min(ans,dp[i][j][1]+t*s+a[j+1].c) ;
                }
            }
        }
        int ans=(int)(min(dp[1][n][0],dp[1][n][1])+EPS) ;
        printf("%d\n",ans) ;
    }
}
