#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
#define INF 10000000
using namespace std;
struct P {int to,w ;};
vector<P> v[101] ;
vector<int> fa[101] ;
queue<int> q ;
bool esc[101],inq[101] ;
int n,d1[101],d2[101] ;

double dfs(int x,int y)
{
    if(x==y) return 0.0 ;
    double ret=INF ;
    for(int i=0;i<fa[x].size();i++)
    {
        double sp=(160.0)*d1[x]/d2[x] ;
        double newsp=max(sp,dfs(fa[x][i],y)) ;
        ret=min(newsp,ret) ;
    }
    //printf("dfs %d %d : %lf\n",x,y,ret) ;
    return ret ;
}

void SSSP(int s,int *d,int wall)
{
    for(int i=1;i<=n;i++) fa[i].clear() ;
    for(int i=1;i<=n;i++) d[i]=INF ;
    memset(inq,0,sizeof(inq)) ;
    d[s]=0 ; inq[s]=1 ; q.push(s) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        if(u==wall) continue ;
        for(int i=0;i<v[u].size();i++)
            if(d[v[u][i].to] > d[u] + v[u][i].w)
            {
                fa[v[u][i].to].clear() ;
                fa[v[u][i].to].push_back(u) ;

                d[v[u][i].to] = d[u] + v[u][i].w ;
                if(!inq[v[u][i].to]) q.push(v[u][i].to) ;
                inq[v[u][i].to]=1 ;
            }
            else if(d[v[u][i].to] > d[u] + v[u][i].w)
                fa[v[u][i].to].push_back(u) ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int m,e ;
        scanf("%d%d%d",&n,&m,&e) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        memset(esc,0,sizeof(esc)) ;
        while(m--)
        {
            int a,b,w ;
            scanf("%d%d%d",&a,&b,&w) ;
            v[a].push_back((P){b,w}) ;
            v[b].push_back((P){a,w}) ;
        }
        while(e--)
        {
            int a;
            scanf("%d",&a) ;
            esc[a]=1 ;
        }
        int st1,st2 ;
        scanf("%d %d",&st1,&st2) ;
        SSSP(st2,d2,-1) ;
        SSSP(st1,d1,st2) ;
        double ans=INF ;/*
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<fa[i].size();j++) printf("%d,",fa[i][j]);
                printf("\n");
            }*/
        for(int i=1;i<=n;i++) if(esc[i] && d1[i]!=INF)
            ans=min(ans,dfs(i,st1)) ;
        if(ans==INF) printf("IMPOSSIBLE\n") ;
        else printf("%.9lf\n",ans) ;
    }
}
