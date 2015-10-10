#include<stdio.h>
#include<algorithm>
#define DB double
#define EPS 1e-10
using namespace std;
struct P {int l,r;}a[100001];
bool cmp(P x,P y)
{
    return x.l<y.l ;
}

int n;

bool check(DB val)
{
    DB now=0.0 ;
    for(int i=1;i<=n;i++)
    {
        if(now+val > (DB)a[i].r) return 0;
        now=max(now,(DB)a[i].l)+val ;
    }
    return 1;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        DB l=0,r=1000001.0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].l,&a[i].r) ;
            r=min(r,(DB)a[i].r-a[i].l) ;
        }
        sort(a+1,a+n+1,cmp) ;
        while(r-l>EPS)
        {
            DB mid=(r+l)/2 ;
            if(check(mid)) l=mid ;
            else r=mid ;
        }
        int ans1=0,ans2=1 ;
        for(int i=1;i<=n;i++)
        {
            int k=(int)((l+EPS)*((DB)i)) ;
            if(k*ans2 > i*ans1) {ans1=k ; ans2=i ;}
        }
        printf("%d/%d\n",ans1,ans2) ;
    }
}
