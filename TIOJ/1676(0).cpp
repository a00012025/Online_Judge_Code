#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

LL a[maxn],s[maxn],dp[maxn],A[maxn],B[maxn] ;

main()
{
    freopen("1.txt","r",stdin) ;
    int T=1 ;
    scanf("%d",&T) ;
    while(T--)
{
    int n,k ;
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[n+1-i]) ;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i] ;
    dp[0]=0 ; A[0]=B[0]=0LL ;
    for(int i=1;i<=n;i++)
    {
        dp[i]=i*A[i-1]+B[i-1] ;
        for(int j=max(i-k,0);j<i-1;j++)
            dp[i]=max(dp[i],i*A[j]+B[j]) ;
        dp[i]-=((LL)i)*((LL)i) ;
        A[i]=2*i ; B[i]=dp[i]+s[i]-((LL)i)*((LL)i) ;
    }
    printf("%I64d\n",dp[n]) ;
}
}
