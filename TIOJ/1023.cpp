#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=50000+10 ;
LL a[maxn],b[maxn] ;
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]) ;
        sort(a+1,a+n+1) ;
        sort(b+1,b+n+1) ;
        LL ans=0LL ;
        for(int i=1;i<=n;i++) ans+=a[i]*b[i] ;
        printf("%lld\n",ans) ;
    }
}
