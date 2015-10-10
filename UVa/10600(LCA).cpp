#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10,maxm=10000,INF=1000000000 ;

struct P
{
    int from,to,dis;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

int n ;
vector<P> v[maxn] ;
vector<P> edge ;

int fa[maxn],fa_dis[maxn] ;

bool vis[maxn] ;
int depth[maxn] ;
void dfs(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i].to])
    {
        fa[v[x][i].to]=x ;
        fa_dis[v[x][i].to]=v[x][i].dis ;
        depth[v[x][i].to]=depth[x]+1 ;
        dfs(v[x][i].to) ;
    }
}

int anc[20][maxn],ancmax[20][maxn] ;
void build_LCA(int root)
{
    fa[root]=root ; depth[root]=0 ;
    memset(vis,0,sizeof(vis)) ;
    dfs(root) ;
    for(int i=0;(1<<i)<n;i++) for(int j=1;j<=n;j++) if(depth[j]>=(1<<i))
    {
        if(i==0) anc[0][j]=fa[j] , ancmax[0][j]=fa_dis[j]  ;
        else anc[i][j]=anc[i-1][anc[i-1][j]] , ancmax[i][j]=max(ancmax[i-1][j],ancmax[i-1][anc[i-1][j]]) ;

    }
}

int get_anc(int x,int len)
{
    while(len)
    {
        int i ;
        for(i=20;(1<<i)>len;i--) ;
        x=anc[i][x] ;
        len-=(1<<i) ;
    }
    return x ;
}

int get_max(int x,int len)
{
    int ret=0 ;
    while(len)
    {
        int i ;
        for(i=20;(1<<i)>len;i--) ;
        ret=max(ret,ancmax[i][x]) ;
        len-=(1<<i) ;
    }
    return ret ;
}

int LCA(int x,int y)
{
    int d=depth[x]-depth[y] ;
    if(d>0) return LCA(get_anc(x,d),y) ;
    if(d<0) return LCA(x,get_anc(y,-d)) ;
    if(x==y) return x ;
    int l=0 , r=depth[x] ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(get_anc(x,mid)==get_anc(y,mid)) r=mid ;
        else l=mid ;
    }
    return get_anc(x,r) ;
}

int g[maxn] ;
int getg(int x)
{
    return g[x]==x ? x : g[x]=getg(g[x]) ;
}

bool used[maxm] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int m ; scanf("%d%d",&n,&m) ;
        for(int i=0;i<=n;i++) v[i].clear() , g[i]=i ;
        edge.clear() ;
        for(int i=1;i<=m;i++)
        {
            int x,y,d ; scanf("%d%d%d",&x,&y,&d) ;
            edge.push_back((P){x,y,d}) ;
        }
        sort(edge.begin(),edge.end()) ;
        memset(used,0,sizeof(used)) ;
        int ans1=0 ;
        for(int i=0;i<m;i++)
        {
            int x=edge[i].from , y=edge[i].to , d=edge[i].dis ;
            if(getg(x)==getg(y)) continue ;
            g[getg(x)]=getg(y) ;
            v[x].push_back((P){x,y,d}) ; v[y].push_back((P){y,x,d}) ;
            used[i]=1 ; ans1+=edge[i].dis ;
        }

        build_LCA(1) ;
        int ans2=INF ;
        for(int i=0;i<m;i++) if(!used[i])
        {
            int x=edge[i].from , y=edge[i].to ;
            int lca=LCA(x,y) ;
            int d1=depth[x]-depth[lca] , d2=depth[y]-depth[lca] ;
            int val=max(get_max(x,d1),get_max(y,d2)) ;
            ans2=min(ans2,ans1+edge[i].dis-val) ;
        }
        printf("%d %d\n",ans1,ans2) ;
    }
}
