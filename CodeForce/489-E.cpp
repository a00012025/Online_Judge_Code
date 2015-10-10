#include<bits/stdc++.h>
#define DB double
#define ABS(x) ((x)>0?(x):(-(x)))
#define INF (1e9)
using namespace std;
const int maxn=1000+10 ;

int x[maxn],val[maxn] ;
DB fr[maxn][maxn] ;
int n,fa[maxn] ;
void print(int x)
{
    if(!x) return ;
    print(fa[x]) ;
    printf("%d%c",x,x==n?'\n':' ') ;
}

DB dp[maxn] ;
bool DP(DB r)
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=INF ;
        for(int j=0;j<i;j++)
        {
            DB nv=dp[j]+fr[j][i]-r*val[i] ;
            if(nv<dp[i]) dp[i]=nv , fa[i]=j ;
        }
    }
    return dp[n]<=0 ;
}
main()
{
    int L ; scanf("%d%d",&n,&L) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&val[i]) ;
    for(int i=0;i<n;i++) for(int j=i+1;j<=n;j++)
        fr[i][j]=sqrt(ABS(x[j]-x[i]-L)) ;
    DB l=-1 , r=fr[0][n]/val[n] ;
    while(r-l>1e-9)
    {
        DB mid=(r+l)/2 ;
        if(DP(mid)) r=mid ;
        else l=mid ;
    }
    DP(r) ;
    print(n) ; printf("\n") ;
}
