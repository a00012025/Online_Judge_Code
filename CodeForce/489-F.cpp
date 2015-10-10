#include<bits/stdc++.h>
#define LL long long
using namespace std;
int num[501],MOD,n ;

struct P
{
    int x,y,z ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        if(y!=rhs.y) return y<rhs.y ;
        return z<rhs.z ;
    }
};

map<P,LL> mp ;

LL dp(int x,LL a,LL b)
{
    //printf("%I64d,%I64d\n",a,b) ;
    if(x==n) return ( a==0 && b==0 ? 1LL : 0LL) ;
    if(mp.count((P){x,a,b})) return mp[(P){x,a,b}] ;
    LL ans=0LL ;
    if(a>=2) ans+=(((a*(a-1)/2)%MOD) * dp(x+1,a-2,b+2)) % MOD , ans %= MOD ;
    if(a && b) ans+=( ((a*b)%MOD) * dp(x+1,a-1,b) ) % MOD , ans %= MOD ;
    if(b>=2) ans+=(((b*(b-1)/2)%MOD) * dp(x+1,a,b-2) ) % MOD , ans %= MOD ;
    return mp[(P){x,a,b}]=ans ;
}

main()
{
    int k ; char s[600] ;
    scanf("%d%d%d",&n,&k,&MOD) ;
    for(int i=1;i<=k;i++)
    {
        scanf("%s",s) ;
        for(int j=0;j<n;j++) if(s[j]=='1') num[j]++ ;
    }
    int a=0 , b=0 ; /// need 2 , need 1
    for(int i=0;i<n;i++)
    {
        if(num[i]==0) a++ ;
        if(num[i]==1) b++ ;
    }
    printf("%I64d\n",dp(k,a,b)) ;
}
