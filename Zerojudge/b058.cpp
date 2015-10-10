#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int maxn=100000 ;
vector<int> v[maxn+10],anc[maxn+10] ;
int tim[maxn+10],in[maxn+10],data[maxn+10],ans ;
bool vis[maxn+10] ;
void dfs(int n)
{
    for(int i=0;i<v[n].size();i++)
    {
        int t=v[n][i] ;
        if(tim[t]+data[n]==data[t]) anc[t].push_back(n) ;
        else if(tim[t]+data[n]>data[t])
        {
            anc[t].clear() ;
            anc[t].push_back(n) ;
            data[t]=tim[t]+data[n] ;
            dfs(t) ;
        }
    }
}
void dfs2(int n)
{
    vis[n]=1 ;
    ans++ ;
    for(int i=0;i<anc[n].size();i++)
    {
        if(!vis[anc[n][i]]) dfs2(anc[n][i]) ;
    }
}
main()
{
    int n,m ;
    while(scanf("%d %d",&n,&m)!=EOF){
    memset(tim,0,sizeof(tim)) ;
    memset(in,0,sizeof(in)) ;
    memset(data,0,sizeof(data)) ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) scanf("%d",&tim[i]) ;
    for(int i=0;i<=n;i++) {v[i].clear() ; anc[i].clear() ;}
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b) ;
        in[b]++ ;
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]) continue ;
        data[i]=tim[i] ;
        dfs(i) ;
    }
    int M=0 ; ans=0 ;
    for(int i=1;i<=n;i++)
        if(M<data[i] && !v[i].size()) M=data[i] ;
    for(int i=1;i<=n;i++)
    {
        if(data[i]<M || v[i].size()) continue ;
        dfs2(i) ;
    }
    printf("%d\n",ans) ;
}
}
