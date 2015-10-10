#include<bits/stdc++.h>
#define LL long long
#define MOD 100000007
using namespace std;
const int maxn=10000000 + 5 ;
bool vis[maxn]={0} ;
int phifac[maxn] ;

void pre_cal()
{
    vis[1]=1 ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    phifac[1]=phifac[2]=1 ;
    for(int i=3;i<maxn;i++)
        phifac[i]= (((LL)phifac[i-1]) * (vis[i]? (LL)i : (LL)i-1 ))%MOD ;
}

main()
{
    pre_cal() ;
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        int ans=phifac[m] ;
        for(int i=m+1;i<=n;i++) ans = (((LL)ans)*i)%MOD ;
        printf("%d\n",ans-1) ;
    }
}
