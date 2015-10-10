#include<bits/stdc++.h>
using namespace std;
int INF=10000 ;

int dp[5001] ;
main()
{
    for(int i=0;i<=5000;i++) dp[i]=INF ; dp[0]=0 ;
    for(int i=3;i<=5000;i+=3) dp[i]=i/3 ;
    for(int i=5;i<=5000;i++) dp[i]=min(dp[i],dp[i-5]+1) ;
    int n ; scanf("%d",&n) ;
    if(dp[n]==INF) printf("This is Kongming's Trap!!!\n") ;
    else printf("%d\n",dp[n]) ;
}
