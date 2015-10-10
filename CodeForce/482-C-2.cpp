#include<bits/stdc++.h>
#define DB double
#define LL long long
using namespace std;
const int maxn=20,maxm=50 ;

int n,m,num[1<<maxn] ;
char s[maxm][maxn] ;

LL bit[1<<maxn] ;
void getnum()
{
    for(int i=0;i<(1<<n);i++) num[i]=m ;
    for(int i=0;i<m;i++) for(int j=i+1;j<m;j++)
    {
        int same=0 ;
        for(int k=0;k<n;k++) if(s[i][k]==s[j][k])
            same|=(1<<k) ;
        bit[same]|=(1LL<<i) ;
        bit[same]|=(1LL<<j) ;
    }

    for(int i=((1<<n)-1);i>=0;i--)
    {
        for(int j=0;j<n;j++) if(!(i&(1<<j)))
            bit[i]|=bit[i^(1<<j)] ;
        num[i]=__builtin_popcountll(bit[i]) ;
    }
}

DB dp[1<<maxn] ;
DB DP(int S)
{
    if(dp[S]>=0) return dp[S] ;
    DB &ans=dp[S] ; ans=0 ;
    int k=0 ;
    for(int i=0;i<n;i++) if(!(S&(1<<i)))
        k++ , ans+=DP(S^(1<<i)) ;
    ans=ans/k+num[S] ;
    return ans ;
}

main()
{
    scanf("%d",&m) ;
    for(int i=0;i<m;i++)
    {
        scanf("%s",s[i]) ;
        if(!i) n=strlen(s[i]) ;
    }

    getnum() ;

    fill(dp,dp+(1<<n),-1) ;
    dp[(1<<n)-1]=0 ;
    printf("%.15f\n",DP(0)/m) ;
}
