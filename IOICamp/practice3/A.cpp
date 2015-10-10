#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000] ;
bool vis[2000] ;
void dfs(int x)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i]) dfs(i) ;
}
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        int cnt=0 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++) if(!vis[i]) cnt++ , dfs(i) ;
        if(n>1 && cnt==1) printf("Chen Li Bang Bang\n") ;
        else printf("Chen Li Huai Huai\n") ;
    }
}
