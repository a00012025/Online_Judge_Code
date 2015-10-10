#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=1000000,maxl=60000,maxn=100 ;
struct P {int from,to,cap,flow;};
vector<P> edge ;
vector<int> G[61000],ans[110],ans2[110] ;
int a[61000],fa[61000] ;

void add_edge(int from,int to,int cap)
{
    edge.push_back((P){from,to,cap,0}) ;
    edge.push_back((P){to,from,0,0}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

void init(int k)
{
    edge.clear() ;
    for(int i=1;i<=100;i++) {ans[i].clear() ; ans2[i].clear() ;}
    for(int i=0;i<=60001;i++) G[i].clear() ;
    for(int i=0;i<=50000;i++) add_edge(i,60001,k) ;
}

int max_flow(int st,int ed)
{
    int ret=0 ;
    while(1)
    {
        queue<int> q ;
        memset(a,0,sizeof(a)) ;
        a[st]=INF ; q.push(st) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<G[u].size();i++)
            {
                P e=edge[G[u][i]] ;
                if(!a[e.to] && e.cap>e.flow)
                {
                    a[e.to]=min(a[u],e.cap-e.flow) ;
                    fa[e.to]=G[u][i] ;
                    q.push(e.to) ;
                }
            }
            if(a[ed]) break ;
        }
        if(!a[ed]) break ;
        ret += a[ed] ;
        for(int j=ed;j!=st;j=edge[fa[j]].from)
        {
            edge[fa[j]].flow += a[ed] ;
            edge[fa[j]^1].flow -= a[ed] ;
        }
    }
    return ret ;
}

main()
{
    int n,k,tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        int sum=0,cnt=50000 ;
        scanf("%d",&k) ;
        init(k) ;
        for(int j=1;j<=n;j++)
        {
            int v,a,b ;
            scanf("%d%d%d",&v,&a,&b) ;
            cnt++ ;
            for(int i=a;i<b;i++) add_edge(cnt,i,1) ;
            add_edge(60000,cnt,v) ;
            sum+=v ;
        }
        if(max_flow(60000,60001)<sum)
            {printf("Case %d: No\n",++tc) ; continue ;}
            //for(int i=0;i<n;i++) printf("%d,",edge[G[60000][i]].flow) ;
            //printf("\n") ;
        printf("Case %d: Yes\n",++tc) ;
        for(int i=0;i<edge.size();i++)
            if(edge[i].to<=50000 && edge[i].to>=0 && edge[i].flow)
                ans[edge[i].from-50000].push_back(edge[i].to) ;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                if(j==0 || ans2[i][ans2[i].size()-1] != ans[i][j])
                {
                    ans2[i].push_back(ans[i][j]) ;
                    ans2[i].push_back(ans[i][j]+1) ;
                }
                else ans2[i][ans2[i].size()-1]++ ;
            }
            printf("%d",ans2[i].size()/2) ;
            for(int j=0;j<ans2[i].size();j+=2)
                printf(" (%d,%d)",ans2[i][j],ans2[i][j+1]);
            printf("\n") ;
        }
    }
}
