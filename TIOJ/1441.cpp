#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
const int maxn=1000000+10 ;

int dp[2][maxn] ; /// 0 : high µ²§À , 1 : low µ²§À
int num0,num1 ;
main()
{
    int n ; scanf("%d",&n) ;
    dp[1][0]=0 ; dp[0][0]=INF ;
    num0=num1=0 ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        int id0=lower_bound(dp[0],dp[0]+num0+1,x,greater<int>() )-dp[0] ;
        int id1=lower_bound(dp[1],dp[1]+num1+1,x)-dp[1] ;

        for(int j=id1;j>=0&&( j>num0||dp[0][j]<x );j--) dp[0][j]=x ;
        for(int j=id0;j>=0&&( j>num1||dp[1][j]>x );j--) dp[1][j]=x ;
        if(id1>num0) num0=id1 ;
        if(id0>num1) num1=id0 ;
    }
    printf("%d\n",num0%2 ? num0 : num0-1) ;
}
