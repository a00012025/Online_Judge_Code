#include<bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;
const int maxn=200000+10 ;

LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1LL ;
    LL tmp=power(x,n/2) ;
    if(n%2) return (tmp*tmp%MOD)*x%MOD ;
    else return tmp*tmp%MOD ;
}

LL inv(int x)
{
    return power(x,MOD-2) ;
}

struct LL2
{
    int pow ; LL x ;
    LL get()
    {
        return pow ? 0LL : x ;
    }
    LL2 operator * (const LL2 &rhs) const
    {
        return (LL2){pow+rhs.pow,x*rhs.x%MOD} ;
    }
    LL2 operator / (const LL2 &rhs) const
    {
        return (LL2){pow-rhs.pow,x*inv(rhs.x)%MOD} ;
    }
};

LL2 add1(LL2 p)
{
    if(p.pow) return (LL2){0,1} ;
    else if(p.x+1==MOD) return (LL2){1,1} ;
    else return (LL2){0,p.x+1} ;
}

LL2 ans[maxn],dp[maxn] ;
vector<int> v[maxn] ;
void dfs(int x,int f)
{
    dp[x]=(LL2){0,1} ;
    for(auto i : v[x]) if(i!=f)
        dfs(i,x) ,
        dp[x]=dp[x]*add1(dp[i]) ;
}

void dfs2(int x,int f)
{
    ans[x]=dp[x] ;
    LL2 tmp=dp[x] ;
    for(auto i : v[x]) if(i!=f)
    {
        LL2 tmp2=dp[i] ;
        dp[x]=dp[x]/add1(dp[i]) ;
        dp[i]=dp[i]*add1(dp[x]) ;
        dfs2(i,x) ;
        dp[x]=tmp ; dp[i]=tmp2 ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=2;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        v[i].push_back(x) ;
        v[x].push_back(i) ;
    }
    dfs(1,-1) ;
    dfs2(1,-1) ;
    for(int i=1;i<=n;i++) printf("%I64d%c",ans[i].pow?0:ans[i].x,i==n?'\n':' ') ;
}
