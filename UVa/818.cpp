#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
bool G[16][16] ;
int maxd,n,deg[16],vis[16],fa[16] ;

bool dfs1(int x)
{
    vis[x]=-1 ;
    for(int i=1;i<=n;i++) if(G[i][x] && vis[i]!=1)
    {
        if(i==fa[x]) continue ;
        fa[i]=x ;
        if(vis[i]==-1 || dfs1(i)) return 1 ;
    }
    vis[x]=1 ;
    return 0;
}

void dfs2(int x)
{
    vis[x]=1 ;
    for(int i=1;i<=n;i++) if(G[i][x] && !vis[i])
        dfs2(i) ;
}

bool have_cycle()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        fa[i]=i ;
        if(dfs1(i)) return 1;
    }
    return 0;
}

int component()
{
    int ret=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        dfs2(i) ;
        ret++ ;
    }
    return ret ;
}

bool check()
{
    for(int i=1;i<=n;i++) if(deg[i]>2) return 0 ;
    if(have_cycle()) return 0;
    int num=component() ;
    if(num-maxd <= maxd+1) return 1;
    else return 0;
}

bool iddfs(int num,int last)
{
    if(num==maxd)
    {
        if(check()) return 1;
        else return 0;
    }
    for(int i=last+1;i<=n;i++)
    {
        vector<int> tem ;
        for(int j=1;j<=n;j++) if(G[i][j])
        {
            tem.push_back(j) ;
            G[i][j]=G[j][i]=0 ;
            deg[i]-- ; deg[j]-- ;
        }
        if(iddfs(num+1,i)) return 1;
        for(int j=0;j<tem.size();j++)
        {
            G[i][tem[j]]=G[tem[j]][i]=1 ;
            deg[tem[j]]++ ; deg[i]++ ;
        }
    }
    return 0;
}

main()
{
        //freopen("1.txt","r",stdin);
        //freopen("2.txt","w",stdout);
    int tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        memset(G,0,sizeof(G)) ;
        memset(deg,0,sizeof(deg)) ;
        while(1)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            if(a==-1 && b==-1) break ;
            if(G[a][b] || a==b) continue ;
            G[a][b]=G[b][a]=1 ;
            deg[a]++ ; deg[b]++ ;
        }
        maxd=0 ;
        for(;;maxd++) if(iddfs(0,0)) break ; //else printf("%d\n",maxd) ;
        printf("Set %d: Minimum links to open is %d\n",++tc,maxd) ;
    }
}
