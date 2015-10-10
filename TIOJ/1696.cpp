#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int val[maxn] ;
vector<int> v[maxn] ;
bool vis[maxn] ;
int sum[maxn],sum2[maxn],sz1,sz2 ;
int cnt ;

int d[maxn] ;
void dfs0(int x,int &M,int dep)
{
    d[x]=dep ; vis[x]=1 ; cnt++ ;
    if(d[x]>d[M]) M=x ;
    for(auto i : v[x]) if(!vis[i])
        dfs0(i,M,dep+1) ;
    vis[x]=0 ;
}

int get_cent(int x,int &sz)
{
    int y=x ; cnt=0 ;
    dfs0(x,y,0) ; sz=cnt ;
    x=y ;
    dfs0(y,x,0) ;

    int maxd=d[x] ;
    if(!maxd) return x ;
    for(int i=x;;)
    {
        for(auto j : v[i]) if(!vis[j] && d[j]==d[i]-1)
            { i=j ; break ; }
        if(d[i]==maxd/2) return i ;
    }
}

void dfs_dis(int x,int dep,int *sm)
{
    sm[dep]++ ;
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
        dfs_dis(i,dep+1,sm) ;
    vis[x]=0 ;
}

int ans[maxn] ;

void dfs_cal(int x,int dep)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
        dfs_cal(i,dep+1) ;
    vis[x]=0 ;

    int val2=val[x]-dep-1 ;
    if(val2>=0) ans[x]+= ( val2<=sz1 ? sum[val2] : sum[sz1] ) ,
                ans[x]-= (val2<=sz2 ? sum2[val2] : sum2[sz2]) ;
}

void solve(int y)
{
    int x=get_cent(y,sz1) ;

    fill(sum,sum+sz1+1,0) ;
    dfs_dis(x,0,sum) ;
    for(int i=1;i<=sz1;i++) sum[i]+=sum[i-1] ;
    ans[x]+= (val[x]<=sz1 ? sum[val[x]] : sum[sz1]) ;

    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i])
    {
        get_cent(i,sz2) ;
        fill(sum2,sum2+sz2+1,0) ;
        dfs_dis(i,1,sum2) ;
        for(int i=1;i<=sz2;i++) sum2[i]+=sum2[i-1] ;
        dfs_cal(i,0) ;
    }
    for(auto i : v[x]) if(!vis[i])
        solve(i) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&val[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    solve(1) ;
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]) ;
}
