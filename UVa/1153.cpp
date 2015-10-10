#include<stdio.h>
#include<algorithm>
using namespace std;
struct P {int t,ed;};
bool cmp(P x,P y)
{
    if(x.ed!=y.ed) return x.ed<y.ed ;
    else return x.t<y.t ;
}
P a[800001] ;

bool check(int now,int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        if(now+a[i].t > a[i].ed) return 0;
        now += a[i].t ;
    }
    return 1;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].t,&a[i].ed) ;
        sort(a+1,a+n+1,cmp) ;
        int now=0 , ans=0 ;
        for(int i=1;i<=n;)
        {
            int j;
            for(j=i;j<n && a[j+1].t<a[j].t;j++) ;
            int l=i-1 , r=j+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(check(now,mid,j)) r=mid ;
                else l=mid ;
            }
            for(int z=r;z<=j;z++) now+=a[z].t ;
            ans+=j-r+1 ;
            i=j+1 ;
        }
        printf("%d\n\n",ans) ;
    }
}
