#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100+10 ;

LL d[maxn][maxn] ;
int a[maxn] ;

LL dp(int l,int r)
{
    if(l==r) return a[l] ;
    if(d[l][r]!=-1) return d[l][r] ;
    LL &ans=d[l][r] ; ans=0LL ;
    int len=r-l+1 ;
    for(int i=l;i<r;i++)
        if(len%2) ans=max(ans,dp(l,i)*dp(i+1,r)) ;
        else ans=max(ans,dp(l,i)+dp(i+1,r)) ;
    return ans ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        memset(d,-1,sizeof(d)) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        printf("%lld\n",dp(1,n)) ;
    }
}
