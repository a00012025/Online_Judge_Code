#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,a[100] ;
        scanf("%d%d%d%d%d",&n,&a[1],&a[2],&a[3],&a[4]) ;
        for(int i=5;i<=n;i++) a[i]=a[i-4]+a[i-1] ;
        sort(a+1,a+n+1) ;
        printf("%d\n",a[(n+1)/2]) ;
    }
}
