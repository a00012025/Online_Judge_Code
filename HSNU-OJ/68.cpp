#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100001 ;
vector<int> v[maxn] ;
int low[maxn],lev[maxn],sz[maxn],n ;
bool vis[maxn],cut[maxn] ;
LL ans[maxn] ;

void dfs(int x,int l)
{
    vis[x]=1 ; low[x]=lev[x]=l ; sz[x]=1 ;
    int cnt=0 ;
    int sum=0 ; LL sqsum=0LL ;
    for(int i=0;i<v[x].size();i++)
    {
        if(vis[v[x][i]]) low[x]=min(low[x],lev[v[x][i]]) ;
        else
        {
            cnt++ ; dfs(v[x][i],l+1) ;
            sz[x]+=sz[v[x][i]] ;
            low[x]=min(low[x],low[v[x][i]]) ;
            if(low[v[x][i]]>=l)
            {
                if(x!=1 || cnt>1) cut[x]=1 ;
                sum+=sz[v[x][i]] ;
                sqsum+= ((LL)sz[v[x][i]])*((LL)sz[v[x][i]]) ;
            }
        }
    }
    sqsum += ((LL)n-1-sum)*((LL)n-1-sum) ;
    ans[x]=2*(n-1) ;
    if(cut[x]) ans[x]+=((LL)n-1)*((LL)n-1)-sqsum ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    memset(vis,0,sizeof(vis)) ;
    memset(cut,0,sizeof(cut)) ;
    memset(ans,0LL,sizeof(ans)) ;
    dfs(1,0) ;
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]) ;
}
