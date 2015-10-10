#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[300001] ;
main()
{
    LL ans=0 ;
    int n ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]) ;
        ans+=a[i] ;
    }
    make_heap(a+1,a+n+1) ;
    int num=n ;
    while(num>=2)
    {
        LL x=a[1] ;
        pop_heap(a+1,a+num+1) ;
        LL y=a[1] ;
        pop_heap(a+1,a+num) ;
        a[num-1]=x+y ; ans+=x+y ;
        push_heap(a+1,a+num) ;
        num-- ;
    }
    printf("%I64d\n",ans) ;
}
