#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL a[10010] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n ; int m ;
        scanf("%lld%d",&n,&m) ;
        for(int i=1;i<=m;i++) scanf("%lld",&a[i]) ;
        sort(a+1,a+m+1) ;
        LL ans=0LL ;
        if(a[1]>=3) ans+=(a[1]-1)/2 ;
        for(int i=1;i<m;i++) if(a[i+1]>=a[i]+4)
            ans+=(a[i+1]-a[i]-2)/2 ;
        if(a[m]<=n-2) ans+= (n-a[m])/2 ;
        printf("%lld\n",ans) ;
    }
}
