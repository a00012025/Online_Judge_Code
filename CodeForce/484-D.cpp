#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[1000001],dp[1000001],last[1000001] ;
bool good[1000001] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]) ;
    memset(good,0,sizeof(good)) ;
    for(int i=2;i<n;i++)
    {
        if(a[i-1]==a[i] && a[i]==a[i+1]) continue ;
        if(a[i-1]>a[i] && a[i]>a[i+1]) continue ;
        if(a[i-1]<a[i] && a[i]<a[i+1]) continue ;
        good[i]=1 ;
    }
    last[1]=-1 ;
    for(int i=1;i<=n;i++) last[i+1]=good[i] ? i : last[i] ;
    dp[1]=0 ;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) {dp[i]=dp[i-1] ; continue ;}
        int x=last[i] ;
        if(x==-1) dp[i]=abs(a[i]-a[1]) ;
        else dp[i]=max(dp[x-1]+abs(a[x]-a[i]) , dp[x]+abs(a[x+1]-a[i])) ;
    }
    printf("%I64d\n",dp[n]) ;
}
