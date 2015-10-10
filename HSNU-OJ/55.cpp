#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+100 ;
int n ;
vector<int> v1[maxn],v2[maxn] ;
int topo[maxn],t,scc[maxn],scnt ;
bool vis[maxn] ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v1[x].size();i++) if(!vis[v1[x][i]])
        dfs1(v1[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x,int k)
{
    vis[x]=1 ; scc[x]=k ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i],k) ;
}

void SCC()
{
    scnt=0 ;
    memset(vis,0,sizeof(vis)) ;
    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i])
        dfs1(i) ;

    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]])
    {
        scnt++ ;
        dfs2(topo[i],scnt) ;
    }
}

bool in[maxn],out[maxn] ;
void get_new_edge()
{
    memset(in,0,sizeof(in)) ;
    memset(out,0,sizeof(out)) ;
    for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
        if(scc[i] != scc[v1[i][j]] )
        out[scc[i]]=1 , in[scc[v1[i][j]]]=1 ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ;
        while(1)
        {
            scanf("%d",&x) ;
            if(!x) break ;
            v1[i].push_back(x) , v2[x].push_back(i) ;
        }
    }
    SCC() ;
    get_new_edge() ;

    int ans1=0,ans2=0,zero=0 ;
    for(int i=1;i<=scnt;i++)
    {
        if(!in[i] && !out[i]) { zero++ ; continue ; }
        if(!in[i]) ans1++ ;
        if(!out[i]) ans2++ ;
    }
    if(!zero) printf("%d\n%d\n",ans1,ans1+ans2-1) ;
    else
    {
        if(!ans1 && !ans2)
        {
            if(zero==1) printf("1\n0\n") ;
            else printf("%d\n%d\n",zero,zero) ;
        }
        else printf("%d\n%d\n",ans1+zero,max(ans1,ans2)+zero) ;
    }
}
