#include<bits/stdc++.h>
#define LL long long
using namespace std;

map<LL,int> mp ;

LL power(LL x,int n)
{
    LL ret=1LL ;
    while(n--) ret*=x ;
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        mp.clear();
        int a,b,c,d,p,q,r,w ;
        scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&p,&q,&r,&w) ;
        LL ans=0LL ;
        for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++)
            mp[a*power(i,p)+b*power(j,q)]++ ;
        for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++)
            ans+=mp[-c*power(i,r)-d*power(j,w)] ;
        printf("%lld\n",ans) ;
    }
}
