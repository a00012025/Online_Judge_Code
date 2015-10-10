#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

int nex[maxn] ;
int dis[maxn],ord[maxn],cycpt[maxn],cycid[maxn] ;
int size[maxn] ;
int ccnt=0 ;

int fa[maxn],vis[maxn] ;
void dfs(int x)
{
    if(vis[x]==-1)
    {
        ccnt++ ;
        int cnt=0 ;
        for(int y=x;;y=fa[y])
        {
            size[ccnt]++ ;
            ord[y]=++cnt ;
            cycpt[y]=y ;
            cycid[y]=ccnt ;
            if(fa[y]==x || fa[y]==-1) break ;
        }
        vis[x]=1 ;
        return ;
    }

    vis[x]=-1 ;
    if(vis[nex[x]]!=1) fa[nex[x]]=x , dfs(nex[x]) ;

    vis[x]=1 ;
    if(ord[x]) return ;
    dis[x]=dis[nex[x]]+1 ;
    cycpt[x]=cycpt[nex[x]] ;
    vis[x]=1 ;
}

vector<int> v[maxn] ;
int anc[19][maxn],dep[maxn] ;
void dfs2(int x)
{
    for(int i=1;i<19;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
    for(int i=0;i<v[x].size();i++)
        anc[0][v[x][i]]=x , dep[v[x][i]]=dep[x]+1 ,
        dfs2(v[x][i]) ;
}

int getfa(int x,int d)
{
    if(!d) return x ;
    for(int i=18;i>=0 && d;i--) if(d&(1<<i))
        x=anc[i][x] , d^=(1<<i) ;
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]!=dep[y]) return dep[x]>dep[y] ?
        LCA(getfa(x,dep[x]-dep[y]),y) :
        LCA(x,getfa(y,dep[y]-dep[x])) ;
    if(x==y) return x ;
    for(int i=18;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return anc[0][x] ;
}

int ans1,ans2 ;
bool better(int d1,int d2)
{
    if(ans1==-1) return 1 ;
    if(max(d1,d2)!=max(ans1,ans2)) return max(d1,d2)<max(ans1,ans2) ;
    if(min(d1,d2)!=min(ans1,ans2)) return min(d1,d2)<min(ans1,ans2) ;
    return d1>=d2 ;
}
inline void update(int d1,int d2) { if(better(d1,d2)) ans1=d1 , ans2=d2 ; }

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&nex[i]) ;

    for(int i=1;i<=n;i++) if(!vis[i])
        fa[i]=-1 , dfs(i) ;

    for(int i=1;i<=n;i++) if(!ord[i] || !ord[nex[i]])
        v[nex[i]].push_back(i) ;
    for(int i=1;i<=n;i++) if(ord[i])
        anc[0][i]=i , dfs2(i) ;

    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(cycid[cycpt[x]]!=cycid[cycpt[y]])
            { printf("-1 -1\n") ; continue ; }
        if(cycpt[x]==cycpt[y])
        {
            int lca=LCA(x,y) ;
            printf("%d %d\n",dep[x]-dep[lca],dep[y]-dep[lca]) ;
            continue ;
        }

        ans1=ans2=-1 ;
        int d1=dis[x] , d2=dis[y] , id=cycid[cycpt[x]] ;
        int sz=size[id] ;
        int cdis=(ord[cycpt[x]]-ord[cycpt[y]]+sz)%sz ;
        update(d1+cdis,d2) ;
        update(d1,d2+sz-cdis) ;
        printf("%d %d\n",ans1,ans2) ;
    }
}
