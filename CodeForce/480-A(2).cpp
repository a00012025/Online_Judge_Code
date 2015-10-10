#include<stdio.h>
#include<algorithm>
using namespace std;
struct P{int l,r ;} p[5001];
bool cmp(P x,P y)
{
    if(x.r != y.r) return x.r < y.r ;
    else return x.l < y.l ;
}
main()
{
    int n;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d %d",&p[i].r,&p[i].l) ;
    sort(p+1,p+n+1,cmp) ;
    int now=0 ;
    for(int i=1;i<=n;i++)
    {
        if(p[i].l < now) now=p[i].r ;
        else now=max(now,p[i].l) ;
    }
    printf("%d\n",now) ;
}
