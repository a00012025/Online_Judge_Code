#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=2000000000 ;
int dp[17][1<<17],x[17],y[17],d[17][17] ;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        char c;
        int cnt=1 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            scanf("%c",&c) ;
            while(c!='#' && c!='L' && c!='.') scanf("%c",&c) ;
            if(c=='L') {x[0]=i ; y[0]=j ;}
            else if(c!='.') {x[cnt]=i ; y[cnt]=j ; cnt++ ;}
        }
        for(int i=0;i<cnt;i++) for(int j=0;j<cnt;j++)
        {
            int dx=x[i]>x[j]?x[i]-x[j]:x[j]-x[i] ;
            int dy=y[i]>y[j]?y[i]-y[j]:y[j]-y[i] ;
            d[i][j]=max(dx,dy) ;
        }
        for(int i=0;i<cnt;i++) for(int j=0;j<(1<<cnt);j++) dp[i][j]=INF ;
        dp[0][1]=0 ;
        for(int j=0;j<(1<<cnt);j++) for(int i=0;i<cnt;i++)
        {
            if(((1<<i) & j) ==0) continue ;
            for(int k=0;k<cnt;k++) if(k!=i && ((1<<k)&j)!=0)
            {
                dp[i][j]=min(dp[i][j],d[k][i]+dp[k][j-(1<<i)]) ;
            }
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]) ;
        }
        int ans=INF ;
        for(int i=1;i<cnt;i++) ans=min(ans,dp[i][(1<<cnt)-1]+d[i][0]) ;
        if(cnt==1) ans=0 ;
        printf("%d\n",ans) ;
    }
}
