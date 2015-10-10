#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

vector<int> v[maxn],ans ;

bool vis[maxn] ;
int lev[maxn],fa[maxn] ;

int dfs(int x,int l)
{
    int low,son=0 ;
    lev[x]=low=l ;
    vis[x]=1 ;
    for(auto i : v[x]) if(i!=fa[x])
    {
        if(vis[i]) low=min(low,lev[i]) ;
        else
        {
            son++ ;
            fa[i]=x ;
            int tmp=dfs(i,l+1) ;
            if(x!=1 && tmp>=lev[x]) ans.push_back(x) ;
            low=min(low,tmp) ;
        }
    }
    if(x==1 && son>1) ans.push_back(1) ;
    return low ;
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
        ans.clear() ;
        memset(vis,0,sizeof(vis)) ;
        fa[1]=1 ; dfs(1,0) ;
        sort(ans.begin(),ans.end()) ;
        ans.resize(unique(ans.begin(),ans.end())-ans.begin()) ;
        printf("%d\n",ans.size()) ;
        if(ans.empty()) printf("0") ;
        else for(auto i : ans) printf("%d ",i) ;
        printf("\n") ;
    }
}
