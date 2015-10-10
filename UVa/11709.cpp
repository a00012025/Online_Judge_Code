#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
map<string,int> mp ;
vector<int> v1[2000],v2[2000] ;
int topo[2000],t ;
bool vis[2000] ;

bool no(char k)
{
    if((k<'A' || k>'Z') && (k<'a' || k>'z')) return 1 ;
    return 0 ;
}

void dfs1(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v1[n].size();i++) if(!vis[v1[n][i]]) dfs1(v1[n][i]) ;
    topo[--t]=n ;
}

void dfs2(int n)
{
    vis[n]=1 ;
    for(int i=0;i<v2[n].size();i++) if(!vis[v2[n][i]]) dfs2(v2[n][i]) ;
}

main()
{
    int n,m ;
    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        mp.clear() ;
        for(int i=0;i<=n;i++) {v1[i].clear() ; v2[i].clear() ;}
        for(int i=1;i<=n;i++)
        {
            char s[100] ;
            gets(s) ;
            while(no(s[0])) gets(s) ;
            mp[s]=i ;
        }
        for(int i=1;i<=m;i++)
        {
            char s[100],t[100] ;
            gets(s) ; while(no(s[0])) gets(s) ;
            gets(t) ; while(no(s[0])) gets(t) ;
            v1[mp[s]].push_back(mp[t]);
            v2[mp[t]].push_back(mp[s]);
        }
        memset(vis,0,sizeof(vis)) ;
        t=n+1 ;
        for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i) ;
        memset(vis,0,sizeof(vis)) ;
        int scc=0 ;
        for(int i=1;i<=n;i++) if(!vis[topo[i]])
        {
            dfs2(topo[i]) ;
            scc++ ;
        }
        printf("%d\n",scc) ;
            //for(int i=1;i<=n;i++) printf("%d,",topo[i]);
            //printf("\n");
    }
}
