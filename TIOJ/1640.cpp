#include<bits/stdc++.h>
#define LL long long
#define INF 1000000
using namespace std;
const int maxn=1000 ;

int d[maxn][maxn] ;

int dp(int n,int k)
{
    if(d[n][k]!=-1) return d[n][k] ;
    if(n==3)
    {
        if(k==0) return d[n][k]=3 ;
        if(k==1) return d[n][k]=2 ;
        if(k==2) return d[n][k]=1 ;
    }
    int &ans=d[n][k] ; ans=INF ;
    if(k==n-1) return ans=n-2 ;
    if(k==0)
    {
        ans=3+dp(n-1,2) ;
        ans=min(ans,max(2+dp(n,2),2+dp(n-1,1))) ;
        ans=min(ans,max(2+dp(n-1,0),2+dp(n-1,1))) ;
        return ans ;
    }
    if(k>1) ans=min(ans,1+dp(n-1,k-1)) ;
    if(k==n-2)
    {
        ans=min(ans,max(1,1+dp(n,k+1))) ;
        ans=min(ans,max(1+dp(n-1,k-1),1+dp(n-1,k))) ;
        return ans ;
    }
    ans=min(ans,max(dp(n-1,k)+1,dp(n-1,k-1)+1)) ;
    ans=min(ans,max(1+dp(n,k+1),1+dp(n-k,1))) ;
    ans=min(ans,max(2+dp(n-1,k+1),2+dp(n-k,2))) ;
    return ans ;
}

main()
{
//    memset(d,-1,sizeof(d)) ;
//    for(int i=3;i<maxn;i++) assert(dp(i,0)==(3*i-3)/2) ;
    LL n ;
    while(scanf("%lld",&n)==1)
    {
        LL ans=(3*n-3)/2 ;
        if(n>=2) printf("%lld %lld\n",n,ans) ;
    }
}
