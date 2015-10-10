#include<stdio.h>
#include<math.h>
#include<iostream>
#define ULL unsigned long long
#define PWR(a) ((a)*(a))
using namespace std;
int n;
struct point{
    int x,y ;
    bool vis;
    ULL key ;
    }P[1001];
ULL dis(int a,int b)
{
    return PWR((ULL)(P[a].x-P[b].x))+PWR((ULL)(P[a].y-P[b].y)) ;
}
ULL solve()
{
    int now=1,num=n,outminp ;
    ULL outmin,ans=0,max_v ;
    P[1].key=0 ;
    while(--num)
    {
        P[now].vis=1 ; outmin=1LL<<63 ;
        for(int i=1;i<=n;i++)
        {
            if(P[i].vis) continue ;
            if(P[i].key > dis(now,i)) P[i].key=dis(now,i);
            if(P[i].key < outmin)
            {
                outmin=P[i].key ;
                outminp=i ;
            }
        }
        now=outminp ;
        if(outmin>ans) ans=outmin ;
    }
    for(int i=1,max_v=0;i<=n;i++) if(P[i].key>max_v) max_v=P[i].key ;
    return (ULL)(ceil(sqrtl(ans)/2)) ;
}
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d %d",&P[i].x,&P[i].y) ;
        for(int i=0;i<=n;i++) {P[i].vis=0 ; P[i].key=1LL<<63 ; }
        printf("%llu\n",solve()) ;
    }
}
