#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct P{
    int sec,sum ;
    bool operator < (const P &rhs) const
    {
        return sum>rhs.sum ;
    }
};
priority_queue<P> pq ;
main()
{
    int n,a[1000],b[1000];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1) ;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++) scanf("%d",&b[j]) ;
            sort(b+1,b+n+1) ;
            while(!pq.empty()) pq.pop() ;
            for(int i=1;i<=n;i++) pq.push((P){1,a[i]+b[1]}) ;
            for(int i=1;i<=n;i++)
            {
                int x=pq.top().sec , y=pq.top().sum ;
                pq.pop() ;
                a[i]=y ;
                pq.push((P){x+1,y-b[x]+b[x+1]}) ;
            }
        }
        for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
    }

}
