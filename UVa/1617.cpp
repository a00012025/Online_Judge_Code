#include<stdio.h>
#include<algorithm>
using namespace std;
struct P {int l,r;}a[100001];
bool cmp(P x,P y)
{
    if(x.l!=y.l) return x.l<y.l ;
    else return x.r<y.r ;
}
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r) ;
        sort(a+1,a+n+1,cmp) ;
        int nowl=a[1].l+1 , nowr=a[1].r , ans=0 ;
        for(int i=2;i<=n;i++)
        {
            if(nowr<a[i].l) {nowl=a[i].l+1 ; nowr=a[i].r ; ans++ ;}
            else
            {
                nowl=max(nowl,a[i].l) ;
                nowr=min(nowr,a[i].r-1) ;
                nowl++ ; nowr++ ;
            }
        }
        printf("%d\n",ans) ;
    }
}
