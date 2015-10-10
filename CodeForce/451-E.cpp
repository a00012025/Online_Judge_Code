#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=20 ;

LL power(LL x,int n)
{
    if(n<=1) return n ? x : 1 ;
    LL t=power(x,n/2) ;
    if(n%2) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}
LL inv(int x)
{
    return power(x,MOD-2) ;
}

LL fac[maxn],ifac[maxn] ;
LL C(LL n,int m)
{
    n%=MOD ;
    if(n<m) return 0 ;
    LL ret=1 ;
    for(int i=0;i<m;i++) ret=ret*(n-i)%MOD ;
    return ret*ifac[m]%MOD ;
}

LL a[maxn],ans ;
int n ;
void dfs(int x,LL s,int mul)
{
    if(x==n){ans=(ans+mul*C(s+n-1,n-1))%MOD ; return ;}
    dfs(x+1,s,mul) ;
    if(s>a[x]) dfs(x+1,s-a[x]-1,-mul) ;
}

main()
{
    for(int i=0;i<maxn;i++) fac[i]= (i?fac[i-1]*i%MOD : 1) , ifac[i]=inv(fac[i]) ;
    LL s ; scanf("%d%lld",&n,&s) ;
    for(int i=0;i<n;i++) scanf("%lld",&a[i]) ;
    dfs(0,s,1) ;
    printf("%lld\n",(ans+MOD)%MOD) ;
}
