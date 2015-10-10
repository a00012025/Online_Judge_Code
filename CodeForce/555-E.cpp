#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10,LOG=int(log2(maxn)+1) ;

struct P{int x,y;};
vector<P> E ;
bool vise[maxn] ;

vector<int> v[maxn],v2[maxn] ;
int lev[maxn] ;
int bcc[maxn],bcnt ;
stack<int> st ;
int dfs(int x,int l)
{
    st.push(x) ;
    int low ; lev[x]=low=l ;
    for(auto e : v[x]) if(!vise[e])
    {
        vise[e]=1 ;
        int i=(E[e].x==x ? E[e].y : E[e].x) ;
        if(lev[i]!=-1){low=min(low,lev[i]) ; continue ;}
        int tmp=dfs(i,l+1) ; low=min(low,tmp) ;
        if(tmp>l)
        {
            bcnt++ ;
            while(1)
            {
                int t=st.top() ; st.pop() ;
                bcc[t]=bcnt ;
                if(t==i) break ;
            }
        }
    }
    return low ;
}

int col[maxn],fa[maxn],dep[maxn] ;
int anc[maxn][LOG] ;
void dfs2(int x,int f,int d)
{
    fa[x]=x ; anc[x][0]=f ; dep[x]=d ;
    for(int i=1;i<LOG;i++) anc[x][i]=anc[anc[x][i-1]][i-1] ;
    for(auto i : v2[x]) if(i!=f)
        dfs2(i,x,d+1) ;
}

int getfa(int x)
{
    if(fa[x]==x) return x ;
    int tmp=getfa(fa[x]) ;
    return col[tmp]==-1 || col[tmp]==col[x] ? fa[x]=tmp : fa[x] ;
}

bool mark(int x,int y,int c)
{
    while(dep[x]>dep[y])
    {
        if(col[x]==-1) col[x]=c , fa[x]=y , x=anc[x][0] ;
        else if(col[x]!=c) return 0 ;
        else x=getfa(x) ;
    }
    return 1 ;
}

int getfa(int x,int d)
{
    for(int i=0;i<LOG && d;i++) if(d&(1<<i))
        x=anc[x][i] , d^=1<<i ;
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]>dep[y]) return LCA(getfa(x,dep[x]-dep[y]),y) ;
    if(dep[x]<dep[y]) return LCA(x,getfa(y,dep[y]-dep[x])) ;
    if(x==y) return x ;
    for(int i=LOG-1;i>=0;i--) if(anc[x][i]!=anc[y][i])
        x=anc[x][i] , y=anc[y][i] ;
    return anc[x][0] ;
}

main()
{
    int n,m,Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=0;i<m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        E.push_back((P){x,y}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    memset(lev,-1,sizeof(lev)) ;
    for(int i=1;i<=n;i++) if(!bcc[i])
    {
        dfs(i,0) ;
        bcnt++ ;
        while(!st.empty())
            bcc[st.top()]=bcnt , st.pop() ;
    }
    for(auto i : E) if(bcc[i.x]!=bcc[i.y])
        v2[bcc[i.x]].push_back(bcc[i.y]) ,
        v2[bcc[i.y]].push_back(bcc[i.x]) ;

    for(int i=1;i<=bcnt;i++) if(!anc[i][0])
        dfs2(i,i,0) ;

    memset(col,-1,sizeof(col)) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        x=bcc[x] ; y=bcc[y] ;
        if(x==y) continue ;
        int lca=LCA(x,y) ;
        if(!mark(x,lca,1) || !mark(y,lca,2))
            {printf("No\n") ; return 0 ;}
    }
    printf("Yes\n") ;
}
