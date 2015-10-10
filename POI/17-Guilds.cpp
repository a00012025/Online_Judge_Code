#include<bits/stdc++.h>
using namespace std;

vector<int> v[200001] ;
int ans[200001] ;

void dfs(int x,int t)
{
    ans[x]=t ;
    for(int i=0;i<v[x].size();i++) if(!ans[v[x][i]])
    {
        dfs(v[x][i],3-t) ;
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
    bool ok=1 ;
    for(int i=1;i<=n;i++) {if(v[i].empty()) ok=0 ; break ;}
    if(!ok){ printf("NIE\n") ; return 0 ; }
    memset(ans,0,sizeof(ans)) ;
    for(int i=1;i<=n;i++) if(!ans[i]) dfs(i,1) ;
    for(int i=1;i<=n;i++)
    {
        int x=ans[i] ;
        for(int j=0;j<v[i].size();j++) x|=ans[v[i][j]] ;
        if(x!=3) { printf("NIE\n") ; return 0 ; }
    }
    printf("TAK\n") ;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==1) printf("K\n") ;
        else printf("S\n") ;
    }
}
