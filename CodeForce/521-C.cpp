#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=100000+10 ;

LL power(LL x,int n)
{
    if(n==0) return 1LL ;
    if(n==1) return x ;
    LL tmp=power(x,n/2) ;
    if(n%2) return (tmp*tmp%MOD)*x%MOD ;
    else return tmp*tmp%MOD ;
}

LL inv(LL x)
{
    return power(x,MOD-2) ;
}

LL pw[maxn] ;
int a[maxn] ;
LL sum[maxn] ;
char s[maxn] ;

main()
{
    int n,k ; scanf("%d%d%s",&n,&k,s+1) ;
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0' ,
        sum[i]=sum[i-1]+a[i] ;
    pw[0]=1LL ;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*10%MOD ;

    LL ans=0LL , comb=1LL ;
    for(int i=k-1;i<=n-2;i++)
    {
        ans+=(sum[i+1]*pw[n-i-2]%MOD)*comb ;
        ans%=MOD ;
        comb=(comb*(i+1)%MOD)*inv(i-k+2)%MOD ;
    }
    comb=1LL ;
    for(int i=k+1;i<=n;i++)
    {
        ans+=(a[i]*pw[n-i]%MOD)*comb ;
        ans%=MOD ;
        comb=(comb*i%MOD)*inv(i-k)%MOD ;
    }
    printf("%I64d\n",ans) ;
}
