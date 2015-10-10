#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=10000+10 ;

struct P{int id,val;};

int dp[maxn] ;
deque<P> dq[101] ;
main()
{
    int n ; scanf("%d",&n) ;
    fill(dp,dp+maxn,-INF) ;
    dp[0]=0 ;
    while(n--)
    {
        int w,v,c ; scanf("%d%d%d",&w,&v,&c) ;
        for(int i=0;i<w;i++) dq[i].clear() ;
        for(int j=0;j<maxn;j++)
        {
            if(j<w) { dq[j].push_front((P){j,dp[j]}) ; continue ; }
            int id=j%w ;
            while(dq[id].back().id+c*w<j) dq[id].pop_back() ;
            int tmp=dq[id].back().val+( (j-dq[id].back().id)/w*v ) ;
            while(!dq[id].empty() &&
                dq[id].front().val+(j-dq[id].front().id)/w*v
                <= dp[j]) dq[id].pop_front() ;
            dq[id].push_front((P){j,dp[j]}) ;
            dp[j]=max(dp[j],tmp) ;
        }
    }
    int t ; scanf("%d",&t) ;
    int ans=-INF ;
    for(int i=0;i<=t;i++) ans=max(ans,dp[i]) ;
    printf("%d\n",ans) ;
}
