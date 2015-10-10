#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
using namespace std;
const int INF=1000000000 ;
vector<int> v[100001] ;
int fa[100001],n ;
int c1,c2,dp[100001][5] ;

void XD()
{
    while(1) printf("XDDDDDDD\n") ;
}

int get_ans(int x)
{
    int ret=INF ;
    for(int i=1;i<=4;i++) ret=min(ret,dp[x][i]) ;
    return ret ;
}

int B_val[100001] ;
void dfs(int x)
{
    if(v[x].size()==1 && x!=1)
    {
        dp[x][1]=c1 ; dp[x][2]=c2 ;
        dp[x][3]=INF ; dp[x][4]=0 ; return ;
    }
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        {fa[v[x][i]]=x ; dfs(v[x][i]) ;}
    int ans1=0 ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        ans1 += get_ans(v[x][i]) ;
    dp[x][1]=ans1+c1 ;
    dp[x][2]=c2+B_val[x] ;
    dp[x][3]=INF ; dp[x][4]=0 ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        dp[x][3]=min(dp[x][3],ans1-get_ans(v[x][i])+dp[v[x][i]][2]) ,
        dp[x][4] += min(dp[v[x][i]][1],dp[v[x][i]][3]) ;

    if(fa[fa[x]]!=fa[x]) B_val[fa[fa[x]]]+=get_ans(x) ;
    debugf("dp[%d] : %d,%d,%d,%d\n",x,dp[x][1],dp[x][2],dp[x][3],dp[x][4]) ;
}

bool vis[100001] ;

void dfs2(int x)
{
    vis[x]=1 ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs2(v[x][i]) ;
}

bool connected()
{
    memset(vis,0,sizeof(vis)) ;
    int cnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        cnt=1 ; dfs2(i) ;
    }
    return cnt==1 ;
}

main()
{
    bool fir=1 ;
    while(scanf("%d%d%d",&n,&c1,&c2)==3 && n+c1+c2)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        if(!(n>=1 && n<=10000)) XD() ;
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        if(!connected()) XD() ;
        fa[1]=1 ;
        memset(B_val,0,sizeof(B_val)) ;
        dfs(1) ;
        int ans=get_ans(1) ;
        if(c1==0 || c2==0) ans=0 ;
        if(fir) fir=0 ;
        else printf("\n");
        printf("%d",ans) ;
    }
}

/*
    (1) x為A => cost(A) + (子代ans和)
    (2) x為B => cost(B) + (孫子ans和)
    (3) x無，子代有B => min of (子代選一個放B的ans + 其他子代ans)
    (4) x無，每個子代不是A就是其子代有B => sum(min( __ , __ ))
*/
