#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P{int st,ed,len ;}p[maxn];
bool cmp(const P &x,const P &y)
{
    if(x.len!=y.len) return x.len>y.len ;
    return x.st>y.st ;
}

vector<int> v[maxn] ;
int n,topo[maxn],d[maxn],fa[maxn],t ;

void dfs(int x,int len)
{
    d[x]=len ;
    for(int i=0;i<v[x].size();i++) if(!d[v[x][i]])
        fa[v[x][i]]=x , dfs(v[x][i],len+1) ;
    topo[--t]=x ;
}

bool used[maxn] ;
main()
{
    int k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    if(!k) { printf("0\n") ; return 0 ; }
    if(n==1) { printf("1\n") ; return 0 ; }

    memset(d,0,sizeof(d)) ;
    t=n+1 ; dfs(1,1) ;

    int M=0 , id ;
    for(int i=1;i<=n;i++) if(d[i]>M) M=d[id=i] ;
    memset(d,0,sizeof(d)) ;
    t=n+1 ; dfs(id,1) ; fa[id]=id ;
    for(int i=n;i>=1;i--)
    {
        int u=topo[i] ;
        p[u]=(P){u,u,1} ;
        for(int j=0;j<v[u].size();j++) if(v[u][j]!=fa[u] && p[v[u][j]].len+1>p[u].len)
            p[u].len=p[v[u][j]].len+1 , p[u].ed=p[v[u][j]].ed ;
    }
    sort(p+1,p+n+1,cmp) ;
    for(int i=1;i<=n;i++)
    int now=1 ;
    for(int i=1;i<=2*k-1 && now<=n;i++)
    {
        while(now<=n && used[p[now].st]) now++ ;
        if(now>n) break ;
        used[p[now].ed]=1 ;
        for(int j=p[now].ed;j!=p[now].st && !used[fa[j]];j=fa[j]) used[fa[j]]=1 ;
        now++ ;
    }
    int ans=0 ;
    for(int i=1;i<=n;i++) if(used[i]) ans++ ;
    printf("%d\n",ans) ;
}
