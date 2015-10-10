#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL dp[61][61][3600]={{{0}}} ;
main()
{
    int x,y,m ;
    scanf("%d %d %d",&x,&y,&m) ;
    for(int i=0;i<=60;i++) dp[i][0][0]=1 ;
    for(int i=1;i<=x;i++) for(int j=1;j<=min(i,y);j++) for(int r=0;r<m;r++)
    {
        LL a1,a2 ;
        a1 = (r%2==1 ? dp[i][j-1][(r-1)/2] : dp[i-1][j][r/2]) ;
        a2 = ((r+m)%2==1 ? dp[i][j-1][(r+m-1)/2] : dp[i-1][j][(r+m)/2]) ;
        dp[i][j][r]=a1+a2 ;
    }
    LL ans=0 ;
    for(int r=0;r<m;r++) ans+=dp[x][y][r]*r ;
    printf("%lld\n",ans) ;
}
