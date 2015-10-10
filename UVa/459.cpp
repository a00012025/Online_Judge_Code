#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[50] ;
bool vis[50] ;

int id(char c)
{
    return c-'A' ;
}

void dfs(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++)
        if(!vis[v[n][i]])dfs(v[n][i]) ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char c[3] ;
        scanf("%s",c) ;
        int n=id(c[0]) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        gets(c) ;
        while(1)
        {
            if(!gets(c)) break ;
            if(c[0]<'A' || c[0]>'Z') break ;
            v[id(c[0])].push_back(id(c[1])) ;
            v[id(c[1])].push_back(id(c[0])) ;
        }
        int ans=0 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<=n;i++) if(!vis[i])
        {
            dfs(i) ;
            ans++ ;
        }
        printf("%d\n",ans) ;
        if(T)printf("\n");
    }
}
