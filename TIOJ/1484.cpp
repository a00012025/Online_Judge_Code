#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;

int vis[maxn] ;
int lev[maxn],low[maxn] ;

bool dfs(int x,int l)
{
    lev[x]=low[x]=l ;
    vis[x]=-1 ;
    int num=0 ;
    for(auto i : v[x])
    {
        if(vis[i]==1) return 0 ;
        else if(vis[i]==-1) num++ , low[x]=min(low[x],lev[i]) ;
        else
        {
            if(!dfs(i,l+1)) return 0 ;
            low[x]=min(low[x],low[i]) ;
            if(low[i]>lev[x]) return 0 ;
            if(low[i]<lev[x]) num++ ;
        }
    }
    vis[x]=1 ;
    return num<2 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            if(x!=y) v[x].push_back(y) ;
        }
        fill(vis,vis+n,0) ;
        if(!dfs(0,0)) printf("NO\n") ;
        else
        {
            bool ok=1 ;
            for(int i=0;i<n;i++) if(!vis[i])
                {ok=0 ; break ;}
            if(!ok) printf("NO\n") ;
            else printf("YES\n") ;
        }
    }
}
