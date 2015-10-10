#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
typedef struct {int t,val ;} P;

LL gcd(LL x,LL y)
{
    return (y==0 ? x : gcd(y,x%y)) ;
}

bool cmp(P x,P y)
{
    return ((LL)y.t)*(x.val) > ((LL)x.t)*(y.val) ;
}

P a[100001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        LL time=1,ans=0 ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].t,&a[i].val) ;
            time+=(LL)a[i].t ;
        }
        sort(a+1,a+n+1,cmp) ;
        LL sum=1 ;
        for(int i=1;i<=n;i++)
        {
            ans+=sum*((LL)a[i].t) ;
            sum+=(LL)a[i].val ;
        }
        if(ans==0) printf("0 1\n") ;
        else
        {
            int g=gcd(ans,time) ;
            printf("%lld %lld\n",ans/g,time/g) ;
        }
    }
}
