#include<bits/stdc++.h>
#define INF 2000000000
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=3000+10 ;

int dp[maxn][maxn] ;
deque<pii> dq ;
pii a[maxn] ;
main()
{
    int n,k,m,D ; scanf("%d%d%d%d",&n,&k,&m,&D) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    sort(a+1,a+n+1) ;

    for(int i=0;i<=n;i++) dp[0][i]=-INF ;
    dp[0][0]=0 ;
    for(int i=1;i<=k;i++)
    {
        while(!dq.empty()) dq.pop_front() ;
        dq.push_front(mkp(0,dp[i-1][0])) ;
        for(int j=1;j<=n;j++)
        {
            while(a[j].F - dq.back().F > D) dq.pop_back() ;
            dp[i][j]=a[j].S + dq.back().S ;
            while(!dq.empty() && dq.front().S <= dp[i-1][j])
                dq.pop_front() ;
            dq.push_front(mkp(a[j].F,dp[i-1][j])) ;
        }
    }
    int ans=0 ;
    for(int i=1;i<=n;i++) ans=max(ans,dp[k][i]) ;
    printf("%d\n",ans) ;
}
