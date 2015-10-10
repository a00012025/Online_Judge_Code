#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
#define INF 100000000
using namespace std;
const int maxn=20000+100 ;
struct P{int from,to,flow,cap;};
vector<P> edge ;
vector<int> v[maxn] ;

int n,m ;
struct Dinic
{
    int st,ed ;

    void init(int num)
    {
        for(int i=0;i<edge.size();i++)
            edge[i].flow = 0 ;
        for(int i=0;i<n;i++) edge[2*i].cap=num ;
    }

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
            memset(cur,0,sizeof(cur)) ;
            Flow+=DFS(st,INF) ;
        }
        return Flow ;
    }
}dinic ;

int Mflow ;
bool check(int num)
{
    dinic.init(num) ;
    if(dinic.MaxFlow(n+m+1,n+m+2)==Mflow) return 1 ;
    else return 0 ;
}

map<pii,int> mp ;
pii p[maxn],p2[maxn] ;
main()
{
    scanf("%d%d",&n,&m) ;
    int m0 ; m0=Mflow=m ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        p[i]=mkp(x,y) ;
        if(x>y) swap(x,y) ;
        mp[mkp(x,y)]++ ;
    }
    m=mp.size() ;

    for(int i=1;i<=n;i++) dinic.add_edge(n+m+1,i,0) ;

    int cnt=0 ;
    for(auto i : mp)
    {
        cnt++ ;
        dinic.add_edge(i.F.F,n+cnt,i.S) ;
        dinic.add_edge(i.F.S,n+cnt,i.S) ;
        dinic.add_edge(n+cnt,n+m+2,i.S) ;
        p2[n+cnt]=i.F ;
    }

    int l=0 , r=Mflow+1 ;
    while(r-l>1)
    {
        int mid=(l+r)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    check(r) ;
    printf("%d\n",r) ;

    mp.clear() ;
    for(auto i : edge)
        if(i.from<=m+n && i.to<=m+n && i.cap)
    {
        if(i.from == p2[i.to].F)
            mp[p2[i.to]]=i.flow ;
    }

    for(int i=1;i<=m0;i++)
    {
        if(p[i].F < p[i].S)
        {
            auto it=mp.find(p[i]) ;
            if(it->S)
            {
                printf("1\n") ;
                it->S-- ;
            }
            else printf("0\n") ;
        }
        else
        {
            auto it=mp.find(mkp(p[i].S,p[i].F)) ;
            if(it->S)
            {
                printf("0\n") ;
                it->S-- ;
            }
            else printf("1\n") ;
        }
    }
}
