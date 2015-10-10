#include<bits/stdc++.h>
#define INF 100000000
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
#define pii pair<int,int>
using namespace std;
const int maxn=10000 ;
struct P{int from,to,flow,cap;};
vector<int> v[maxn] ;
vector<P> edge ;

int prime[40000],pcnt ;
bool vis[40000] ;
void make_prime(int x)
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<x;i++) if(!vis[i])
        for(int j=i*i;j<x;j+=i) vis[j]=1 ;
    pcnt=0 ;
    for(int i=2;i<x;i++) if(!vis[i]) prime[++pcnt]=i ;
}

void add_edge(int from,int to,int cap)
{
    edge.push_back((P){from,to,0,cap}) ;
    edge.push_back((P){to,from,0,0}) ;
    int m=edge.size() ;
    v[from].push_back(m-2) ;
    v[to].push_back(m-1) ;
}

int a[maxn],fa[maxn] ;
int max_flow(int st,int ed)
{
    int flow=0 ;
    while(1)
    {
        memset(a,0,sizeof(a)) ;
        a[st]=INF ;
        queue<int> q ; q.push(st) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<v[u].size();i++)
            {
                P &e=edge[v[u][i]] ;
                if(e.flow<e.cap && !a[e.to])
                {
                    a[e.to]=min(a[u],e.cap-e.flow) ;
                    fa[e.to]=v[u][i] ;
                    q.push(e.to) ;
                }
            }
            if(a[ed]) break ;
        }
        if(!a[ed]) break ;
        flow+=a[ed] ;
        for(int i=ed;i!=st;i=edge[fa[i]].from)
        {
            edge[fa[i]].flow += a[ed] ;
            edge[fa[i]^1].flow -= a[ed] ;
        }
    }
    return flow ;
}

int p[maxn] ;
bool adj[101][101] ;
map<int,pii> mp[101] ;
main()
{
    make_prime(40000) ;
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        adj[x][y]=adj[y][x]=1 ;
    }
    int st=maxn-2 , ed=maxn-1 ;
    int cnt=0 ; /// point number
    for(int i=1;i<=n;i++)
    {
        int tmp=p[i] , j ;
        for(j=1;j<=pcnt && tmp!=1;j++) if(tmp%prime[j]==0)
        {
            int num=0 ;
            while(tmp%prime[j]==0) num++ , tmp/=prime[j] ;
            mp[i][prime[j]]=MKP(cnt,num) ;
            if(i%2) add_edge(st,cnt,num) ;
            else add_edge(cnt,ed,num) ;
            cnt++ ;
        }
        if(tmp!=1)
        {
            mp[i][tmp]=MKP(cnt,1) ;
            if(i%2) add_edge(st,cnt,1) ;
            else add_edge(cnt,ed,1) ;
            cnt++ ;
        }
    }
    for(int i=1;i<=n;i+=2) for(int j=2;j<=n;j+=2) if(adj[i][j])
    {
        for(map<int,pii>::iterator it=mp[i].begin();it!=mp[i].end();it++)
        if(mp[j].count(it->F))
        {
            map<int,pii>::iterator it2=mp[j].find(it->F) ;
            add_edge(it->S.F,it2->S.F,min(it->S.S,it2->S.S)) ;
        }
    }

    printf("%d\n",max_flow(st,ed)) ;
}
