#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=100000+10 ;
struct P{int id,val ;};
int sum[2*maxn],a[maxn] ;
deque<P> dq ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        sum[0]=0 ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , sum[i]=sum[i-1]+a[i] ;
        for(int i=n+1;i<=2*n;i++) sum[i]=sum[i-1]+a[i-n] ;

        while(!dq.empty()) dq.pop_front() ;
        dq.push_front((P){0,0}) ;
        int ans=-INF ;
        for(int i=1;i<=2*n;i++)
        {
            while(!dq.empty() && dq.back().id < i-k) dq.pop_back() ;
            ans=max(ans,sum[i]-dq.back().val) ;
            while(!dq.empty() && dq.front().val>=sum[i]) dq.pop_front() ;
            dq.push_front((P){i,sum[i]}) ;
        }

        printf("%d\n",ans) ;
    }
}
