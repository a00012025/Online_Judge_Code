#include<stdio.h>
#define LL long long

LL power(LL a,int b)
{
    LL ret=1 ;
    while(b--) ret*=a ;
    return ret ;
}

int digit(LL n,int pos)
{
    LL x=n/power(10,pos) ;
    x*=10 ;
    LL y=n/power(10,pos-1) ;
    return y-x ;
}

bool ok(LL n)
{
    if(n<10) return true ;
    LL k=1 ;
    while(k-1<n) k*=10 ;
    k/=10 ;
    if((n/k) != (n%10)) return false ;
    n-=(n/k)*k ; n/=10 ;
    return ok(n) ;
}

LL rev(LL n)
{
    LL k=1 , ret=0 ; int num=0 ;
    while(power(10,num)-1<n) num++ ;
    for(int i=1;i<=num;i++) ret+=digit(n,i)*power(10,num-i) ;
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0 ;
        LL n ;
        scanf("%lld",&n) ;
        while(!ok(n))
        {
            n+=rev(n) ;
            ans++ ;
        }
        printf("%d %lld\n",ans,n) ;
    }
}
