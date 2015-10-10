#include<stdio.h>
#define LL long long
#define MOD 1000000007
int n ;
LL sum[1000001] ;

LL check(LL x)
{
    LL ret=0LL ;
    int l , r=0 ;
    for(l=0;l<=n;l++)
    {
        for(;r<=n && sum[r]-sum[l]<=x ; r++) ;
        ret+=(LL)(r-l-1) ;
    }
    return ret ;
}
main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        LL m ; scanf("%d%lld",&n,&m) ;
        sum[0]=0LL ;
        for(int i=1;i<=n;i++) {LL a ; scanf("%lld",&a) ; sum[i]=sum[i-1]+a ;}
        LL l=0LL , r=sum[n] ;
        while(r-l>1LL)
        {
            LL mid=(r+l)/2 ;
            if(check(mid)<m) l=mid ;
            else r=mid ;
        }
        printf("%lld\n",r%MOD) ;
    }
}
