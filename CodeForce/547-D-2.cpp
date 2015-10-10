#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

struct P{int x,y,id;};
bool cmp1(const P &a,const P &b)
{
    return a.x==b.x ? a.y<b.y : a.x<b.x ;
}
bool cmp2(const P &a,const P &b)
{
    return a.y==b.y ? a.x<b.x : a.y<b.y ;
}

P p[maxn] ;

struct node
{
    node *las,*nex ;
    int id ;
    node(int _id){las=nex=NULL ; id=_id ;}
}*head[3][maxn] , *nd[3][maxn] ;

void add_node(int type,int x,int id)
{
    node *u=head[type][x] ;
    head[type][x]=new node(id) ;
    head[type][x]->nex=u ;
    if(u) u->las=head[type][x] ;
}

void erase(int type,int id,node *u)
{
    if(u==head[type][id]) head[type][id]=u->nex ;
    else
    {
        u->las->nex=u->nex ;
        if(u->nex) u->nex->las=u->las ;
    }
}

bool vis[maxn] ;
int fa[maxn],ans[maxn] ;
void dfs(int x,int f,int type)
{
    vis[x]=1 ; fa[x]=f ;
    int id=(type==1 ? p[x].x : p[x].y) ;
    erase(type,id,nd[type][x]) ;

    for(node *u=head[type][id];u;u=head[type][id])
    {
        if(vis[u->id])
        {
            for(int i=x,col=type^3;;i=fa[i],col^=3)
            {
                ans[i]=col ;
                int id2=(col==1 ? p[i].x : p[i].y) ;
                erase(col,id2,nd[col][i]) ;
                if(i==u->id) break ;
            }
            return ;
        }
        else
        {
            dfs(u->id,x,type^3) ;
            head[type][id]=u->nex ;
            if(ans[x]) return ;
        }
    }
}

vector<int> v[maxn] ;
void build_graph(int n)
{
    sort(p+1,p+n+1,cmp1) ;
    for(int i=1;i<n;i++) if(p[i].x==p[i+1].x)
        v[p[i].id].push_back(p[i+1].id) ,
        v[p[i+1].id].push_back(p[i].id) ;
    sort(p+1,p+n+1,cmp2) ;
    for(int i=1;i<n;i++) if(p[i].y==p[i+1].y)
        v[p[i].id].push_back(p[i+1].id) ,
        v[p[i+1].id].push_back(p[i].id) ;
}

void dfs2(int x,int f=-1,int c=1)
{
    ans[x]=c ;
    for(auto i : v[x]) if(i!=f)
        dfs2(i,x,3-c) ;
}

main()
{
    if(fopen("in","r")) freopen("in","r",stdin) ;

    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y) ;
        p[i].id=i ;
        add_node(1,p[i].x,i) ;
        add_node(2,p[i].y,i) ;
        nd[1][i]=head[1][p[i].x] ;
        nd[2][i]=head[2][p[i].y] ;
    }

    for(int i=1;i<=n;i++) if(!vis[i])
    {
        dfs(i,-1,1) ;
        if(!head[2][p[i].y] || ans[i]) continue ;
        if(!head[2][p[i].y]->nex) continue ;
        dfs(i,-1,2) ;
    }

    int n2=0 ;
    for(int i=1;i<=n;i++) if(!ans[i])
        p[++n2]=p[i] ;
    build_graph(n2) ;

    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!ans[i]) dfs2(i) ;
    for(int i=1;i<=n;i++) printf("%c",ans[i]==1?'b':'r') ;
    printf("\n") ;
}
