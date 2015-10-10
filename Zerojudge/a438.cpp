#include<bits/stdc++.h>
using namespace std;
const int maxn=32000+5 , maxm=514000+5 , INF=100000000 ;
struct P{int from,to,id;};
int n,m,bcnt ;
vector<int> v[maxn],v2[maxn] ;
vector<P> edge ;
int lev[maxn],low[maxn],bcc[maxn] ;
bool vis[maxn] ;
stack<int> st ;

void dfs(int x,int l)
{
    //printf("%d\n",x) ;
    lev[x]=l ; low[x]=l ; vis[x]=1 ;
    for(int i=0;i<v[x].size();i++)
    {
        P e=edge[v[x][i]] ;
        if(lev[e.to]==lev[x]-1) continue ;
        if(vis[e.to]) low[x]=min(low[x],lev[e.to]) ;
        else
        {
            st.push(e.to) ;
            dfs(e.to,l+1) ;
            low[x]=min(low[x],low[e.to]) ;
            if(low[e.to]>l)
            {
                bcnt++ ;
                int top ;
                do
                {
                    top=st.top() ; st.pop() ;
                    bcc[top]=bcnt ;
                }while(top!=e.to) ;
            }
        }
    }
}

void find_edge_bcc()
{
    bcnt=0 ;
    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) lev[i]=INF ;
    while(!st.empty()) st.pop() ;
    memset(bcc,0,sizeof(bcc)) ;
    dfs(1,0) ;
}

void find_new_edge()
{
    for(int i=0;i<=bcnt;i++) v2[i].clear() ;
    for(int i=0;i<edge.size();i++)
    {
        P e=edge[i] ;
        if(bcc[e.to]!=bcc[e.from])
        {
            v2[bcc[e.to]].push_back(bcc[e.from]) ;
            v2[bcc[e.from]].push_back(bcc[e.to]) ;
        }
    }
    for(int i=0;i<=bcnt;i++)
    {
        sort(v2[i].begin(),v2[i].end()) ;
        v2[i].resize(unique(v2[i].begin(),v2[i].end())-v2[i].begin()) ;
    }
}

int Time,fa[maxn],in[maxn],out[maxn] ;
void dfs2(int x)
{
    vis[x]=1 ;
    in[x]=Time++ ;
    for(int i=0;i<v2[x].size();i++) if(!vis[v2[x][i]])
        {fa[v2[x][i]]=x ; dfs2(v2[x][i]) ;}
    out[x]=Time++ ;
}

void find_new_in_out()
{
    Time=0 ;
    memset(vis,0,sizeof(vis)) ;
    fa[0]=0 ;
    for(int i=0;i<=bcnt;i++) if(!vis[i]) dfs2(i) ;
}

bool can_reach(int id,int x,int y)
{
    id=2*id-2 ; //printf("%d,%d,%d,%d\n",edge[id].from,edge[id].to,bcc[edge[id].from],bcc[edge[id].to]) ;
    if(bcc[edge[id].from]==bcc[edge[id].to]) return 1 ;
    int cut1=bcc[edge[id].from] , cut2=bcc[edge[id].to] ;
    if(fa[cut1]!=cut2) swap(cut1,cut2) ;
    x=bcc[x] ; y=bcc[y] ;
    if(in[x]>=in[cut1] && out[x]<=out[cut1] && (!( in[y]>=in[cut1] && out[y]<=out[cut1] ))) return 0 ;
    if(in[y]>=in[cut1] && out[y]<=out[cut1] && (!( in[x]>=in[cut1] && out[x]<=out[cut1] ))) return 0 ;
    return 1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        edge.clear() ;
        for(int i=1;i<=m;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            edge.push_back((P){x,y}) ; edge.push_back((P){y,x}) ;
            int sz=edge.size() ;
            v[x].push_back(sz-2) ; v[y].push_back(sz-1) ;
        }
        find_edge_bcc() ;
        //for(int i=1;i<=n;i++) printf("%d,",bcc[i]) ; printf("\n") ;
        find_new_edge() ;
        find_new_in_out() ;
        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            int id,x,y ;
            scanf("%d%d%d",&id,&x,&y) ;
            if(!can_reach(id,x,y)) printf("Y") ;
            else printf("N") ;
        }
        printf("\n") ;
    }
}
