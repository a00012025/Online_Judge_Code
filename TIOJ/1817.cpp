#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=1500+10 ;

int power[11]={1,3,9,27,81,243,729,2187,6561,19683,59049} ;

int n,m ;
int now[15] ;
void decode(int x)
{
    for(int i=0;i<m;i++) now[i]=x%3 , x/=3 ;
}
int encode()
{
    int ret=0 ;
    for(int i=0;i<m;i++) ret+=now[i]*power[i] ;
    return ret ;
}

int dp[2][60000] ;
bool G[maxn][15] ;

int last[15],tmp[15] ;
void dfs(int i,int j,int Last,int num)
{
    if(j==m)
    {
        int newst=encode() ;
        dp[(i+1)%2][newst]=max(dp[(i+1)%2][newst],dp[i%2][Last]+num) ;
        return ;
    }

    if(j<m-1 && !last[j] && !last[j+1] && !G[i+1][j] && !G[i+1][j+1])
    {
        now[j]=now[j+1]=1 ;
        dfs(i,j+2,Last,num+1) ;
        now[j]=tmp[j] ; now[j+1]=tmp[j+1] ;
    }

    if(j<m-2 && last[j]!=1 && last[j+1]!=1 && last[j+2]!=1
        && !G[i+1][j] && !G[i+1][j+1] && !G[i+1][j+2])
    {
        now[j]=now[j+1]=now[j+2]=1 ;
        dfs(i,j+3,Last,num+1) ;
        now[j]=tmp[j] ; now[j+1]=tmp[j+1] ; now[j+2]=tmp[j+2] ;
    }

    dfs(i,j+1,Last,num) ;
}

main()
{
    int T ; scanf("%d",&T);
    while(T--)
    {
        int k ; scanf("%d%d%d",&n,&m,&k) ;
        memset(G,0,sizeof(G)) ;
        memset(now,0,sizeof(now)) ;
        while(k--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            G[x][y-1]=1 ;
        }

        for(int i=0;i<power[m];i++) dp[1][i]=-INF ;
        for(int i=0;i<m;i++) now[i]= G[1][i]?1:2 ;
        dp[1][encode()]=0 ;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<power[m];j++) dp[(i+1)%2][j]=-INF ;
            for(int j=0;j<power[m];j++) if(dp[i%2][j]>=0)
            {
//                if(i==2)printf("dp[%d][%d]=%d\n",i,j,dp[i%2][j]) ;
                decode(j) ;
                for(int z=0;z<m;z++)
                {
                    last[z]=now[z] ;
                    if(G[i+1][z]) tmp[z]=now[z]=1 ;
                    else if(now[z]==1) tmp[z]=now[z]=2 ;
                    else tmp[z]=now[z]=0 ;
                }
                dfs(i,0,j,0) ;
            }
        }

        int ans=0 ;
        for(int j=0;j<power[m];j++) ans=max(ans,dp[n%2][j]) ;
        printf("%d\n",ans) ;
    }
}
