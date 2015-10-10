#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
main()
{
    int a[3000] ;
    int n,k;
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>()) ;
    int ans=0 ;
    for(int i=1;i<=n;i+=k)
    {
        ans+=2*a[i]-2 ;
    }
    printf("%d\n",ans);
}
