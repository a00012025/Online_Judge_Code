#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define MIN(x,y,z) min(x,min(y,z))
using namespace std;

LL cal(LL k,LL x1,LL y1,LL L,LL R,int tp)
{
    if(tp==1) x1-=k-1 ;
    else y1+=k-1 ;
    return MIN(k,R-x1+1,y1-L+1) ;
}

LL solve(LL x,LL y,int d,int tp)
{
    LL k=(1LL<<d) ;
    LL x0=tp==1 ? 2*k-1 : 3*k , y0= tp==1 ? k-1 : 2*k ;

    if(y<x0) return 0LL ;

    LL add=0LL ;
    if(y0<x) add=(x-y0-1)/(2*k)+1 ; add*=2*k ;
    if(x0+add > y) return 0LL ;

    LL ret=2*(k%MOD)*(cal(k,x0+add,y0+add,x,y,tp)%MOD) ; ret%=MOD ;
    if(x0+2*k+add>y) return ret ;
    ret+=2*(k%MOD)*(cal(k,x0+2*k+add,y0+2*k+add,x,y,tp)%MOD) ; ret%=MOD ;
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL L,R ; scanf("%lld%lld",&L,&R) ;
        LL len=R-L+1 ;
        int d=(int)log2(len+1.0) ; d++ ;

        LL ans ;
        while(d>=0)
        {
            ans=solve(L,R,d,2) ;
            if(d) ans+=solve(L,R,d,1) ;
            else ans*=2 ;
            if(ans) break ;
            d-- ;
        }

        if(d==-1) printf("0 %lld\n",R-L+1) ;
        else printf("%lld %d\n",(1LL<<(d+1))-1,ans%MOD) ;
    }
}
