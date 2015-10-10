#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=100000+10 ;

int n,l[maxn],r[maxn] ;
int cnt[maxn],dep[maxn] ;

void dfs(int x,int d)
{
    if(x==-1){ cnt[d]++ ; return ; }
    dep[x]=d ;
    dfs(l[x],d+1) ;
    dfs(r[x],d+1) ;
}

int num,d0 ;
bool check()
{
    dfs(1,0) ;
    num=0 ;
    for(int i=0;i<=n;i++) if(cnt[i]) num++ ;
    if(num==1) return 1 ;
    if(num>=3) return 0 ;
    bool ok=0 ;
    for(d0=0;d0<=n;d0++) if(cnt[d0]&&cnt[d0+1]){ ok=1 ; break ; }
    if(!ok) return 0 ;
    return 1 ;
}

int ll[maxn],lh[maxn],rl[maxn],rh[maxn] ;
void get_d(int x)
{
    if(l[x]==-1)
    {
        ll[x]= dep[x]==d0 ? 1 : 0 ;
        lh[x]= dep[x]==d0 ? 0 : 1 ;
    }
    else
    {
        get_d(l[x]) ;
        ll[x]=ll[l[x]]+rl[l[x]] ;
        lh[x]=lh[l[x]]+rh[l[x]] ;
    }
    if(r[x]==-1)
    {
        rl[x]= dep[x]==d0 ? 1 : 0 ;
        rh[x]= dep[x]==d0 ? 0 : 1 ;
    }
    else
    {
        get_d(r[x]) ;
        rl[x]=ll[r[x]]+rl[r[x]] ;
        rh[x]=lh[r[x]]+rh[r[x]] ;
    }
}

int solve(int x)
{
    if(!ll[x] && !rl[x]) return 0 ;
    if(!lh[x] && !rh[x]) return 0 ;
    if(ll[x] && rl[x] && lh[x] && rh[x]) return -INF ;
    if(!ll[x]) return 1+solve(r[x]) ;
    if(!rl[x]) return solve(l[x]) ;
    if(!lh[x]) return solve(r[x]) ;
    if(!rh[x]) return 1+solve(l[x]) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]) ;
    if(!check()) { printf("-1\n") ; return 0 ; }
    if(num==1) { printf("0\n") ; return 0 ; }
    get_d(1) ;
    int ans=solve(1) ;
    if(ans<0) printf("-1\n") ;
    else printf("%d\n",ans) ;
}
