#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10 ;
int MOD ;
inline void up(int &a,int b){a=(a+b)%MOD;}

struct P{int to ; char c ;};
vector<P> v[maxn] ;
char s[maxn] ;
int dp[2][maxn] ;
void solve()
{
    int n,m ; scanf("%d%d%d%s",&n,&m,&MOD,s) ;
    memset(dp,0,sizeof(dp)) ;
    for(int i=0;i<n;i++) v[i].clear() ;
    while(m--)
    {
        int x,y ; char c[3] ;
        scanf("%d%d%s",&x,&y,c) ;
        v[x].push_back((P){y,c[0]}) ;
    }
    for(int i=0;i<n;i++) dp[0][i]=1 ;
    int cur=1 ;
    for(int i=0;s[i];i++,cur^=1)
    {
        fill(dp[cur],dp[cur]+n,0) ;
        for(int j=0;j<n;j++) for(auto k : v[j]) if(k.c==s[i])
            up(dp[cur][k.to],dp[cur^1][j]) ;
    }
    int ans=0 ;
    for(int i=0;i<n;i++) up(ans,dp[cur^1][i]) ;
    printf("%d\n",ans) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
