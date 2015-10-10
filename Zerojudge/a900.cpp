#include<stdio.h>
#include<algorithm>
using namespace std;
bool comp(int x,int y)
{
    return x>y ;
}
main()
{
    int T,a[50001],p[50001];
    p[50001] ;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(a+1,a+n+1,comp) ;
        for(int i=1;i<=n-1;i++) p[i]=a[i]-a[i+1] ;
        sort(p+1,p+n,comp) ;
        long long ans=0 ;
        for(int i=1;i<=m-1;i++) ans+=(long long)p[i] ;
        printf("%lld\n",(long long)a[1]-a[n]-ans) ;

    }
}
