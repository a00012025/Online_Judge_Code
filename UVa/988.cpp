#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[1000001] ;
int topo[1000001],ans[1000001],t,n ;
bool vis[1000001] ;

void init()
{
    for(int i=0;i<n;i++)
    {
        v[i].clear() ;
        int m;
        scanf("%d",&m) ;
        while(m--)
        {
            int a;
            scanf("%d",&a) ;
            v[i].push_back(a) ;
        }
    }
}

void dfs(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i]])
        dfs(v[n][i]) ;
    topo[t++]=n ;
}

void topo_sort()
{
    memset(vis,0,sizeof(vis)) ;
    t=0 ;
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i) ;
}

void cal_ans()
{
    for(int i=0;i<n;i++)
    {
        ans[topo[i]]=0 ;
        if(!v[topo[i]].size()) ans[topo[i]]=1 ;
        else for(int j=0;j<v[topo[i]].size();j++)
            ans[topo[i]]+=ans[v[topo[i]][j]] ;
    }
}

main()
{
    bool fir=1 ;
    while(scanf("%d",&n)!=EOF)
    {
        init() ;
        topo_sort() ;
        cal_ans() ;
        if(fir) fir=0 ;
        else printf("\n") ;
        printf("%d\n",ans[0]) ;
    }
}
