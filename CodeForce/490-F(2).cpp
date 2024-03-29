#include<bits/stdc++.h>
using namespace std;
const int maxn=6001 ;
vector<int> v[maxn] ;
bool vis[maxn] ;
int dp[maxn],num,a[maxn],ans ;

void dfs(int x)
{
    vis[x]=1 ; ans=max(ans,num) ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
    {
        int id=lower_bound(dp,dp+num+1,a[v[x][i]]) - dp ;
        int tmp=dp[id] ;
        dp[id]=a[v[x][i]] ;
        if(id==num+1) num++ , tmp=-1 ;
        dfs(v[x][i]) ;
        if(tmp==-1) num-- ;
        else dp[id]=tmp ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    ans=0 ;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis)) ;
        num=1 ; dp[1]=a[i] ;
        dfs(i) ;
    }
    printf("%d\n",ans) ;
}
