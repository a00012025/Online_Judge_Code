#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    LL ans=0 ;
    for(int i=1;i<=n && i<=k+1;)
    {
        int x=i , y=k+2-i ;
        int x2=n/(n/i) , y2=m/(m/y+1)+1 ;
        ans=max(ans,(LL)(n/x)*(m/y)) ;
        i=min(x2,k+2-y2)+1 ;
    }
    printf("%lld\n",ans ? ans : -1) ;
}
