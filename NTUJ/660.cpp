#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v1[maxn],v2[maxn] ;
int topo[maxn],t ;
bool vis[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i]) dfs1(i) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ;
    for(auto i : v2[x]) if(!vis[i]) dfs2(i) ;
}

int solve(int n,int m)
{
    for(int i=0;i<n;i++) v1[i].clear() , v2[i].clear() ;
    fill(vis,vis+n,0) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
    }
    t=n ;
    for(int i=0;i<n;i++) if(!vis[i]) dfs1(i) ;
    fill(vis,vis+n,0) ;
    int ans=0 ;
    for(int i=0;i<n;i++) if(!vis[topo[i]])
        dfs2(topo[i]) , ans++ ;
    return ans ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m) printf("%d\n",solve(n,m)) ;
}
