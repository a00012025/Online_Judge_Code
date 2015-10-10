#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#define INF 100000000
using namespace std;
struct P {int from,to,cap,flow;};
vector<P> edge ;
vector<int> G[101] ;
int n,d[101],fa[101];

void init()
{
    edge.clear() ;
    for(int i=0;i<=n;i++) G[i].clear() ;
}

void add_edge(int x,int y,int cap)
{
    edge.push_back((P){x,y,cap,0}) ;
    edge.push_back((P){y,x,cap,0}) ;
    int sz=edge.size() ;
    G[x].push_back(sz-2) ;
    G[y].push_back(sz-1) ;
}

int max_flow(int st,int ed)
{
    int ans=0 ;
    while(1)
    {
        memset(d,0,sizeof(d)) ;
        d[st]=INF ;
        queue<int> q ;
        q.push(st) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<G[u].size();i++)
            {
                P e=edge[G[u][i]] ;
                if(!d[e.to] && e.cap>e.flow)
                {
                    d[e.to]=min(d[u],e.cap-e.flow) ;
                    fa[e.to]=G[u][i] ;
                    q.push(e.to) ;
                }
            }
            if(d[ed]) break ;
        }
        if(!d[ed]) break ;
        for(int j=ed;j!=st;j=edge[fa[j]].from)
        {
            edge[fa[j]].flow += d[ed] ;
            edge[fa[j]^1].flow -= d[ed] ;
        }
        ans += d[ed] ;
    }
    return ans ;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        init() ;
        int st,ed,m ;
        scanf("%d%d%d",&st,&ed,&m) ;
        while(m--)
        {
            int a,b,cap ;
            scanf("%d%d%d",&a,&b,&cap) ;
            add_edge(a,b,cap) ;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",++tc,max_flow(st,ed)) ;
    }
}
