#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct P
{
    int t,ed;
    bool operator < (const P &rhs) const
    {
        if(t!=rhs.t) return t<rhs.t ;
        else return ed<rhs.ed ;
    }
}a[800001] ;

bool cmp(P x,P y)
{
    if(x.ed!=y.ed) return x.ed<y.ed ;
    else return x.t<y.t ;
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
        priority_queue<P> pq ;
        int now=0 ;
        for(int i=1;i<=n;i++)
        {
            if(pq.size() && pq.top().t>a[i].t && now+a[i].t>a[i].ed)
            {
                now -= pq.top().t-a[i].t ;
                pq.pop() ;
                pq.push(a[i]) ;
            }
            else if(now+a[i].t <= a[i].ed)
            {
                now += a[i].t ;
                pq.push(a[i]) ;
            }
        }
        printf("%d\n",pq.size()) ;
        if(T) printf("\n") ;
    }
}
