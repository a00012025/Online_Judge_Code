#include<bits/stdc++.h>
#include "interactive/363.h"
using namespace std;

bool ask[1000][1000],vis[1000] ;
vector<int> v[1000] ;
int t,topo[1000] ;

void dfs(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs(v[x][i]) ;
    topo[--t]=x ;
}

main()
{
    srand(time(NULL)) ;
    int n=Ramen() ;
    memset(ask,0,sizeof(ask)) ;
    for(int i=1;i<=min(599,n*(n-1)/2);i++)
    {
        int x,y ;
        while(1)
        {
            x=abs(rand())%n , y=abs(rand())%n ;
            if(x!=y && !ask[x][y]) break ;
        }
        ask[x][y]=ask[y][x]=1 ;
        if(Compare(x,y)==1) v[x].push_back(y) ;
        else v[y].push_back(x) ;
    }

    int p[800] ;
    for(int i=0;i<n;i++)
    {
        while(1)
        {
            int x=(((rand())%n)+2*n)%n ;
            if(!vis[x]) {p[i]=x ; vis[x]=1 ; break ; }
        }
    }

    t=n ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=n-1;i>=0;i--) if(!vis[p[i]]) dfs(p[i]) ;
    Answer(topo[n-1],topo[0]) ;
}
