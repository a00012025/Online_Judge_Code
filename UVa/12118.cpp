#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> v[1001] ;
bool vis[1001] ;
int odd,comp,allodd,zeronum,noedge ;

void dfs(int n)
{
    if(v[n].size()%2) odd++ ;
    vis[n]=1 ;
    for(int i=0;i<v[n].size();i++) if(!vis[v[n][i]])
        dfs(v[n][i]) ;
}

main()
{
    int n,e,t,tc=0 ;
    while(scanf("%d%d%d",&n,&e,&t)==3 && n+e+t)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=e;i++)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            v[a].push_back(b) ;
            v[b].push_back(a) ;
        }
        memset(vis,0,sizeof(vis)) ;
        comp=0 ; allodd=0 ; zeronum=0 ; noedge=0 ;
        for(int i=1;i<=n;i++)
        {
            if(!v[i].size()) noedge++ ;
            if(v[i].size()%2) allodd++ ;
            if(vis[i]) continue ;
            odd=0 ; comp++ ;
            dfs(i) ;
            if(!odd) zeronum++ ;
        }
        int ans ;
        if(!allodd && zeronum==noedge) ans=0 ;
        else if(!allodd) ans=comp-noedge-1 ;
        else ans=(allodd/2)-1+zeronum-noedge ;
        printf("Case %d: %d\n",++tc,(ans+e)*t) ;
    }
}
