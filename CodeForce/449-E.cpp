#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=1000000+10 ;

LL pw(LL x,int n)
{
    if(n<=1) return n ? x : 1 ;
    LL t=pw(x,n/2) ;
    if(n%2) return (t*t%MOD)*x%MOD ;
    else return t*t%MOD ;
}
LL inv(LL x)
{
    return pw(x,MOD-2) ;
}

int phi[maxn] ;
LL f[maxn],s1[maxn],s2[maxn],s3[maxn] ;
main()
{
    for(int i=1;i<maxn;i++)
    {
        phi[i]+=i ;
        for(int j=2*i;j<maxn;j+=i) phi[j]-=phi[i] ;
    }
    for(int i=1;i<maxn;i++)
    {
        f[i]=(f[i]+i)%MOD ;
        s1[i]=(s1[i-1]+f[i])%MOD ;
        s2[i]=(s2[i-1]+f[i]*i)%MOD ;
        s3[i]=(s3[i-1]+f[i]*i%MOD*i)%MOD ;
        for(int j=2*i,k=2;j<maxn;j+=i,k++) f[j]+=i*phi[k] ;
    }

    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,m,r ; scanf("%lld%lld",&n,&m) ;
        r=min(m,n) ;
        LL X=r*(r+1)%MOD*inv(180)%MOD ;
        LL Y=6*m*(5*n*((r*r-3*r-1)%MOD)%MOD-4*r*r%MOD*r%MOD+14*r*r%MOD-4*r-6)%MOD
                 +(r-1)*(n*((-24*r*r%MOD+60*r+36)%MOD)%MOD+
                         (20*r*r%MOD)*r%MOD-60*r*r%MOD-5*r+30)%MOD ;
        LL ans=X*Y%MOD ;
        ans+=((m+1)*(n+1)%MOD*s1[r]%MOD-(m+n+2)*s2[r]%MOD+s3[r])*2%MOD + MOD ;
        printf("%lld\n",((ans%MOD)+MOD)%MOD) ;
    }
}
