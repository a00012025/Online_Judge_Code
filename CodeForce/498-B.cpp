#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=5002 ;
int p[maxn],t[maxn],n ;
DB dp[maxn][maxn] ;

main()
{
    int T ; scanf("%d%d",&n,&T) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&t[i]) ;

    for(int i=0;i<=T;i++) dp[n+1][i]=0.0 ;
    for(int i=n;i>=1;i--)
    {
        int x=t[i] ;
        DB pb=((DB)p[i])/((DB)100) , pbt=pow(1-pb,x) ;
        for(int j=0;j<=T;j++)
        {
            if(j==0) { dp[i][j]=0.0 ; continue ; }
            if(j<x) dp[i][j]=dp[i][j-1]*(1-pb) + (1+dp[i+1][j-1])*pb ;
            else if(j==x)
                dp[i][j]=dp[i][j-1]*(1-pb) + (1+dp[i+1][j-1])*pb
                        + (1+dp[i+1][0])*pbt ;
            else if(j>x)
                dp[i][j]=dp[i][j-1]*(1-pb) + (1+dp[i+1][j-1])*pb
                        + (dp[i+1][j-x]-dp[i+1][j-1-x])*pbt ;
        }
    }
    printf("%.10f\n",dp[1][T]) ;
}
