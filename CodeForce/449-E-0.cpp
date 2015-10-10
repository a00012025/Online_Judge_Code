#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
main()
{
    int T ; LL n,m,r ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%lld%lld",&n,&m) ; r=min(m,n) ;
        LL ans=0 ;
        for(int x=0;x<=r;x++) for(int y=1;x+y<=r;y++)
            ans+=(m-x-y+1)*(n-x-y+1)*((x-y)*(x-y)+(x*y-x-y+__gcd(x,y))*2) ;
        LL ans0=0 ;
        for(int x=0;x<=r;x++) for(int y=1;x+y<=r;y++)
            ans0+=(m-x-y+1)*(n-x-y+1)*__gcd(x,y)*2 ;
        printf("ans0 = %lld\n",ans0%MOD) ;

//        for(int t=1;t<=min(n,m);t++) for(int x=0;x<t;x++)
//            ans+=(m-t+1)*(n-t+1)*((t-2*x)*(t-2*x)+
//                (x*t-t-x*x+__gcd(t,x))/2) ;
        printf("%lld\n",ans%MOD) ;
    }
}
