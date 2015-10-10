#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000+10 ;

LL a[maxn],b[maxn] ;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        LL sa=0LL , sb=0LL ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) , sa+=a[i] ;
        int k,m ; scanf("%d",&k) ;
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]) , sb+=b[i] ;
        scanf("%d",&m) ;

        LL ans=0LL ;
        for(int i=1;i<=n;i++) if(b[i]) ans=max(ans, (b[i]-1)/a[i]+1 ) ;
        ans=max(ans, (sb+k-1)/sa+1 ) ;
        printf("%lld\n",ans) ;
    }
}
