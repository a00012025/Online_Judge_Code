#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[301] ;
int group[301] ;
bool vis[301] ;

bool dfs(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++)
    {
        if(group[v[n][i]]==group[n]) return false ;
        else if(!vis[v[n][i]])
        {
            group[v[n][i]]=(!group[n]) ;
            if(!dfs(v[n][i])) return false ;
        }
    }
    return true ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(1)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(!(a+b)) break ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        memset(vis,0,sizeof(vis)) ;
        bool ans=1 ;
        for(int i=1;i<=n;i++) group[i]=-1 ;
        for(int i=1;i<=n;i++) if(!vis[i])
        {
            group[i]=1 ;
            if(!dfs(i)) {ans=0 ; break ;}
        }
        if(ans) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
