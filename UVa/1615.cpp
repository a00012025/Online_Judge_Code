#include<stdio.h>
#include<algorithm>
#include<math.h>
#define EPS 1e-6
#define DB double
using namespace std;
struct P{DB l,r;};
bool cmp(P x,P y)
{
    if(x.l!=y.l) return x.l<y.l ;
    else return x.r<y.r ;
}
P a[1000001] ;
main()
{
    DB D,L;
    int n;
    while(scanf("%lf%lf%d",&L,&D,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            DB x,y ;
            scanf("%lf%lf",&x,&y) ;
            DB d=sqrt(D*D-y*y) ;
            a[i]=(P){max(0.0,x-d-EPS) , min(L,x+d+EPS)} ;
        }
        sort(a+1,a+n+1,cmp) ;
        int ans=0 ; DB now=-1.0 ;
        for(int i=1;i<=n;i++)
        {
            if(i<n && a[i+1].r<=a[i].r) continue ;
            if(now<a[i].l) {now=a[i].r ; ans++ ;}
        }
        printf("%d\n",ans) ;
    }
}
