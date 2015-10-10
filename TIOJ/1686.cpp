#include<bits/stdc++.h>
using namespace std;
const int maxn=20000+10 ;

vector<int> v1[maxn],v2[maxn],SCC[maxn] ;
bool vis[maxn] ;
int t,topo[maxn],scnt,scc[maxn] ;

void add_edge(int x,int y)
{
    v1[x].push_back(y) ;
    v2[y].push_back(x) ;
}

void dfs1(int x)
{
    vis[x]=1 ;
    for(auto i : v1[x]) if(!vis[i])
        dfs1(i) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ;
    SCC[scnt].push_back(x) ;
    for(auto i : v2[x]) if(!vis[i])
        dfs2(i) ;
}

vector<int> tmp ;
int ans[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,tp ; scanf("%d%d%d",&x,&y,&tp) ;
        if(tp==0) add_edge(x,y) , add_edge(y+n,x+n) ;
        else add_edge(x,y+n) , add_edge(y+n,x) ;
    }

    t=2*n+1 ;
    for(int i=1;i<=2*n;i++) if(!vis[i])
        dfs1(i) ;

    memset(vis,0,sizeof(vis)) ;
    scnt=0 ;
    for(int i=1;i<=2*n;i++) if(!vis[topo[i]])
        scnt++ , dfs2(topo[i]) ;

    for(int i=1;i<=scnt;i++)
    {
        tmp.clear() ;
        for(auto j : SCC[i]) tmp.push_back(j>n?j-n:j) ;
        sort(tmp.begin(),tmp.end()) ;
        tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
        ans[i]=tmp.size() ;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[scc[i+n]]-1) ;
}
