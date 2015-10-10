#define NDEBUG
#include<bits/stdc++.h>
#define LL long long
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
using namespace std;
const LL INF=1LL<<60 ;
vector<int> v[100001] ;
int fa[100001],n ;
LL c1,c2,dp[100001][3] ;
LL B_val[100001] ;
void dfs(int x)
{
    if(v[x].size()==1 && x!=1)
    {
        dp[x][1]=min(c1,c2) ; dp[x][2]=0LL ; return ;
    }
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        {fa[v[x][i]]=x ; dfs(v[x][i]) ;}
    LL ans1=0LL , ans2=B_val[x]+c2 , ans3=INF ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        ans1 += min(dp[v[x][i]][1],dp[v[x][i]][2]) ,
        ans3=min(ans3 , -min(dp[v[x][i]][1],dp[v[x][i]][2])+B_val[v[x][i]]+c2);
    ans3 += ans1 ;
    ans1 += c1 ;
    dp[x][1]=min(ans1,min(ans2,ans3)) ;

    dp[x][2]=0LL ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        dp[x][2] += dp[v[x][i]][1] ;

    if(fa[x]!=x && fa[fa[x]]!=fa[x]) B_val[fa[fa[x]]]+=min(dp[x][1],dp[x][2]) ;
    debugf("dp[%d] : %I64d,%I64d\n",x,dp[x][1],dp[x][2]) ;
}

main()
{
    while(scanf("%d%lld%lld",&n,&c1,&c2) && n)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        fa[n]=n ;
        memset(B_val,0LL,sizeof(B_val)) ;
        dfs(n) ;
        printf("%lld\n",min(dp[n][1],dp[n][2])) ;
    }
}
