#include<bits/stdc++.h>
#define MOD 1000000
#define LL long long
using namespace std;

LL C[201][201] , dp[201][201] ;

main()
{
    for(int i=1;i<=200;i++) for(int j=0;j<=i;j++)
        C[i][j]= (j==0||j==i) ? 1LL : (C[i-1][j]+C[i-1][j-1])%MOD ;

    for(int i=1;i<=200;i++) dp[0][i]=1LL , dp[1][i]=1LL ;
    for(int i=2;i<=200;i++) for(int j=1;j<=200;j++)
    {
        if(j==1) { dp[i][j]=1LL ; continue ; }
        dp[i][j]=1LL ;
        for(int k=0;k<=i-2;k++) dp[i][j]+=C[i-1][k]*dp[i-k-1][j-1] , dp[i][j]%=MOD ;
    }

    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && m+n) printf("%lld\n",dp[m][n]) ;
}
