#include<bits/stdc++.h>
using namespace std;
const int maxn=20 ;

struct P
{
    int x1,y1,x2,y2 ;
    void scan()
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
        if(x1>x2||y1>y2) swap(x1,x2) , swap(y1,y2) ;
    }
}a[1000];

bool inter(P p,P q)
{
    if(p.x1==p.x2&&q.x1==q.x2)
    {
        if(p.x1!=q.x1) return 0 ;
        if(p.y1>q.y2) return 0 ;
        if(q.y1>p.y2) return 0 ;
        return 1 ;
    }
    if(p.y1==p.y2&&q.y1==q.y2)
    {
        if(p.y1!=q.y1) return 0 ;
        if(p.x1>q.x2) return 0 ;
        if(q.x1>p.x2) return 0 ;
        return 1 ;
    }
    if(q.x1==q.x2) swap(p,q) ;
    return q.x1<=p.x1 && p.x1<=q.x2 && p.y1<=q.y1 && q.y1<=p.y2 ;
}

vector<int> v[1000] ;
bool vis[1000],G[maxn][maxn] ;
void dfs(int x)
{
    vis[x]=1 ;
    for(int i=a[x].x1;i<=a[x].x2;i++)
        for(int j=a[x].y1;j<=a[x].y2;j++) G[i][j]=1 ;
    for(auto i : v[x]) if(!vis[i]) dfs(i) ;
}

main()
{
    if(fopen("in","r"))
        freopen("in","r",stdin) ,
        freopen("out2","w",stdout) ;
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) a[i].scan() ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        if(inter(a[i],a[j]))
        v[i].push_back(j) , v[j].push_back(i) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        memset(G,0,sizeof(G)) ;
        dfs(i) ;
        ans=max(ans,count(G[0],G[maxn-1]+maxn,true)-1) ;
    }
    printf("%d\n",ans) ;
}

