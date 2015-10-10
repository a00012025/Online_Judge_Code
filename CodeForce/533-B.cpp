#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=200000+10 ;

vector<int> v[maxn] ;
int fa[maxn],val[maxn] ;
LL dp[maxn][2] ;

void dfs(int x)
{
    if(v[x].empty())
    {
        dp[x][0]=0 ;
        dp[x][1]=val[x] ;
        return ;
    }
    for(auto i : v[x]) dfs(i) ;

    dp[x][1]=-INF ;
    for(auto i : v[x])
    {
        LL t0=dp[x][0] , t1=dp[x][1] ;
        dp[x][0]=max(t0+dp[i][0],t1+dp[i][1]) ;
        dp[x][1]=max(t1+dp[i][0],t0+dp[i][1]) ;
    }
    dp[x][1]=max(dp[x][1],dp[x][0]+val[x]) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&fa[i],&val[i]) ;
        if(i!=1) v[fa[i]].push_back(i) ;
    }
    dfs(1) ;
    printf("%I64d\n",max(dp[1][0],dp[1][1])) ;
}
