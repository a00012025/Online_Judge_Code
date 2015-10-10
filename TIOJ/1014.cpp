#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;

LL d[17][1<<16] ;
LL t[17],n ;

LL dp(int x,int S)
{
    if(d[x][S]!=-1) return d[x][S] ;
    LL &ans=d[x][S] ; ans=INF ;

    if(S==(1<<x))
    {
        return ans= (x+t[x])/t[x]*t[x] ;
    }

    for(int i=0;i<n;i++) if(i!=x && (S&(1<<i)))
    {
        LL tmp=dp(i,S^(1<<x)) ;
        tmp+= i>=x ? i-x : x-i ;
        ans= min(ans,(tmp+t[x]-1)/t[x]*t[x]) ;
    }
    return ans ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%lld",&t[i]) ;
    memset(d,-1,sizeof(d)) ;
    LL ans=INF ;
    for(int i=0;i<n;i++) ans=min(ans,dp(i,(1<<n)-1)) ;
    printf("%lld\n",ans) ;
}
