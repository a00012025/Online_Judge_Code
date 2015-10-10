#include<bits/stdc++.h>
#define LL long long
using namespace std;

inline LL cal(LL a,LL b)
{
    return a/b ;
}
int f[50],lo[50] ;
LL lcm[50] ;
main()
{
    lcm[1]=1 ; lcm[2]=2 ;
    f[2]=1 ; lo[2]=1 ;
    for(int i=3;i<=41;i++)
    {
        lcm[i]=lcm[i-1]/__gcd(lcm[i-1],(LL)i)*i ;
        for(int j=2;;j++) if(i%j)
            {f[i]=j ; break ;}
        lo[i]=lo[f[i]]+1 ;
    }
    LL a,b ;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        LL ans=0 ;
        for(int i=2;i<=41;i++)
        {
            LL num=cal(b,lcm[i-1])-cal(b,lcm[i]) ;
            num-=cal(a-1,lcm[i-1])-cal(a-1,lcm[i]) ;
            ans+=num*lo[i] ;
        }
        printf("%lld\n",ans+b-a+1) ;
    }
}
