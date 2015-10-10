#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=200 ;
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
        int m=edge.size() ;
        v[from].push_back(m-2) ;
        v[to].push_back(m-1) ;
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
}di;

string st[]={"XXL","XL","L","M","S","XS"} ;
int num[16] ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        edge.clear() ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        memset(num,0,sizeof(num)) ;
        for(int z=0;z<m;z++)
        {
            string s,t ;
            cin >> s >> t ;
            int cnt=0 ;
            for(int i=0;i<6;i++) for(int j=i+1;j<6;j++,cnt++)
                if((s==st[i]&&t==st[j])||(t==st[i]&&s==st[j]))
                    num[cnt]++ ;
        }
        int cnt=0 ;
        for(int i=0;i<6;i++) di.add_edge(i,21,n/6) ;
        for(int i=0;i<6;i++) for(int j=i+1;j<6;j++,cnt++)
            di.add_edge(cnt+6,i,INF) ,
            di.add_edge(cnt+6,j,INF) ,
            di.add_edge(22,cnt+6,num[cnt]) ;
        if(di.MaxFlow(22,21)==m) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
