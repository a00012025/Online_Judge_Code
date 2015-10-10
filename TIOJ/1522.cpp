#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=70+10,maxm=2100+10 ;

struct P
{
    int h,w ;
    bool operator < (const P &rhs) const
    {
        return h>rhs.h ;
    }
}a[maxn] ;

int dp[2][maxm][maxm] ;
int sum[maxn] ;

inline void up(int &a,int b)
{
    if(b<a) a=b ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].h,&a[i].w) ;
        sort(a+1,a+n+1) ;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].w ;
        dp[1][0][0]=a[1].h ;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j+a[1].w<=sum[i+1];j++)
                for(int k=0;k+j+a[1].w<=sum[i+1];k++)
                dp[(i+1)%2][j][k]=INF ;

            for(int j=0;j+a[1].w<=sum[i];j++)
                for(int k=0;k+j+a[1].w<=sum[i];k++)
                if(dp[i%2][j][k]!=INF)
            {
                int val=dp[i%2][j][k] ;
                up(dp[(i+1)%2][j][k],val) ;
                int add1= j==0?a[i+1].h:0 ;
                up(dp[(i+1)%2][j+a[i+1].w][k],val+add1) ;
                int add2= k==0?a[i+1].h:0 ;
                up(dp[(i+1)%2][j][k+a[i+1].w],val+add2) ;
            }
        }

        int ans=INF ;
        for(int j=1;j+a[1].w<=sum[n];j++)
            for(int k=1;j+k+a[1].w<=sum[n];k++)
            if(dp[n%2][j][k]!=INF)
        {
            int M=max(sum[n]-j-k,max(j,k)) ;
            up(ans,M*dp[n%2][j][k]) ;
        }
        printf("%d\n",ans) ;
    }
}
