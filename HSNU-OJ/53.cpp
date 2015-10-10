#include<bits/stdc++.h>
#define LL long long
#define MOD 910193
using namespace std;
const int maxn=40010 ;

bool vis[maxn] ;
int p[maxn],cnt ;

void pre_cal()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++cnt]=i ;
}

int num[maxn] ;

void add_fac(int val,int t)
{
    for(int i=1;p[i]<=val;i++)
    {
        int j=val ;
        while(j) num[i]+=t*(j/p[i]) , j/=p[i] ;
    }
}

void add_num(int val,int t)
{
    for(int i=1;i<=cnt && val!=1;i++) if(val % p[i]==0)
    {
        while(val%p[i]==0) num[i]+=t , val/=p[i] ;
    }
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        memset(num,0,sizeof(num)) ;
        add_fac(2*n,1) ;
        add_fac(n,-2) ;
        add_num(n+1,-1) ;
        LL ans=1LL ;
        for(int i=1;i<=cnt;i++)
        {
            while(num[i]) ans*=(LL)p[i] , ans%=MOD , num[i]-- ;
        }
        printf("%lld\n",ans) ;
    }
}
