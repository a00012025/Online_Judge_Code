#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10001],sum ;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sum=0 ; int minsum=0 ; int ans=-2147483647 ;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i] ;
            ans=max(ans,sum-minsum) ;
            minsum=min(minsum,sum) ;
        }
        if(ans<=0) printf("Losing streak.\n") ;
        else printf("The maximum winning streak is %d.\n",ans) ;
    }
}
