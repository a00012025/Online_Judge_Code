#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+100 ;
int a[maxn],b[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
        LL ans=0LL ;
        for(int i=1;i<=n;i++) ans=max(ans,((LL)k/a[i])*((LL)b[i])) ;
        printf("%lld\n",ans) ;
    }
}
