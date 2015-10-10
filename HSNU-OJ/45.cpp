#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

int cal(int x,int y,int z)
{
    if(x==y && y==z) return 1 ;
    if(x==y || y==z || x==z) return 2 ;
    return 3 ;
}

int dp[100001][10][10] ;
int a[100001] ;
char s[100001] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='M') a[i]=0 ;
        if(s[i]=='B') a[i]=1 ;
        if(s[i]=='F') a[i]=2 ;
    }
    for(int i=0;i<=n;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) dp[i][j][k]=-INF ;
    dp[0][9][9]=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) if(dp[i][j][k]!=-INF)
    {
        int x1=j/3 , y1=j%3 , x2=k/3 , y2=k%3 ;
        if(j==9)
            dp[i+1][4*a[i+1]][k]=max(dp[i+1][4*a[i+1]][k],dp[i][j][k]+1) ;
        else
        {
            int j2=3*y1+a[i+1] ;
            dp[i+1][j2][k]=max(dp[i+1][j2][k],dp[i][j][k]+cal(x1,y1,a[i+1])) ;
        }

        if(k==9)
            dp[i+1][j][4*a[i+1]]=max(dp[i+1][j][4*a[i+1]],dp[i][j][k]+1) ;
        else
        {
            int k2=3*y2+a[i+1] ;
            dp[i+1][j][k2]=max(dp[i+1][j][k2],dp[i][j][k]+cal(x2,y2,a[i+1])) ;
        }
    }
    int ans=0 ;
    for(int j=0;j<10;j++) for(int k=0;k<10;k++)
        ans=max(ans,dp[n][j][k]) ;
    printf("%d\n",ans) ;
}
