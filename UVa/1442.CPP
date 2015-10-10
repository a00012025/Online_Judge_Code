#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001],b[1000001],h1[1000010],h2[1000010] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
        h1[0]=3000 ;
        for(int i=1;i<=n;i++)
        {
            if(h1[i-1]>=b[i]) h1[i]=b[i] ;
            else if(h1[i-1]<=a[i]) h1[i]=a[i] ;
            else h1[i]=h1[i-1] ;
            //printf("h1[%d]=%d\n",i,h1[i]) ;
        }
        h2[n+1]=2000 ;
        for(int i=n;i>=1;i--)
        {
            if(h2[i+1]>=b[i]) h2[i]=b[i] ;
            else if(h2[i+1]<=a[i]) h2[i]=a[i] ;
            else h2[i]=h2[i+1] ;
            //printf("h2[%d]=%d\n",i,h2[i]) ;
        }
        int ans=0 ;
        for(int i=1;i<=n;i++) ans += min(h1[i],h2[i])-a[i] ;
        printf("%d\n",ans) ;
    }
}
