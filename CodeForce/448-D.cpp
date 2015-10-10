#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

int n,m ;
LL cal(LL x)
{
    LL ret=0 ;
    for(int i=1;i<=n;i++) ret+=min(x/i,(LL)m) ;
    return ret ;
}

main()
{
    LL k ;
    scanf("%d%d%I64d",&n,&m,&k) ;
    LL l=0 , r=(LL)n*m ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(cal(mid)>=k) r=mid ;
        else l=mid ;
    }
    printf("%I64d\n",r) ;
}
