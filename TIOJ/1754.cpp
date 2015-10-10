#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
const int maxn=1000+10 ;
using namespace std;

inline void add(LL &a,LL b){a=(a+b)%MOD;}
LL dp[maxn][maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
        if(k>=m || k+1>n){printf("0\n") ; continue ;}
        memset(dp,0,sizeof(dp)) ;
        dp[1][1]=1 ;
        for(int i=1;i<=m;i++) for(int j=1;j<=i;j++)
        {
            int use=min(k,i-1) ;
            if(j>=i-k+1 && j!=1) use-- ;
            add(dp[i+1][j],dp[i][j]*(n-1-use)) ;
            if(j+k<=i) add(dp[i+1][i+1],dp[i][j]) ;
        }
        printf("%lld\n",dp[m+1][m+1]) ;
    }
}
