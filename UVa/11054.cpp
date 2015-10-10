#include<stdio.h>
#define LL long long
LL a[100001] ;
main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        LL ans=0 ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        for(int i=1;i<=n;i++)
        {
            ans += a[i]>0 ? a[i]:-a[i] ;
            a[i+1]+=a[i] ;
        }
        printf("%lld\n",ans) ;
    }
}
