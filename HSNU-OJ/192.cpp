#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

int G[301][301],dp[2][301][301] ;
int d1[]={-1,0} , d2[]={1,0} ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&G[i][j]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[0][i][j]=-INF ;
    dp[0][1][1]=G[1][1] ;
    for(int i=2;i<2*n;i++)
    {
        if(i<=n) for(int j=1;j<=i;j++) for(int k=j;k<=i;k++)
        {
            int &ans=dp[(i+1)%2][j][k] ; ans=-INF ;
            int add ;
            if(j==k) add=G[i-j+1][j] ;
            else add=G[i-j+1][j]+G[i-k+1][k] ;
            for(int t1=0;t1<2;t1++) for(int t2=0;t2<2;t2++)
            {
                int nj=j+d1[t1] , nk=k+d1[t2] ;
                if(nj>=i || nj<1 || nk>=i || nk<1) continue ;
                ans=max(ans,dp[i%2][nj][nk]+add) ;
            }
            dp[(i+1)%2][k][j]=ans ;
        }
        else for(int j=1;j<=2*n-i;j++) for(int k=j;k<=2*n-i;k++)
        {
            int &ans=dp[(i+1)%2][j][k] ; ans=-INF ;
            int add ;
            if(j==k) add=G[n-j+1][i-n+j] ;
            else add=G[n-j+1][i-n+j]+G[n-k+1][i-n+k] ;
            for(int t1=0;t1<2;t1++) for(int t2=0;t2<2;t2++)
            {
                int nj=j+d2[t1] , nk=k+d2[t2] ;
                ans=max(ans,dp[i%2][nj][nk]+add) ;
            }
            dp[(i+1)%2][k][j]=ans ;
        }
    }
    printf("%d\n",dp[0][1][1]) ;
}
