#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
#define pii pair<LL,LL>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

pii p[maxn] ;
LL a[maxn],dp[maxn] ;
main()
{
    if(fopen("cowjog.in","r"))
    {
        freopen("cowjog.in","r",stdin) ;
        freopen("cowjog.out","w",stdout) ;
    }
    int n ; LL T ; scanf("%d%lld",&n,&T) ;
    for(int i=1;i<=n;i++)
    {
        LL x,y ; scanf("%lld%lld",&x,&y) ;
        p[i].F=x ;
        p[i].S=x+y*T ;
    }
    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) a[i]=p[i].S ;
    int num=0 ; dp[0]=INF ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=dp[num]) { dp[++num]=a[i] ; continue ; }
        int id=upper_bound(dp,dp+num+1,a[i],greater<LL>())-dp ;
        dp[id]=a[i] ;
    }
    printf("%d\n",num) ;
}
