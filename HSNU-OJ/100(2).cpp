#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010 ;
struct P
{
    int val,cnt;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};
vector<int> v1[maxn],v2[maxn],tmp[maxn] ;
vector<P> v[maxn] ;
bool ok[maxn],vis[maxn] ;
int topo[maxn],scc[maxn],num[maxn],t,scnt ;

void dfs1(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v1[x].size();i++) if(!vis[v1[x][i]])
        dfs1(v1[x][i]) ;
    topo[--t]=x ;
}

void dfs2(int x)
{
    vis[x]=1 ; scc[x]=scnt ; num[scnt]++ ; debugf("scc[%d]=%d\n",x,scnt) ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs2(v2[x][i]) ;
}

main()
{
    int n ;scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int t ; scanf("%d",&t) ;
        while(t--)
        {
            int x ; scanf("%d",&x) ;
            v1[i].push_back(x) ;
            v2[x].push_back(i) ;
        }
    }
    memset(vis,0,sizeof(vis)) ;
    t=n+1 ;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i) ;
    scnt=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!vis[topo[i]]) scnt++ , dfs2(topo[i]) ;

    for(int i=1;i<=scnt;i++) ok[i]=1 ;
    if(scnt!=n)
    {
        for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
            if(scc[i]!=scc[v1[i][j]])
                tmp[scc[i]].push_back(scc[v1[i][j]]) , ok[scc[v1[i][j]]]=0 ;

        for(int i=1;i<=scnt;i++)
        {
            sort(tmp[i].begin(),tmp[i].end()) ;
            int cnt=0 ;
            for(int j=0;j<tmp[i].size();j++)
            {
                if(j>0 && tmp[i][j]!=tmp[i][j-1])
                {
                    v[i].push_back((P){tmp[i][j-1],cnt}) ;
                    cnt=1 ;
                }
                else cnt++ ;
            }
            if(!tmp[i].empty())
                v[i].push_back((P){tmp[i][tmp[i].size()-1],cnt}) ;
            tmp[i].clear() ;
        }
    }

    else
    {
        for(int i=1;i<=n;i++) for(int j=0;j<v1[i].size();j++)
            if(scc[i]!=scc[v1[i][j]])
                v[scc[i]].push_back((P){scc[v1[i][j]],1}) ,
                ok[scc[v1[i][j]]]=0 ;
        for(int i=1;i<=scnt;i++) sort(v[i].begin(),v[i].end()) ;
    }

    queue<int> q ;
    for(int i=1;i<=scnt;i++) if(ok[i]) q.push(i) ;
    int id=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        int j=0 ;
        for(;id<=n&&ok[id];id++) ;
        for(int i=id;i<=scnt;i++) if(!ok[i])
        {
            for(;j<v[u].size()&&v[u][j].val<i;j++) ;
            if(j<v[u].size()&&v[u][j].val==i&&v[u][j].cnt==num[u]*num[i])
                continue ;
            ok[i]=1 ; q.push(i) ;
            for(;id<=n&&ok[id];id++) ;
        }
    }
    int ans=0 ;
    for(int i=1;i<=n;i++) if(ok[scc[i]]) ans++ ;
    printf("%d",ans) ;
    for(int i=1;i<=n;i++) if(ok[scc[i]]) printf(" %d",i) ;
    printf("\n") ;
}
