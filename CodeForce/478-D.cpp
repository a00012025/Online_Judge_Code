#include<stdio.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007
int dp[300000] ;
main()
{
    int a,b,h=0,ans=0 ;
    scanf("%d %d",&a,&b) ;
    while((h+1)*(h+2)/2 <= a+b) h++ ;
    dp[0]=1 ;
    for(int i=1;i<=h;i++) for(int j=a;j>=i;j--) {dp[j]+=dp[j-i] ; dp[j] %= MOD ;}
    for(int i=max(0,h*(h+1)/2-b) ; i<=a ; i++) {ans += dp[i] ; ans %= MOD ;}
    printf("%d\n",ans) ;
}
