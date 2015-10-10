#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[20],prod[20] ;
main()
{
    int n,tc=0,fir=1;
    while(scanf("%d",&n)!=EOF)
    {
        prod[0]=1 ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        LL ans=0 ;
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
        {
            LL now=1 ;
            for(int k=i;k<=j;k++) now *= a[k] ;
            ans=max(now,ans) ;
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++tc,ans) ;
    }
}
