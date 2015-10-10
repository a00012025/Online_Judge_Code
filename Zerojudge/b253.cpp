#include<bits/stdc++.h>
#define MS0(x) memset((x),0,sizeof(x))
#define MS1(x) memset((x),-1,sizeof(x))
using namespace std;
struct P{int from,to,flow,cap,cost;};
vector<int> v[60],G[60],v2[60] ;
vector<P> edge ;
int n,m,in[60],out[60] ;
int a[60],d[60],fa[60] ;

int odd_num()
{
    int num=0 ;
    for(int i=1;i<=n;i++) if((in[i]+out[i])%2) num++ ;
    return num ;
}

void add_edge(int from,int to,int cap,int cost)
{
    edge.push_back((P){from,to,0,cap,cost}) ;
    edge.push_back((P){to,from,0,0,-cost}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

bool inq[60] ;
const int INF=10000000 ;
void MCMF(int st,int ed,int &flow,int &cost)
{
    flow=cost=0 ;
    while(1)
    {
        for(int i=0;i<60;i++) a[i]=0 , d[i]=INF , inq[i]=0 ;
        a[st]=INF ; d[st]=0 ;
        queue<int> q ; q.push(st) ; inq[st]=1 ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ; inq[u]=0 ;
            for(int i=0;i<G[u].size();i++)
            {
                P e=edge[G[u][i]] ;
                if(d[e.to]>d[u]+e.cost && e.flow<e.cap)
                {
                    d[e.to]=d[u]+e.cost ;
                    a[e.to]=min(a[u],e.cap-e.flow) ;
                    fa[e.to]=G[u][i] ;
                    if(!inq[e.to]) q.push(e.to) ; inq[e.to]=1 ;
                }
            }
        }
        if(d[ed]==INF) break ;
        flow+=a[ed] ; cost+=a[ed]*d[ed] ;
        for(int j=ed;j!=st;j=edge[fa[j]].from)
        {
            edge[fa[j]].flow +=a[ed] ;
            edge[fa[j]^1].flow -=a[ed] ;
        }
    }
    return ;
}

bool vis[60] ;

void dfs(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        dfs(v2[x][i]) ;
}

bool connected()
{
    memset(vis,0,sizeof(vis)) ;
    int cnt=0,zero=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        if(v2[i].size()==0) {zero++ ; continue ;}
        dfs(i) ;
        cnt++ ;
    }
    return (zero==n || cnt==1) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<=n+1;i++) v[i].clear() , v2[i].clear() , G[i].clear() ;
        edge.clear() ; MS0(in) ; MS0(out) ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v2[x].push_back(y) ; v2[y].push_back(x) ;
            out[x]++ ; in[y]++ ;
        }
        if(!connected()) {printf("NO\n") ; continue ;}
        int num=odd_num() ;
        if(num>2) {printf("NO\n") ; continue ;}
        for(int i=1;i<=n;i++) for(int j=0;j<v[i].size();j++)
            add_edge(i,v[i][j],1,1) ;
        int st=0 , ed=n+1 ;

        for(int i=1;i<=n;i++) if(out[i]!=in[i])
        {
            if((out[i]+in[i])%2==0 && out[i]<in[i])
                add_edge(i,ed,(in[i]-out[i])/2,0) ;
            else if((out[i]+in[i])%2==0)
                add_edge(st,i,(out[i]-in[i])/2,0) ;
        }

        bool ok= (num==0) ;
        int x0=-1,y0=-1,ans=INF,flow,cost ;
        if(!ok) for(int i=1;i<=n;i++) if((in[i]+out[i])%2)
            {y0=i ; if(x0==-1) x0=i ;}
        int need1,need2 ;
        if(!ok)
        {
            need1=(in[x0]+1-out[x0])/2 , need2=(in[y0]-1-out[y0])/2 ;
            if(need1>0) add_edge(x0,ed,need1,0) ;
            else if(need1<0) add_edge(st,x0,-need1,0) ;
            if(need2>0) add_edge(y0,ed,need2,0) ;
            else if(need2<0) add_edge(st,y0,-need2,0) ;
        }
        MCMF(st,ed,flow,cost) ;
        ans=min(ans,cost) ;
        if(!ok)
        {
            for(int i=0;i<edge.size();i++) edge[i].flow=0 ;
            if(need1)
            {
                edge.resize(edge.size()-2) ;
                G[x0].resize(G[x0].size()-1) ;
                if(need1>0) G[ed].resize(G[ed].size()-1) ;
                else G[st].resize(G[st].size()-1) ;
            }
            if(need2)
            {
                edge.resize(edge.size()-2) ;
                G[y0].resize(G[y0].size()-1) ;
                if(need2>0) G[ed].resize(G[ed].size()-1) ;
                else G[st].resize(G[st].size()-1) ;
            }
            need1=(in[x0]-1-out[x0])/2 , need2=(in[y0]+1-out[y0])/2 ;
            if(need1>0) add_edge(x0,ed,need1,0) ;
            else if(need1<0) add_edge(st,x0,-need1,0) ;
            if(need2>0) add_edge(y0,ed,need2,0) ;
            else if(need2<0) add_edge(st,y0,-need2,0) ;
            MCMF(st,ed,flow,cost) ;
            ans=min(ans,cost) ;
        }
        printf("YES %d\n",ans) ;
    }
}
