#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> v1[500],v2[500] ;
bool vis[500] ;
int topo[500],t ;

void dfs1(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    for(int i=0;i<v1[n].size();i++) dfs1(v1[n][i]) ;
    topo[--t]=n ;
}

void dfs2(int n)
{
    if(vis[n]) return ;
    vis[n]=1 ;
    for(int i=0;i<v2[n].size();i++) dfs2(v2[n][i]) ;
}

main()
{
    int n,m;
    char c[100] ;
    for(int i=0;i<500;i++) {v1[i].clear() ; v2[i].clear() ;}
    scanf("%d %d",&n,&m) ;
    scanf("%s",c) ;
    for(int i=1;i<=n;i++)
    {
        if(c[i-1]=='<') for(int j=2;j<=m;j++)
        {
            v1[m*(i-1)+j].push_back(m*(i-1)+j-1) ;
            v2[m*(i-1)+j-1].push_back(m*(i-1)+j) ;
        }
        else for(int j=1;j<m;j++)
        {
             v1[m*(i-1)+j].push_back(m*(i-1)+j+1) ;
             v2[m*(i-1)+j+1].push_back(m*(i-1)+j) ;
        }
    }
    scanf("%s",c) ;
    for(int j=1;j<=m;j++)
    {
        if(c[j-1]=='^') for(int i=2;i<=n;i++)
        {
             v1[m*(i-1)+j].push_back(m*(i-2)+j) ;
             v2[m*(i-2)+j].push_back(m*(i-1)+j) ;
        }
        else for(int i=1;i<n;i++)
        {
             v1[m*(i-1)+j].push_back(m*(i)+j) ;
             v2[m*(i)+j].push_back(m*(i-1)+j) ;
        }
    }
    memset(vis,0,sizeof(vis)) ; t=m*n+1 ;
    for(int i=1;i<=n*m;i++) dfs1(i) ;
    memset(vis,0,sizeof(vis)) ;
    int scc=0 ;
    for(int i=1;i<=n*m;i++)
    {
        if(vis[topo[i]]) continue ;
        scc++ ;
        dfs2(topo[i]) ;
    }
    if(scc==1) printf("YES\n") ;
    else printf("NO\n") ;
}
