#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#define INF 100000000
using namespace std;
struct P {int to,w ;};
vector<P> v0[1001],v[1100001] ;
queue<int> q ;
int cost[1001],d[1100001],c,n ;
bool inq[1100001] ;

int id(int a,int b)
{
    return a*101+b ;
}

void make_graph()
{
    for(int i=0;i<n*101;i++) v[i].clear() ;
    for(int i=0;i<n;i++) for(int j=0;j<v0[i].size();j++)
        for(int k=100;k>=v0[i][j].w;k--)
        {
            int id1=id(i,k),id2=id(v0[i][j].to,k-v0[i][j].w);
            v[id1].push_back((P){id2,0}) ;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<=100;j++)
        {
            int id1=id(i,j) , id2=id(i,j+1) ;
            v[id1].push_back((P){id2,cost[i]}) ;
        }
}

void SSSP(int st,int N)
{
    memset(inq,0,sizeof(inq)) ;
    while(!q.empty()) q.pop() ;
    for(int i=0;i<N;i++) d[i]=INF ;
    d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
        {
            int nu=v[u][i].to  , nw=v[u][i].w ;
            if(d[u]+nw<d[nu] && (nu%101 <= c))
            {
                d[nu]=d[u]+nw ;
                if(!inq[nu]) q.push(nu) ;
                inq[nu]=1 ;
            }
        }
    }
}

main()
{
    int m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) v0[i].clear() ;
        for(int i=0;i<n;i++) scanf("%d",&cost[i]) ;
        while(m--)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w) ;
            v0[a].push_back((P){b,w}) ;
            v0[b].push_back((P){a,w}) ;
        }

        int Q;
        scanf("%d",&Q) ;
        make_graph() ;
        while(Q--)
        {
            int st,ed ;
            scanf("%d%d%d",&c,&st,&ed) ;
            SSSP(id(st,0),n*101) ;
            if(d[id(ed,0)]==INF) printf("impossible\n") ;
            else printf("%d\n",d[id(ed,0)] ) ;
        }
    }
}
