#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii ;
const int INF=10000000 ;
struct P{int from,to,cap,flow;};
vector<P> edge ;
vector<int> G[5001] ;
vector<pii> ans[200],ans2[200] ;
int a[5001],fa[5001] ;
int cut[1000],l[1000],r[1000],v[1000],num[1000] ;

void init()
{
    edge.clear() ;
    for(int i=0;i<=3000;i++) G[i].clear() ;
}

void add_edge(int from,int to,int cap)
{
        //printf("add %5d -> %5d : %5d\n",from,to,cap) ;
    if(!cap) return ;
    edge.push_back((P){from,to,cap,0}) ;
    edge.push_back((P){to,from,0,0}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
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
        scanf("%d",&k) ;
        init() ;
        cut[1]=0 ; cut[2*n+2]=50001 ;
        int sum=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&v[i],&l[i],&r[i]) ;
            cut[2*i] = l[i] ;
            cut[2*i+1] = r[i] ;
            sum += v[i] ;
        }
        sort(cut+1,cut+2*n+2) ;
        for(int i=1;i<=n;i++)
        {
            int j;
            for(j=1;cut[j]!=l[i];j++) ;
            for(;cut[j]<r[i];j++) add_edge(1000+i,j,cut[j+1]-cut[j]) ;
            add_edge(0,1000+i,v[i]) ;
        }
        for(int i=1;i<=2*n+1;i++) add_edge(i,3000,k*(cut[i+1]-cut[i])) ;
        if(max_flow(0,3000)<sum) {printf("Case %d: No\n",++tc) ; continue ; }
        printf("Case %d: Yes\n",++tc) ;

        for(int i=1;i<2*n+2;i++) num[i]=cut[i] ;
        for(int i=1;i<=n;i++) {ans[i].clear() ; ans2[i].clear() ;}

        for(int i=1;i<=n;i++)
        {
                //for(int i=1;i<=2*n+1;i++) printf("%d,",num[i]);
                //printf("\n");
            for(int j=0;j<G[1000+i].size();j++)
            {
                P e=edge[G[1000+i][j]] ; int fl=e.flow ;
                if(!fl || e.to==0) continue ;
                    //printf("%5d->%5d : %5d\n",e.from,e.to,e.flow) ;
                if(num[e.to]+fl <= cut[e.to+1])
                {
                    ans[i].push_back(make_pair(num[e.to],num[e.to]+fl)) ;
                    num[e.to] += fl ;
                    if(num[e.to] == cut[e.to+1]) num[e.to]=cut[e.to] ;
                }
                else
                {
                    ans[i].push_back(make_pair(cut[e.to],fl+num[e.to]-cut[e.to+1]+cut[e.to])) ;
                    ans[i].push_back(make_pair(num[e.to],cut[e.to+1])) ;
                    num[e.to]=fl+num[e.to]-cut[e.to+1]+cut[e.to] ;
                    if(num[e.to] == cut[e.to+1]) num[e.to]=cut[e.to] ;
                }
            }
            for(int j=0;j<ans[i].size();j++)
            {
                int sz=ans2[i].size() ;
                if(j==0 || ans[i][j].first!=ans2[i][sz-1].second)
                    ans2[i].push_back(ans[i][j]) ;
                else ans2[i][sz-1].second=ans[i][j].second ;
            }
            printf("%d",ans2[i].size()) ;
            for(int j=0;j<ans2[i].size();j++) printf(" (%d,%d)",ans2[i][j].first,ans2[i][j].second);
            printf("\n") ;
        }
    }
}
