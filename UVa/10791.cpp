#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=50000 + 5 ;
int cnt ;
LL pm[maxn] ;
bool vis[maxn] ;
void get_prime()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        for(int j=i*i;j>0 && j<maxn;j+=i) vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        pm[++cnt]=(LL)i ;
}

bool is_prime(LL x)
{
    if(x<maxn) return vis[x]==0 ;
    for(int i=1;i<=cnt;i++) if(x%pm[i]==0) return 0 ;
    return 1 ;
}

LL n ;
LL solve()
{
    if(n==1) return 2 ;
    if(is_prime(n)) return n+1 ;
    LL ans=0LL ; int num=0 ;
    for(int i=1;i<=cnt;i++) if(n%pm[i]==0)
    {
        num++ ;
        LL add=1 ;
        while(n%pm[i]==0) {add*=pm[i] ; n/=pm[i] ;}
        ans+=add ;
    }
    if(num==1) ans++ ;
    if(n!=1) ans+=n ;
    return ans ;
}

main()
{
    get_prime() ;
    int tc=0 ;
    while(scanf("%lld",&n)==1 && n) printf("Case %d: %lld\n",++tc,solve()) ;
}
