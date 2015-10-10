#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=2000 ;
int dp[110][maxn] ;

main()
{
    int v1,v2,t,d ; scanf("%d%d%d%d",&v1,&v2,&t,&d) ;
    fill(dp[0],dp[109]+maxn,-INF) ;
    dp[1][v1]=v1 ;
    for(int i=1;i<t;i++) for(int j=0;j<maxn;j++) if(dp[i][j]>=0)
        for(int k=max(j-d,0);k<=min(j+d,maxn-1);k++)
        dp[i+1][k]=max(dp[i+1][k],dp[i][j]+k) ;
    printf("%d\n",dp[t][v2]) ;
}
