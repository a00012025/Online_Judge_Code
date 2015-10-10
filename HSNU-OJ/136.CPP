#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,maxm=5001 ;
struct P{int x,y,anc,val;}a[maxm] ;
int vis[maxn] ;
int n,m,fa[maxn],dep[maxn] ;
vector<int> v[maxn] ;

int tim=0,in[maxn],out[maxn] ;
void dfs(int x,int col)
{
    vis[x]=col ; in[x]=++tim ;
    for(int i=0;i<v[x].size();i++) if(vis[v[x][i]]==-1)
        fa[v[x][i]]=x , dep[v[x][i]]=dep[x]+1 , dfs(v[x][i],1-col) ;
    out[x]=++tim ;
}

inline bool is_fa(int x,int y) /// x is y's fa
{
    return in[x]<=in[y] && out[x]>=out[y] ;
}

vector<int> path[maxn] ;
int LCA(int x,int y,int id)
{
    while(dep[x]>dep[y]) path[x].push_back(id) , x=fa[x] ;
    while(dep[x]<dep[y]) path[y].push_back(id) , y=fa[y] ;
    while(x!=y)
    {
        path[x].push_back(id) , x=fa[x] ;
        path[y].push_back(id) , y=fa[y] ;
    }
    path[x].push_back(id) ;
    return x ;
}

struct Q{int id,bit;};
vector<Q> pthid[maxn] ;
int ans[11][maxn],d[1500] ;

int dp2(int x,int S)
{
    if(S==0) return 0 ;
    if(d[S]!=-1) return d[S] ;
    int &ret=d[S] ; ret=0 ;
    for(int i=0;i<v[x].size();i++) if(S&(1<<i))
        ret+=ans[10][v[x][i]] ;
    for(int i=0;i<pthid[x].size();i++)
        if( (pthid[x][i].bit&S)==pthid[x][i].bit  )
            ret=max(ret,dp2(x,S-pthid[x][i].bit)+a[pthid[x][i].id].val) ;
    return ret ;
}

void dp(int x)
{
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        dp(v[x][i]) ;

    int sz=(int)v[x].size() ;
    memset(d,-1,sizeof(d)) ;
    for(int i=0;i<sz;i++)
        ans[i][x]=dp2(x,(1<<sz)-1-(1<<i)) ;
    ans[10][x]=dp2(x,(1<<sz)-1) ;

    if(fa[x]==x) return ;

    for(int i=0;i<path[x].size();i++)
    {
        P &tmp=a[path[x][i]] ;
        if(x==tmp.anc) continue ;

        if(x==tmp.x || x==tmp.y) a[path[x][i]].val += ans[10][x] ;
        else for(int j=0;j<v[x].size();j++) if(v[x][j]!=fa[x])
        {
            if(is_fa(v[x][j],tmp.x) || is_fa(v[x][j],tmp.y))
                a[path[x][i]].val += ans[j][x] ;
        }
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    int cnt=0 ;
    while(m--)
    {
        int x,y,val ; scanf("%d%d%d",&x,&y,&val) ;
        if(!val) v[x].push_back(y) , v[y].push_back(x) ;
        else a[++cnt]=(P){x,y,-1,val} ;
    }
    m=cnt ;
    memset(vis,-1,sizeof(vis)) ;
    dep[1]=0 ; fa[1]=1 ;
    dfs(1,0) ;

    int sum=0 ;
    cnt=0 ;
    for(int i=1;i<=m;i++)
    {
        sum+=a[i].val ;
        if(vis[a[i].x]==vis[a[i].y]) a[++cnt]=a[i] ;
    }
    m=cnt ;

    for(int i=1;i<=m;i++)
    {
        a[i].anc=LCA(a[i].x,a[i].y,i) ;
        int tmp=a[i].anc ;
        if(tmp==a[i].x)
        {
            int j ;
            for(j=0;v[tmp][j]==fa[tmp] || !is_fa(v[tmp][j],a[i].y);j++) ;
            pthid[tmp].push_back((Q){i,1<<j}) ;
        }
        else if(tmp==a[i].y)
        {
            int j ;
            for(j=0;v[tmp][j]==fa[tmp] || !is_fa(v[tmp][j],a[i].x);j++) ;
            pthid[tmp].push_back((Q){i,1<<j}) ;
        }
        else
        {
            int j1,j2 ;
            for(j1=0;v[tmp][j1]==fa[tmp] || !is_fa(v[tmp][j1],a[i].x);j1++) ;
            for(j2=0;v[tmp][j2]==fa[tmp] || !is_fa(v[tmp][j2],a[i].y);j2++) ;
            pthid[tmp].push_back((Q){i,(1<<j1)+(1<<j2)}) ;
        }
    }
    dp(1) ;
    printf("%d\n",sum-ans[10][1]) ;
}
