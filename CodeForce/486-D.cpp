#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define LL long long
#define MOD 1000000007
using namespace std;
int d,n,a[2001] ;
vector<int> v[2001] ;
bool vis[2001],vis2[2001] ;

LL dfs(int x,int val)
{
    vis2[x]=1 ;
    if(a[x]<val || a[x]>val+d) return 0LL ;
    if(a[x]==val && vis[x]) return 0LL ;
    LL ret=1LL ;
    for(int i=0;i<v[x].size();i++) if(!vis2[v[x][i]])
        ret *= (dfs(v[x][i],val)+1) , ret%=MOD ;
    return ret ;
}

main()
{
    scanf("%d%d",&d,&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].pb(y) ; v[y].pb(x) ;
    }
    memset(vis,0,sizeof(vis)) ;
    LL ans=0LL ;
    for(int i=1;i<=n;i++)
    {
        memset(vis2,0,sizeof(vis2)) ;
        ans+=dfs(i,a[i]) ; ans%=MOD ;
        vis[i]=1 ;
    }
    printf("%I64d\n",ans) ;
}
