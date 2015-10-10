#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=200000+10 ;

LL dp[maxn][2] ;
vector<int> v[maxn] ;
void dfs(int x)
{
    if(v[x].empty())
    {
        dp[x][0]=0 ;
        dp[x][1]=1 ;
        return ;
    }
    dp[x][0]=1 ; dp[x][1]=0 ;
    for(auto i : v[x])
    {
        dfs(i) ;
        LL t0=dp[x][0] , t1=dp[x][1] ;
        dp[x][0]=(t0*(dp[i][0]+1)+t1*dp[i][1])%MOD ;
        dp[x][1]=(t0*dp[i][1]+t1*(dp[i][0]+1))%MOD ;
    }
    dp[x][0]*=2 ; dp[x][0]%=MOD ;
    dp[x][1]*=2 ; dp[x][1]%=MOD ;

    LL sub0=1 , sub1[2]={1,0} ;
    for(auto i : v[x])
    {
        sub0=sub0*(dp[i][0]+1)%MOD ;
        LL t0=sub1[0] , t1=sub1[1] ;
        sub1[0]=(t0+t1*dp[i][1])%MOD ;
        sub1[1]=(t1+t0*dp[i][1])%MOD ;
    }
    dp[x][0]-=sub0 ; if(dp[x][0]<0) dp[x][0]+=MOD ;
    dp[x][1]-=sub1[1] ; if(dp[x][1]<0) dp[x][1]+=MOD ;
    swap(dp[x][0],dp[x][1]) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=2;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        v[x].push_back(i) ;
    }
    dfs(1) ;
    printf("%d\n",(dp[1][0]+dp[1][1])%MOD) ;
}
