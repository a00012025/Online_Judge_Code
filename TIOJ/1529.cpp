#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=500000+10 ;
const DB eps=1e-7 ;

struct P
{
    DB x,y ;
    bool operator < (const P &rhs) const
    {
        if(fabs(y-rhs.y)<eps) return x<rhs.x ;
        return y<rhs.y ;
    }
};

P a[maxn];
priority_queue<P> pq ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y) ;
    sort(a+1,a+n+1) ;
    DB now=0.0 , ans=0.0 ;
    for(int i=1;i<=n;i++)
    {
        now+=a[i].x ;
        pq.push((P){1.0,a[i].x}) ;
        if(now>a[i].y)
            while(fabs(now-a[i].y)>eps)
        {
            P u=pq.top() ; pq.pop() ;
            DB t=now-a[i].y ;
            if( t > u.y*u.x ) now-= u.y*u.x , ans+=100.0*u.x ;
            else now=a[i].y , pq.push((P){u.x-t/u.y,u.y}) ,
                    ans+= 100.0*(t/u.y) ;
        }
    }
    printf("%.3f\n",ans) ;
}
