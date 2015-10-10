#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<int> v[4000] ;
LL ans,vis[4000] ;
void dfs(int s,int x,int lev)
{
    if(lev==2) {if(x!=s) vis[x]++ ; return ;}
    for(int i=0;i<v[x].size();i++) dfs(s,v[x][i],lev+1) ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
    }
    ans=0 ;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis)) ;
        dfs(i,i,0) ;
        for(int j=1;j<=n;j++) ans+=vis[j]*(vis[j]-1)/2 ;
    }
    printf("%I64d\n",ans) ;
}
