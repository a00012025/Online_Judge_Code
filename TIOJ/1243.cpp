#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=2000+10 ;

vector<int> v[maxn] ;
bool G[maxn],vis[maxn] ;

int cnt,w[maxn],val[maxn] ;

void dfs(int x)
{
    vis[x]=1 ; val[cnt]++ ;
    for(auto i : v[x])
    {
        if(G[i]) w[cnt]++ ;
        else if(!vis[i]) dfs(i) ;
    }
}

int dp[maxn] ;
main()
{
    int n,k,num ;
    while(scanf("%d%d%d",&n,&k,&num)==3 && n+k+num)
    {
        memset(vis,0,sizeof(vis)) ;
        memset(G,0,sizeof(G)) ;
        for(int i=0;i<n;i++) v[i].clear() ;

        bool no= (num+k > n ? 1 : 0) ;
        while(num--)
        {
            int x ; scanf("%d",&x) ;
            G[x]=1 ;
        }
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }

        if(no) { printf("ACM rules!\n") ; continue ; }

        cnt=0 ;
        for(int i=0;i<n;i++) if(!G[i]&&!vis[i])
            cnt++ , w[cnt]=val[cnt]=0 , dfs(i) ;

        fill(dp,dp+maxn,INF) ; dp[0]=0 ;
        for(int i=1;i<=cnt;i++)
            for(int j=maxn-1;j>=val[i];j--)
                dp[j]=min(dp[j],dp[j-val[i]]+w[i]) ;
        int ans=INF ;
        for(int j=maxn-1;j>=k;j--) ans=min(ans,dp[j]) ;
        printf("%d\n",ans) ;
    }
}
