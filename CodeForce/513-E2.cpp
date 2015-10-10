#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=30000+10 , maxk=200+10 ;

int a[maxn] ;
int dp[maxn][maxk][2],g[maxn][maxk][2][5] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , a[i]+=a[i-1] ;

    fill(dp[0][0],dp[n][k]+2,-INF) ;
    fill(g[0][0][0],g[n][k][1]+5,-INF) ;
    dp[0][0][0]=dp[0][0][1]=0 ;
    for(int i=0;i<2;i++) for(int j=-2;j<=2;j++)
        g[1][1][i][j+2]=j*a[1] ;

    for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) for(int c=0;c<2;c++)
    {
        int &x=dp[i][j][c] ;
        if(!j) x=0 ;
        else
        {
            x=max(x,dp[i-1][j][c]) ;
            int c1=(c==0 ? 0 : 2) , c2=c1-2 ;
            if(j==1) c1-- , c2++ ;
            else if(j==k) c1=1 , c2=-1 ;
            x=max(x,g[i][j][0][c1+2]) ;
            x=max(x,g[i][j][1][c2+2]) ;
        }

        if(c==0) for(int r=-1;r<=2;r++)
            g[i+1][j+1][0][r+2]=max(g[i][j+1][0][r+2],x)+r*(a[i+1]-a[i]) ;
        else for(int r=-2;r<=1;r++)
            g[i+1][j+1][1][r+2]=max(g[i][j+1][1][r+2],x)+r*(a[i+1]-a[i]) ;
    }
    printf("%d\n",max(dp[n][k][0],dp[n][k][1])) ;
}
