#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=10000000 ;
struct P {int from,to,cap,flow;};
vector<P> edge ;
vector<int> G[100] ;
int a[100],fa[100] ;

void add_edge(int from,int to,int cap)
{
    edge.push_back((P){from,to,cap,0}) ;
    edge.push_back((P){to,from,0,0}) ;
    int m=edge.size() ;
    G[from].push_back(m-2) ;
    G[to].push_back(m-1) ;
}

void max_flow(int st,int ed)
{
    while(1)
    {
        queue<int> q ;
        memset(a,0,sizeof(a)) ; a[st]=INF ;
        q.push(st) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            for(int i=0;i<G[u].size();i++)
            {
                P e=edge[G[u][i]] ;
                if(!a[e.to] && e.flow<e.cap)
                {
                    a[e.to]=min(a[u],e.cap-e.flow) ;
                    fa[e.to]=G[u][i] ;
                    q.push(e.to) ;
                }
            }
            if(a[ed]) break ;
        }
        if(!a[ed]) break ;
        for(int j=ed;j!=st;j=edge[fa[j]].from)
        {
            edge[fa[j]].flow += a[ed] ;
            edge[fa[j]^1].flow -= a[ed] ;
        }
    }
}

void init()
{
    edge.clear() ;
    for(int i=0;i<100;i++) G[i].clear() ;
    for(int i=0;i<10;i++) add_edge(i+27,37,1) ;
}

main()
{
    char s[100],ans[10] ;
    while(gets(s))
    {
        init() ;
        while(1)
        {
            if(s[0]<'A' || s[0]>'Z') break ;
            add_edge(0,s[0]-'A'+1,s[1]-'0') ;
            for(int i=3;s[i]!=';';i++) add_edge(s[0]-'A'+1,s[i]-'0'+27,1) ;
            if(!gets(s)) break ;
        }
        max_flow(0,37) ; bool done=0 ;
        for(int i=0;i<edge.size();i++) if(edge[i].from==0 && edge[i].cap!=edge[i].flow)
        {
            printf("!\n") ; done=1 ; break ;
        }
        if(done) continue ;
        for(int i=0;i<10;i++) ans[i]='_' ;
        for(int i=0;i<edge.size();i++) if(edge[i].from>=1 && edge[i].from<=26 && edge[i].flow)
            ans[edge[i].to-27]=edge[i].from-1+'A' ;
        for(int i=0;i<10;i++) printf("%c",ans[i]) ;
        printf("\n") ;
    }
}
