#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

int dp1[6001][3002],dp2[6001][3002],num1[6001],num2[6001] ;
int a[6001] ;
vector<int> v[6001] ;

int d[6001],fa[6001] ;
void dfs(int x,int dep)
{
    d[x]=dep ;
    for(int i=0;i<v[x].size();i++) if(d[v[x][i]]==-1)
        dfs(v[x][i],dep+1) ;
}

int ans ;
void DP(int x)
{
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
    {
        fa[v[x][i]]=x ;
        DP(v[x][i]) ;
    }

    debugf("DP(%d)\n",x) ;

    if(v[x].size()==1 && fa[x]!=x)
        { num1[x]=num2[x]=1 ; dp1[x][1]=dp2[x][1]=a[x] ; ans=max(ans,1) ; return ; }

    int M=-INF , m=-INF , Mid ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
    {
        int y=v[x][i] ;
        int id=lower_bound(dp1[y],dp1[y]+num1[y]+1,a[x]) - dp1[y] ; id-- ;
        debugf("y=%d , id=%d\n",y,id) ;
        if(id>=M) Mid=i , m=M , M=id ;
        else if(id>m) m=id ;

        for(int j=1;j<=num1[y];j++)
        {
            if(num1[x]<j) num1[x]++ , dp1[x][j]=dp1[y][j] ;
            else dp1[x][j]=min(dp1[x][j],dp1[y][j]) ;
        }
    }
    ans=max(ans,M+1) ;
    int id=lower_bound(dp1[x],dp1[x]+num1[x]+1,a[x]) - dp1[x] ;
    if(id==num1[x]+1) num1[x]++ , dp1[x][id]=a[x] ;
    else dp1[x][id]=min(dp1[x][id],a[x]) ;

    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
    {
        int y=v[x][i] ;
        int id=lower_bound(dp2[y],dp2[y]+num2[y]+1,a[x],greater<int>()) - dp2[y] ;
        id-- ;
        debugf("y=%d , id=%d\n",y,id) ;
        ans=max(ans,id+1) ;
        if(i!=Mid) ans=max(ans,M+id+1) ;
        else ans=max(ans,m+id+1) ;

        for(int j=1;j<=num2[y];j++)
        {
            if(num2[x]<j) num2[x]++ , dp2[x][j]=dp2[y][j] ;
            else dp2[x][j]=min(dp2[x][j],dp2[y][j]) ;
        }
    }
    id=lower_bound(dp2[x],dp2[x]+num2[x]+1,a[x],greater<int>()) - dp2[x] ;
    if(id==num2[x]+1) num2[x]++ , dp2[x][id]=a[x] ;
    else dp2[x][id]=max(dp2[x][id],a[x]) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    memset(d,-1,sizeof(d)) ;
    dfs(1,0) ;
    int M=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>M) M=d[id=i] ;
    memset(d,-1,sizeof(d)) ;
    dfs(id,0) ;
    M=-1 ;
    for(int i=1;i<=n;i++) if(d[i]>M) M=d[id=i] ;
    while(d[id]!=M/2)
    {
        int j ;
        for(j=0;j<v[id].size();j++) if(d[v[id][j]]==d[id]-1) break ;
        id=v[id][j] ;
    }
    fa[id]=id ; ans=0 ;
    memset(num1,0,sizeof(num1)) ;
    memset(num2,0,sizeof(num2)) ;
    for(int i=1;i<=n;i++) dp2[i][0]=INF ;
    DP(id) ;
    printf("%d\n",ans) ;
}
