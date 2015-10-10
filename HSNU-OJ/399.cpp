#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int w[maxn] ;
vector<int> v1[maxn],v2[maxn] ;
bool vis1[maxn],vis2[maxn] ;
LL dp[2][maxn] ;

void dp1(int x)
{
    if(vis1[x]) return ;
    vis1[x]=1 ;
    LL &ans=dp[0][x] ; ans=w[x] ;
    for(auto i : v1[x])
    {
        dp1(i) ;
        ans=max(ans,w[x]+dp[0][i]) ;
    }
}

void dp2(int x)
{
    if(vis2[x]) return ;
    vis2[x]=1 ;
    LL &ans=dp[1][x] ; ans=w[x] ;
    for(auto i : v2[x])
    {
        dp2(i) ;
        ans=max(ans,w[x]+dp[1][i]) ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
    }

    for(int i=1;i<=n;i++) dp1(i) ;
    for(int i=1;i<=n;i++) dp2(i) ;
    LL maxl=0LL ;
    for(int i=1;i<=n;i++) maxl=max(maxl,dp[0][i]) ;
    for(int i=1;i<=n;i++)
    {
        LL l=dp[0][i]+dp[1][i]-w[i] ;
        printf("%lld\n",maxl-l) ;
    }
}
