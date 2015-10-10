#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=300 ;
struct P{int from,to,flow,cap;};
vector<P> edge ;
vector<int> v[maxn] ;

struct Dinic
{
    int st,ed ;

    void add_edge(int from,int to,int cap)
    {
        edge.push_back((P){from,to,0,cap}) ;
        edge.push_back((P){to,from,0,0}) ;
        int z=edge.size() ;
        v[from].push_back(z-2) ;
        v[to].push_back(z-1) ;
    }

    bool vis[maxn] ;
    int d[maxn] ;

    bool BFS()
    {
        memset(vis,0,sizeof(vis)) ;
        queue<int> q ;
        q.push(st) ; d[st]=0 ; vis[st]=1 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(auto i : v[u])
            {
                P &e=edge[i] ;
                if(!vis[e.to] && e.cap>e.flow)
                {
                    d[e.to]=d[u]+1 ;
                    vis[e.to]=1 ;
                    q.push(e.to) ;
                }
            }
        }
        return vis[ed] ;
    }

    int cur[maxn] ;
    int DFS(int x,int a)
    {
        if(x==ed || a==0) return a ;
        int flow=0 , f ;
        for(int &i=cur[x];i<v[x].size();i++)
        {
            P &e=edge[v[x][i]] ;
            if(d[e.to]==d[x]+1 && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                flow+=f ;
                e.flow+=f ;
                edge[v[x][i]^1].flow-=f ;
                a-=f ;
                if(a==0) break ;
            }
        }
        return flow ;
    }

    int MaxFlow(int st,int ed)
    {
        this->st = st ;
        this->ed = ed ;
        int ret=0 ;
        while(BFS())
        {
            memset(cur,0,sizeof(cur)) ;
            ret+=DFS(st,INF) ;
        }
        return ret ;
    }

}dinic ;

bool isp(int x)
{
    if(x==1) return 0 ;
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;
    return 1 ;
}

int a[400] ;
vector<int> v0[400] ;
int col[400] ;

void dfs(int x)
{
    for(auto i :v0[x]) if(!col[i])
        col[i]=3-col[x] , dfs(i) ;
}

vector<int> ans[200] ;
int acnt=0 ;

void dfs2(int x)
{
    col[x]=1 ; ans[acnt].push_back(x) ;
    for(auto i : v0[x]) if(!col[i])
        dfs2(i) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(i!=j && isp(a[i]+a[j]))
            v0[i].push_back(j) , v0[j].push_back(i) ;

    for(int i=1;i<=n;i++) if(!col[i])
        col[i]=1 , dfs(i) ;

    for(int i=1;i<=n;i++)
    {
        if(col[i]==1) dinic.add_edge(n+1,i,2) ;
        else dinic.add_edge(i,n+2,2) ;
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(isp(a[i]+a[j]))
    {
        if(col[i]==1) dinic.add_edge(i,j,1) ;
        else dinic.add_edge(j,i,1) ;
    }

    if(dinic.MaxFlow(n+1,n+2)!=n)
        { printf("Impossible\n") ; return 0 ; }

    for(int i=1;i<=n;i++) v0[i].clear() ;
    for(auto i : edge)
        if(i.from<=n && i.to<=n && i.flow==1)
    {
        v0[i.from].push_back(i.to) ;
        v0[i.to].push_back(i.from) ;
    }

    memset(col,0,sizeof(col)) ;
    for(int i=1;i<=n;i++) if(!col[i])
    {
        acnt++ ;
        dfs2(i) ;
    }

    printf("%d\n",acnt) ;
    for(int i=1;i<=acnt;i++)
    {
        printf("%d",ans[i].size()) ;
        for(auto j : ans[i]) printf(" %d",j) ;
        printf("\n") ;
    }
}
