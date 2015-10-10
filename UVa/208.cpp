#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> v[21] ;
int now[21],k,cnt ;
bool vis[21] ;

void dfs1(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i]])
        dfs1(v[n][i]) ;
}

bool can_arrive(int goal)
{
    memset(vis,0,sizeof(vis)) ;
    dfs1(1) ;
    if(vis[goal]) return 1;
    else return 0 ;
}

void dfs(int n)
{
    if(now[n]==k)
    {
        cnt++ ;
        for(int i=1;i<=n;i++) printf("%d%c",now[i],i==n?'\n':' ') ;
        return ;
    }
    for(int i=0;i<v[now[n]].size();i++) if(!vis[v[now[n]][i]])
    {
        vis[v[now[n]][i]]=1 ;
        now[n+1]=v[now[n]][i] ;
        dfs(n+1) ;
        vis[v[now[n]][i]]=0 ;
    }
}

main()
{
    int tc=0;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=0;i<=20;i++) v[i].clear() ;
        while(1)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(!(a+b)) break ;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        printf("CASE %d:\n",++tc) ;
        for(int i=1;i<=20;i++) sort(v[i].begin(),v[i].end()) ;
        cnt=0 ;
        if(can_arrive(k))
        {
            for(int i=1;i<=20;i++) sort(v[i].begin(),v[i].end()) ;
            memset(vis,0,sizeof(vis)) ; now[1]=1 ; vis[1]=1 ;
            dfs(1) ;
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,k);
    }
}
