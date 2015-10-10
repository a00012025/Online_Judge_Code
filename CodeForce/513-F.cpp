#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
using namespace std;
const int maxn=2000 ;

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
}dinic;

struct Scay
{
    int x,y,t ;
    void scan(){scanf("%d%d%d",&x,&y,&t); x-- ; y-- ;}
}a[maxn],b[maxn];

char G[25][25] ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n,m ;
void BFS(int st,int *d)
{
    fill(d,d+n*m,INF) ;
    queue<int> q ; q.push(st) ; d[st]=0 ;
    while(!q.empty())
    {
        int u=q.front() , x=u/m , y=u%m ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(G[nx][ny]=='#'||d[nx*m+ny]!=INF) continue ;
            d[nx*m+ny]=d[u]+1 ; q.push(nx*m+ny) ;
        }
    }
}

struct Q
{
    int x,y ; LL val ;
    bool operator < (const Q &rhs) const
    {
        return val<rhs.val ;
    }
};
vector<Q> E ;

int d[maxn][maxn] ;
int gx[maxn],gy[maxn] ;
main()
{
    int p,q ; scanf("%d%d%d%d",&n,&m,&p,&q) ;
    if(p!=q+1 && q!=p+1){printf("-1\n") ; return 0 ;}
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int k=max(p,q) ;
    for(int i=1;i<=k;i++) a[i].scan() ;
    for(int i=1;i<=k;i++) b[i].scan() ;
    if(p>q) swap(a[1],b[1]) ;

    int num=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]=='.')
        num++ , gx[num]=i , gy[num]=j , BFS(i*m+j,d[i*m+j]) ;

    int source=2*k+2*num+1 , sink=2*k+2*num+2 ;
    for(int i=1;i<=num;i++) E.push_back((Q){k+i,k+num+i,-1}) ;
    for(int i=1;i<=k;i++)
        E.push_back((Q){source,i,-1}) , E.push_back((Q){k+2*num+i,sink,-1}) ;

    for(int i=1;i<=k;i++) for(int j=1;j<=num;j++)
    {
        int x=m*a[i].x+a[i].y , y=m*gx[j]+gy[j] ;
        if(d[x][y]!=INF) E.push_back((Q){i,k+j,(LL)d[x][y]*a[i].t}) ;
        x=m*b[i].x+b[i].y ;
        if(d[x][y]!=INF) E.push_back((Q){k+num+j,k+2*num+i,(LL)d[x][y]*b[i].t}) ;
    }

    sort(E.begin(),E.end()) ;
    int l=num+2*k-2 , r=E.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        dinic.init(2*k+2*num+2) ;
        for(int i=0;i<=mid;i++) dinic.add_edge(E[i].x,E[i].y,1) ;
        if(dinic.MaxFlow(source,sink)==k) r=mid ;
        else l=mid ;
    }
    printf("%I64d\n",r==E.size()?-1:E[r].val) ;
}
