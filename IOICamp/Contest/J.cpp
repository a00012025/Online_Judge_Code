#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;
int a[maxn],n ;
bool vis[maxn] ;
int col[maxn] ;

void dfs0(int x)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
        dfs0(i) ;
}

bool dfs(int x,int c)
{
    col[x]=c ;
    for(auto i : v[x])
    {
        if(col[i]==col[x]) return 0 ;
        if(!col[i] && !dfs(i,3-c)) return 0 ;
    }
    return 1 ;
}

bool solve()
{
    memset(col,0,sizeof(col)) ;
    memset(vis,0,sizeof(vis)) ;
    int cnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        if(cnt++) return 0 ;
        dfs0(i) ;
    }

    if(!dfs(1,1)) return 1 ;

    int val=0 ;
    for(int i=1;i<=n;i++) if(a[i])
    {
        if(a[i]==col[i]) val|=1 ;
        else val|=2 ;
    }
    return val!=3 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() , scanf("%d",&a[i]) ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        if(solve()) printf("Paul Wang Bang Bang\n") ;
        else printf("Paul Wang Huai Huai\n") ;
    }
}
