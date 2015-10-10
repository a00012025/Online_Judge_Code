#include<bits/stdc++.h>
#define LL long long
#define bit(x) __builtin_popcount(x)
using namespace std;
const int maxm=20 , maxn=1<<maxm ;
LL MOD ;

inline LL llmul(LL a,LL b)
{
    LL ret=(a*b-(LL)((long double)a*b/MOD)*MOD)%MOD ;
    if(ret<0) ret+=MOD ;
    return ret ;
}

LL power(LL x,LL n)
{
    if(n<=1) return n ? x : 1 ;
    LL t=power(x,n/2) ;
    if(n%2) return llmul(llmul(t,t),x) ;
    else return llmul(t,t) ;
}

void FWT(LL *a,int n)
{
    if(n==1) return ;
    int n2=n>>1 ;
    FWT(a,n2) ; FWT(a+n2,n2) ;
    for(int i=0;i<n2;i++)
    {
        LL x=a[i] , y=a[i+n2] ;
        a[i]=(x+y)%MOD ;
        a[i+n2]=(x-y+MOD)%MOD ;
    }
}

LL e0[maxn],b[maxm+10],c[maxn] ;
LL ev[maxn] ; /// eigenvalue
main()
{
    int n,m ; LL t,p ; scanf("%d%lld%lld",&m,&t,&p) ;
    n=1<<m ; MOD=n*p ;
    for(int i=0;i<n;i++) scanf("%lld",&e0[i]) ;
    for(int i=0;i<=m;i++) scanf("%lld",&b[i]) ;
    for(int i=0;i<n;i++) ev[i]=b[bit(i)]%MOD ;

    FWT(e0,n) ;
    FWT(ev,n) ;
    for(int i=0;i<n;i++) c[i]=llmul(e0[i],power(ev[i],t)) ;
    FWT(c,n) ;
    for(int i=0;i<n;i++) printf("%lld\n",((c[i]+MOD)%MOD)>>m) ;
}
