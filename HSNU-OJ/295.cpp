#include<bits/stdc++.h>
using namespace std;
const int maxn=1005 ;

bool adj[maxn][maxn] , dp[maxn][maxn][2] ;
int n ;
inline int step(int x,int t)
{
    return ((((x+t-1)%n)+n)%n)+1 ;
}

int check()
{
    for(int i=1;i<=n;i++)
    {
        int i2=step(i,1) , i3=step(i,-1) ;
        if(adj[i][i2] && dp[i2][i3][0]) return i ;
        if(adj[i3][i] && dp[i2][i3][1]) return i ;
    }
    return 0 ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        adj[x][y]=adj[y][x]=1 ;
    }

    for(int i=1;i<=n;i++) dp[i][i][0]=dp[i][i][1]=1 ;
    for(int len=1;len<n;len++) for(int i=1;i<=n;i++)
    {
        int j=step(i,len) ;
        if(adj[i][step(i,1)] && dp[step(i,1)][j][0])
            dp[i][j][0]=1 ;
        else if(adj[i][j] && dp[step(i,1)][j][1])
            dp[i][j][0]=1 ;
        if(adj[step(j,-1)][j] && dp[i][step(j,-1)][1])
            dp[i][j][1]=1 ;
        else if(adj[i][j] && dp[i][step(j,-1)][0])
            dp[i][j][1]=1 ;
    }

    int st=check() ;
    if(!st) { printf("-1\n") ; return 0 ; }

    int now=st , l=st , r=st ; printf("%d\n",st) ;
    for(int i=2;i<=n;i++)
    {
        int l2=step(l,-1) , r2=step(r,1) ;
        if(l2<r2)
        {
            if(dp[r2][l2][1] && adj[now][l2])
                l=l2 , now=l2 ;
            else if(dp[r2][l2][0] && adj[now][r2])
                r=r2 , now=r2 ;
        }
        else
        {
            if(dp[r2][l2][0] && adj[now][r2])
                r=r2 , now=r2 ;
            else if(dp[r2][l2][1] && adj[now][l2])
                l=l2 , now=l2 ;
        }
        printf("%d\n",now) ;
    }
}
