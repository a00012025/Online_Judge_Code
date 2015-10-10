#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

vector<int> v[maxn] ;
int dp[2][maxn] ;

void dfs(int x,int f)
{
    for(auto i : v[x]) if(i!=f)
        dfs(i,x) ;
    if(x!=1 && v[x].size()==1)
    {
        dp[0][x]=0 ;
        dp[1][x]=1 ;
        return ;
    }

    dp[1][x]=1 ;
    for(auto i : v[x]) if(i!=f)
        dp[1][x]+=min(dp[0][i],dp[1][i]) ;
    dp[0][x]=0 ;
    for(auto i : v[x]) if(i!=f)
        dp[0][x]+=dp[1][i] ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dfs(1,1) ;
    printf("%d\n",min(dp[0][1],dp[1][1])) ;
}
