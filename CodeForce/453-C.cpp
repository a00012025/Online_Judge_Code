#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn],ans ;
bool vis[maxn] ;
int c[maxn] ;
inline void go(int x){ans.push_back(x) ; c[x]^=1 ;}
void dfs(int x)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
    {
        go(i) ; dfs(i) ; go(x) ;
        if(c[i]) go(i) , go(x) ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]) ;
    for(int i=1;i<=n;i++) if(c[i])
    {
        go(i) ; dfs(i) ;
        if(c[i]) go(v[i][0]) , go(i) , go(v[i][0]) ;
        break ;
    }
    for(int i=1;i<=n;i++) if(c[i])
        {printf("-1\n") ; return 0 ;}
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
