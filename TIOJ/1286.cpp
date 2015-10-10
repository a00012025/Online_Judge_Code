#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000
using namespace std;

LL power(LL x,int n)
{
    if(n==0) return 1LL ;
    if(n==1) return x ;
    LL tmp=power(x,n/2) ;
    if(n%2) return (((tmp*tmp)%MOD)*x)%MOD ;
    else return (tmp*tmp)%MOD ;
}

main()
{
    int a,b,c,d ;
    scanf("%d%d%d%d",&a,&b,&c,&d) ;
    LL ans=0LL ;
    for(int i=a;i<=d;i+=b) ans=(ans+power(i,c))%MOD ;
    printf("%lld\n",ans) ;
}
