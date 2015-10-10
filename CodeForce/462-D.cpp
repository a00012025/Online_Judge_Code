#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define LL long long
#define PLL pair<LL,LL>
using namespace std;
const int maxn=100000,mod=1000000007 ;
vector<int> v[maxn+10] ;
LL ans1[maxn+10],ans2[maxn+10] ;
bool black[maxn+10],vis[maxn+10] ;

PLL f(PLL P)
{
    if(P.first==0) return (PLL){0,1} ;
    PLL ret=f((PLL){(P.second)%(P.first) , P.first}) ;
    LL ret1=(ret.second)-(P.second/P.first)*(ret.first) ;
    ret1 %= mod ;
    while(ret1<0) ret1+=mod ;
    return (PLL){ ret1 % mod , ret.first } ;
}

LL inverse(LL n)
{
    LL ret=(f((PLL){n,mod}).first)%mod ;
    while(ret<0) ret+=mod ;
    return ret ;
}

void dfs(int n)
{
    vis[n]=1 ;
    if(v[n].size()==1)
    {
        if(black[n]){ans1[n]=0 ; ans2[n]=1 ;}
        else {ans1[n]=1 ; ans2[n]=0 ;}
        return ;
    }
    LL ALL=1 ;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]) continue ;
        dfs(v[n][i]) ;
        ALL *= (ans1[v[n][i]] + ans2[v[n][i]] % mod) ;
        ALL %= mod ;
    }
    if(black[n])
    {
        ans1[n]=0 ;
        ans2[n]=ALL ;
    }
    else
    {
        ans1[n]=ALL ;
        ans2[n]=0 ;
        for(int i=0;i<v[n].size();i++)
        {
            LL add=ans2[v[n][i]] ;
            add *= ALL ;
            add %= mod ;
            add *= inverse((ans1[v[n][i]] + ans2[v[n][i]]) % mod) ;
            add %= mod ;
            ans2[n]+=add ;
        }
        ans2[n] %= mod ;
    }
}

main()
{
    int n;
    scanf("%d",&n) ;
    for(int i=0;i<=n;i++) v[i].clear() ;
    memset(black,0,sizeof(black)) ;
    memset(ans1,0,sizeof(ans1)) ;
    memset(ans2,0,sizeof(ans2)) ;
    for(int i=0;i<n-1;i++)
    {
        int a ;
        scanf("%d",&a) ;
        v[i+1].push_back(a) ;
        v[a].push_back(i+1) ;
    }
    for(int i=0;i<n;i++)
    {
        int c ;
        scanf("%d",&c) ;
        if(c) black[i]=1 ;
        else black[i]=0 ;
    }
    int start ;
    for(start=0;v[start].size()==1;start++) ;
    dfs(start) ;
    printf("%I64d\n",ans2[start]==0 ? 1 : ans2[start]) ;
}
