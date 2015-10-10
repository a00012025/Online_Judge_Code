#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;
int deg[maxn],fort[maxn],n,k ;
int num[maxn],d[maxn] ;

queue<int> q ;
bool vis[maxn] ;
int BFS(DB rat)
{
    for(int i=1;i<=n;i++)
        num[i]=ceil(deg[i]*rat) ,
        d[i]=deg[i] ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=k;i++) vis[fort[i]]=1 , q.push(fort[i]) ;

    int ret=0 ;
    while(!q.empty())
    {
        ret++ ;
        int u=q.front() ; q.pop() ;
        for(auto i : v[u]) if(!vis[i])
        {
            d[i]-- ;
            if(d[i]<num[i]) vis[i]=1 , q.push(i) ;
        }
    }
    return ret ;
}

main()
{
    int m ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=k;i++) scanf("%d",&fort[i]) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    for(int i=1;i<=n;i++) deg[i]=v[i].size() ;
    DB l=0 , r=1 ;
    while(r-l>1e-8)
    {
        DB mid=(r+l)/2 ;
        if(BFS(mid)==n) r=mid ;
        else l=mid ;
    }
    BFS(l) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) if(!vis[i]) ans++ ;
    printf("%d\n",ans) ;
    for(int i=1;i<=n;i++) if(!vis[i]) printf("%d%c",i,--ans?' ':'\n') ;
}
