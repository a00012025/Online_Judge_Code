#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=11+1 ;

bool f(int x,char c)
{
    if(c=='U') return x==1||x==3||x==6 ;
    if(c=='D') return x==2||x==4||x==6 ;
    if(c=='L') return x==1||x==2||x==5 ;
    if(c=='R') return x==3||x==4||x==5 ;
}

int dp[2][1<<maxn] ;
int G[maxn][maxn] ;
void solve(int tc)
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        scanf("%d",&G[i][j]) ;

    memset(dp,0,sizeof(dp)) ;
    dp[1][0]=1 ;
    int Ma=1<<(m+1),cur=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<=m;j++,cur^=1)
    {
        fill(dp[cur],dp[cur]+Ma,0) ;
        if(j==m)
        {
            for(int S=0;S<(1<<m);S++) dp[cur][S]=dp[cur^1][S<<1] ;
            continue ;
        }
        for(int S=0;S<Ma;S++) if(dp[cur^1][S])
        {
            bool L=(S&(1<<(m-j))) , U=(S&(1<<(m-j-1))) ;
            int lo=(G[i][j]?1:0) , hi=(G[i][j]?6:0) ;
            for(int x=lo;x<=hi;x++)
            {
                if(L!=f(x,'L') || U!=f(x,'U')) continue ;
                if(i==n-1 && f(x,'D')) continue ;
                if(j==m-1 && f(x,'R')) continue ;
                bool n1=f(x,'D') , n2=f(x,'R') ;
                int nS=S ;
                if(L!=n1) nS^=(1<<(m-j)) ;
                if(U!=n2) nS^=(1<<(m-j-1)) ;
                dp[cur][nS]+=dp[cur^1][S] ;
                dp[cur][nS]%=MOD ;
            }
        }
    }
    printf("Case %d: %d\n",tc,dp[cur^1][0]) ;
}

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--) solve(++tc) ;
}

