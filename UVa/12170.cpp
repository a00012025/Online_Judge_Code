#include<stdio.h>
#include<deque>
#include<map>
#include<algorithm>
#define LL long long
#define INF (1LL<<60)
using namespace std;
struct P{int id ; LL val ;};
map<LL,int> mp ;
deque<P> dq ;
LL a[101],p[30000],dp[101][30000] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; LL d ;
        scanf("%d%lld",&n,&d) ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        if(abs(a[n]-a[1])>((LL)n-1)*d)
            {printf("impossible\n") ; continue ;}
        mp.clear() ;
        for(int i=1;i<=n;i++) for(int j=-n;j<=n;j++)
            mp[a[i]+((LL)j)*d]++ ;
        int m=0 ;
        for(map<LL,int>::iterator it=mp.begin();it!=mp.end();it++)
            p[++m]=it->first ;
        for(int i=1;i<=m;i++) dp[1][i]= p[i]==a[1] ? 0 : INF ;
        for(int i=2;i<n;i++)
        {
            while(!dq.empty()) dq.pop_front() ;
            dq.push_front((P){1,dp[i-1][1]}) ;
            int now=2 ;
            for(int j=1;j<=m;j++)
            {
                while(!dq.empty() && p[dq.back().id]+d<p[j])
                    dq.pop_back() ;
                for(;now<=m && p[now]<=p[j]+d;now++)
                {
                    while(!dq.empty() && dq.front().val>=dp[i-1][now])
                        dq.pop_front() ;
                    dq.push_front((P){now,dp[i-1][now]}) ;
                }
                //printf("j=%d , now=%d\n",j,now) ;
                if(dq.back().val!=INF) dp[i][j]=dq.back().val+abs(p[j]-a[i]);
                else dp[i][j]=INF ;
                //if(dp[i][j]!=INF) printf("dp[%d][%d]=%I64d\n",i,j,dp[i][j]) ;
            }
        }
        LL ans=INF ;
        for(int i=1;i<=m;i++) if(abs(p[i]-a[n])<=d && dp[n-1][i]!=INF)
            ans=min(ans,dp[n-1][i]) ;
        printf("%lld\n",ans) ;
    }
}
