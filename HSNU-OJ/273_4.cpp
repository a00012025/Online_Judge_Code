#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define LL long long
#define MOD 1000000000
using namespace std;
const int maxn=100000+10 ;

LL ans=0LL ;
vector<int> v[maxn] ;
bool vis[maxn] ;
int n,sz[maxn] ;
int dfs(int x)
{
    vis[x]=1 ;
    int ret=sz[x] ;
    for(auto i : v[x]) if(!vis[i])
    {
        int tmp=dfs(i) ;
        ans+=(LL)tmp*(n-tmp)%MOD ;
        ans%=MOD ;
        ret+=tmp ;
    }
    return ret ;
}

int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;
pii a[maxn] ;
map<pii,int> mp ;
int gp[maxn] ;

void solve()
{
    mp.clear() ;
    memset(vis,0,sizeof(vis)) ;
    memset(sz,0,sizeof(sz)) ;
    for(int i=0;i<n;i++) v[i].clear() ;

    sort(a,a+n) ;
    for(int i=0;i<n;i++) mp[a[i]]=i ;
    int cnt=0 ;
    for(int i=0;i<n;i++)
    {
        if(i==0 || a[i].F!=a[i-1].F || a[i].S!=a[i-1].S+1) cnt++ ;
        gp[i]=cnt ; sz[cnt]++ ;
    }

    for(int i=0;i<n;i++) for(int j=0;j<4;j++)
    {
        int nx=a[i].F+dx[j] , ny=a[i].S+dy[j] ;
        auto it=mp.find((pii){nx,ny}) ;
        if(it!=mp.end()) v[gp[i]].push_back(gp[it->S]) ;
    }
    dfs(1) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    solve() ;
    for(int i=0;i<n;i++) swap(a[i].F,a[i].S) ;
    solve() ;
    printf("%lld\n",ans) ;
}
