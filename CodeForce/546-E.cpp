#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=200+10 ;

struct P{int from,to,flow,cap;};
struct Dinic
{
    vector<P> edge ;
    vector<int> v[maxn] ;
    int n,st,ed ;

    void init(int Max)
    {
        n=Max ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        edge.clear() ;
    }

    void add_edge(int from,int to,int cap)
    {
        edge.push_back((P){from,to,0,cap}) ;
        edge.push_back((P){to,from,0,0}) ;
        int m=edge.size() ;
        v[from].push_back(m-2) ;
        v[to].push_back(m-1) ;
    }

    bool vis[maxn] ;
    int d[maxn] ;
    bool BFS()
    {
        fill(vis,vis+n+1,0) ;
        queue<int> q ;
        d[st]=0 ; q.push(st) ; vis[st]=1 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(auto i:v[u])
            {
                P &e=edge[i] ;
                if(!vis[e.to] && e.cap>e.flow)
                {
                    vis[e.to]=1 ;
                    d[e.to]=d[u]+1 ;
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
        int Flow=0 , f ;
        for(int &i=cur[x];i<v[x].size();i++)
        {
            P &e=edge[v[x][i]] ;
            if(d[e.to]==d[x]+1 && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                Flow+=f ;
                e.flow+=f ;
                edge[v[x][i]^1].flow-=f ;
                a-=f ;
                if(a==0) break ;
            }
        }
        return Flow ;
    }

    int MaxFlow(int st,int ed)
    {
        this->st = st ;
        this->ed = ed ;
        int Flow=0 ;
        while(BFS())
        {
            fill(cur,cur+n+1,0) ;
            Flow+=DFS(st,INF) ;
        }
        return Flow ;
    }
}din;

bool G[maxn][maxn] ;
int a[maxn],b[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    int s1=0 , s2=0 ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , s1+=a[i] ;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]) , s2+=b[i] ;
    if(s1!=s2){printf("NO\n") ; return 0 ;}

    din.init(2*n+2) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        G[x][y]=G[y][x]=1 ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        int cap=(i==j || G[i][j] ? INF : 0) ;
        din.add_edge(i,n+j,cap) ;
    }
    for(int i=1;i<=n;i++)
        din.add_edge(0,i,a[i]) ,
        din.add_edge(n+i,2*n+1,b[i]) ;
    if(din.MaxFlow(0,2*n+1)!=s1){printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
    for(int i=1,cnt=0;i<=n;i++) for(int j=1;j<=n;j++,cnt+=2)
        printf("%d%c",din.edge[cnt].flow,j==n?'\n':' ') ;
}
