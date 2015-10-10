#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define INF 1000000000
using namespace std;
const int maxn=1000+5 ;
inline void up(int &a,int b){a=max(a,b) ;}

int dp[1<<18] ;
int DP(const vector<int> &v)
{
    fill(dp,dp+(1<<18),-INF) ;
    dp[0]=0 ;
    for(int i=0,ma=0;i<v.size();i++)
    {
        int x=1<<v[i] ;
        for(int j=ma;j>=0;j--) if(dp[j]>=0)
            if(!j || (lowbit(j)>=x)) up(dp[j+x],dp[j]+1) , ma=max(ma,j+x) ;
    }
    int ret=0 ;
    for(int i=0;i<18;i++) ret=max(ret,dp[1<<i]) ;
    return ret ;
}

int n ;
vector<int> v[maxn] ;
void solve()
{
    for(int i=0;i<maxn;i++) v[i].clear() ;
    for(int i=1;i<=n;i++)
    {
        int x,y=0 ; scanf("%d",&x) ;
        while(x%2==0) y++ , x/=2 ;
        v[x].push_back(y) ;
    }
    int ans=0 ;
    for(int i=1;i<maxn;i+=2) if(!v[i].empty())
        ans=max(ans,DP(v[i])) ;
    printf("%d\n",ans) ;
}

main()
{
    while(scanf("%d",&n)==1 && n) solve() ;
}
