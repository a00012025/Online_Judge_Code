#include<stdio.h>
#define LL long long
LL a[100001] ;
int ans[100001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        LL sum=0LL ;
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%lld",&a[i]) ; sum+=a[i] ;}
        if(sum%2) {printf("No\n") ; continue ;}
        sum /= 2 ;
        for(int i=n;i>=1;i--)
        {
            if(a[i]>sum) ans[i]=-1 ;
            else
            {
                sum -= a[i] ;
                ans[i]=1 ;
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
    }
}
