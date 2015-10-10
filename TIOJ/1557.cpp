#include<bits/stdc++.h>
#define MOD 1073741824
using namespace std;
const int maxn=10000+10 ;
vector<int> v[maxn] ;
bool vis[maxn] ;
int d[maxn] ;

int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    vis[x]=1 ;
    int &ans=d[x] ; ans=0 ;
    for(auto i : v[x])
    {
        if(vis[i]) return ans=0 ;
        ans=(ans+dp(i))%MOD ;
    }
    vis[x]=0 ;
    return ans ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
    }
    int st,ed ; scanf("%d%d",&st,&ed) ;
    memset(d,-1,sizeof(d)) ;
    d[ed]=1 ;
    printf("%d\n",dp(st)) ;
}
