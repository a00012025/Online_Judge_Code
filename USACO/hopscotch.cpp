#include<bits/stdc++.h>
#define MOD 1000000007
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=750+10 ;

vector<int> bit[maxn*maxn] ;
void add(int id,int x,int val)
{
    while(x<bit[id].size())
        bit[id][x]=(bit[id][x]+val)%MOD ,
        x+=lowbit(x) ;
}
int query(int id,int x)
{
    int ret=0 ;
    while(x) ret=(ret+bit[id][x])%MOD , x-=lowbit(x) ;
    return ret ;
}

vector<int> col[maxn*maxn] ;
int G[maxn][maxn],dp[maxn][maxn] ;
int sum[maxn] ;

main()
{
    if(fopen("hopscotch.in","r"))
    {
        freopen("hopscotch.in","r",stdin) ;
        freopen("hopscotch.out","w",stdout) ;
    }

    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        scanf("%d",&G[i][j]) ;
        col[G[i][j]].push_back(j) ;
    }
    for(int i=1;i<=k;i++)
    {
        sort(col[i].begin(),col[i].end()) ;
        col[i].resize(unique(col[i].begin(),col[i].end())-col[i].begin()) ;
        bit[i].resize(col[i].size()+1) ;
    }

    dp[1][1]=1 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 || j==1) continue ;
            int c=G[i][j] ;
            int id=lower_bound(col[c].begin(),
                    col[c].end(),j) - col[c].begin() + 1 ;
            dp[i][j]=(sum[j-1]-query(c,id-1))%MOD ;
            if(dp[i][j]<0) dp[i][j]+=MOD ;
        }
        for(int j=1,s=0;j<=m;j++)
        {
            s=(s+dp[i][j])%MOD ;
            sum[j]=(sum[j]+s)%MOD ;
            int c=G[i][j] ;
            int id=lower_bound(col[c].begin(),
                    col[c].end(),j) - col[c].begin() + 1 ;
            add(c,id,dp[i][j]) ;
        }
    }
    printf("%d\n",dp[n][m]) ;
}
