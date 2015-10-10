#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

bool isp(int x)
{
    if(x==1) return 0 ;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;
    return 1 ;
}

int G[1000][1000],p[1000][1000] ;
int a[1000001],b[1000001] ;
void build()
{
    G[0][0]=1000000 ; a[1000000]=0 ; b[1000000]=0 ;
    int x=0,y=0,dx=0,dy=1 ;
    for(int i=999999;i>=1;i--)
    {
        if(x+dx>=1000 || x+dx<0 || y+dy>=1000 || y+dy<0 || G[x+dx][y+dy])
        {
            int t=dx ;
            dx=dy ; dy=-t ;
        }
        x+=dx ; y+=dy ;
        G[x][y]=i ;
        p[x][y]=isp(i) ;
        a[i]=x ; b[i]=y ;
    }
}

int dp[1001][1001] ;
int Dx[]={1,-1,0} ;
main()
{
    build() ;
    int n,k ;
    while(scanf("%d%d",&n,&k)==2 && n+k)
    {
        if(k>n) { printf("0 0\n") ; continue ; }

        int ans1=0 , ansid=0 ;

        for(int i=0;i<1000;i++)
            dp[a[k]][i]= i==b[k] ? (p[a[k]][i]?1:0) : -INF ;
        ans1=dp[a[k]][b[k]] ; if(ans1) ansid=k ;

        for(int i=a[k]+1;i<1000;i++) for(int j=0;j<1000;j++)
        {
            dp[i][j]=-INF ;
            if(G[i][j]>n) continue ;
            int add=p[i][j]?1:0 ;
            for(int z=0;z<3;z++)
            {
                int j2=j+Dx[z] ;
                if(j2<0 || j2>=1000) continue ;
                dp[i][j]=max(dp[i][j],dp[i-1][j2]+add) ;
            }
            if(dp[i][j]>ans1 && add) ans1=dp[i][j] , ansid=G[i][j] ;
            else if(dp[i][j]==ans1 && G[i][j]>ansid && add)
                ansid=G[i][j] ;
        }
        printf("%d %d\n",ans1,ansid) ;
    }
}
