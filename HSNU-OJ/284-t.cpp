#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10+5 ;

LL fac[maxn],dp[maxn][maxn] ;
main()
{
    for(int i=0;i<maxn;i++) fac[i]=i?fac[i-1]*i:1 ;
    for(int i=0;i<maxn;i++) for(int j=0;j<maxn;j++)
    {
        if(i<3){dp[i][j]=fac[i+j] ; continue ;}
        for(int k=0;k<=j;k++)
        {
            dp[i][j]+=dp[i-1][j-k]*(fac[j]/fac[j-k]) ;
            dp[i][j]+=(i-1)*dp[i-2][j-k]*(k+1)*(fac[j]/fac[j-k]) ;
        }
    }
    for(int i=0;i<maxn;i++) printf("%lld,",dp[i][0]) ;

    int n,x=0,y=0,k ; scanf("%d",&n) ;
    while(n--) scanf("%d",&k) , (k==1?x:y)++ ;
    if(x+y<=10) printf("%lld\n",dp[x][y]%1000000007) ;
}
