#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=40000 ;
bool vis[maxn] ;
int p[maxn],pcnt=0 ;
void make_prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

int n,a[400],cost[400] ;
int val[400],dp[2000] ;

int DP(int cnt)
{
    for(int i=0;i<(1<<cnt);i++) dp[i]=INF ;
    dp[0]=0 ;
    for(int i=1;i<(1<<cnt);i++) for(int j=1;j<=n;j++)
        if(val[j])
    {
        int val2= (val[j]&i) ;
        dp[i]=min(dp[i],dp[i-val2]+cost[j]) ;
    }
    return dp[(1<<cnt)-1] ;
}

int pr[30],cnt ;
main()
{
    make_prime() ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&cost[i]) ;

    int g=a[1] ;
    for(int i=2;i<=n;i++) g=__gcd(g,a[i]) ;
    if(g!=1) { printf("-1\n") ; return 0 ; }

    int ans=INF ;
    for(int i=1;i<=n;i++) if(a[i]==1) ans=min(ans,cost[i]) ;

    for(int i=1;i<=n;i++) if(a[i]!=1)
    {
        memset(val,0,sizeof(val)) ;
        cnt=0 ; int tmp=a[i] ;
        for(int j=1;j<=pcnt;j++) if(tmp%p[j]==0)
        {
            pr[cnt++]=p[j] ;
            while(tmp%p[j]==0) tmp/=p[j] ;
        }
        if(tmp!=1) pr[cnt++]=tmp ;

        for(int j=0;j<cnt;j++) for(int k=1;k<=n;k++)
            if(a[k]%pr[j]) val[k] |= (1<<j) ;
        ans=min(ans,cost[i]+DP(cnt)) ;
    }
    printf("%d\n",ans) ;
}
