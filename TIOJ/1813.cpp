#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=300+10 ;

int dx[]={-1,1,0,0} , dy[]={0,0,-1,1} ;
char G[maxn][maxn] ;
int dir[maxn],step[maxn] ;

int n,m,dp[2][maxn][maxn] ;

main()
{
    int stx,sty ; scanf("%d%d%d%d",&n,&m,&stx,&sty) ;
    for(int i=1;i<=n;i++) scanf("%s",G[i]+1) ;

    int k ; scanf("%d",&k) ;
    for(int i=1;i<=k;i++) scanf("%d%d",&dir[i],&step[i]) , dir[i]-- ;

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        dp[(k+1)%2][i][j]= G[i][j]=='.' ? 0 : -INF ;
    for(int i=k;i>=1;i--)
        for(int x0=1;x0<=n;x0++) for(int y0=1;y0<=m;y0++)
    {
        if(G[x0][y0]!='.') { dp[i%2][x0][y0]=-INF ; continue ; }
        int &ans=dp[i%2][x0][y0] ; ans=0 ;
        int x=x0 , y=y0 ;
        for(int z=0;G[x][y]=='.' && z<=step[i];z++)
        {
            ans=max(ans,z+dp[(i+1)%2][x][y]) ;
            x+=dx[dir[i]] ; y+=dy[dir[i]] ;
            if(x<1 || x>n || y<1 || y>m) break ;
        }
    }

    printf("%d\n",dp[1][stx][sty]) ;
}
