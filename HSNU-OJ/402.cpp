#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10,maxm=200000+10 ; ;

struct P{int x,y;};
vector<P> edge,ans ;
vector<int> v[maxn] ;
int val[maxn] ;
void change(int id)
{
    swap(edge[id].x,edge[id].y) ;
    val[edge[id].x]++ ;
    val[edge[id].y]++ ;
}

bool vis[maxn] ;
void dfs(int x)
{
    vis[x]=1 ;
    for(auto i : v[x])
    {
        int to= edge[i].x==x ? edge[i].y : edge[i].x ;
        if(vis[to]) continue ;
        dfs(to) ;
        if(val[to]%2) change(i) ;
    }
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        ans.clear() ; edge.clear() ;
        fill(val+1,val+n+1,0) ;
        fill(vis+1,vis+n+1,0) ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            if(x==y) { val[x]++ ; ans.push_back((P){x,x}) ; continue ; }
            edge.push_back((P{x,y})) ; val[x]++ ;
            int sz=edge.size() ;
            v[x].push_back(sz-1) ; v[y].push_back(sz-1) ;
        }

        for(int i=1;i<=n;i++) if(!vis[i])
        {
            dfs(i) ;
            if(val[i]%2) ans.push_back((P){i,i}) ;
        }
        printf("%d\n",ans.size()+edge.size()) ;
        for(auto i : ans) printf("%d %d\n",i.x,i.y) ;
        for(auto i : edge) printf("%d %d\n",i.x,i.y) ;
    }
}
