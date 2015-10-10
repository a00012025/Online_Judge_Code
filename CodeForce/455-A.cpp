#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn] ;
LL dp[maxn] ;
main()
{
    int n,x ; scanf("%d",&n) ;
    while(n--) scanf("%d",&x) , a[x]++ ;
    dp[1]=a[1] ;
    for(LL i=2;i<maxn;i++) dp[i]=max(dp[i-1],dp[i-2]+i*a[i]) ;
    printf("%I64d\n",dp[maxn-1]) ;
}
