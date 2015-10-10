#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=2000+5 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
}p[maxn];

int a[maxn][maxn],dp[maxn],per[maxn] ;

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&p[i].val) , p[i].id=i ;
    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) per[p[i].id]=i ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[per[i]][j]) ;

    fill(dp,dp+n+1,-INF) ; dp[0]=0 ;
    for(int i=1;i<=n;i++) for(int j=n;j>=1;j--)
        dp[j]=max(dp[j],dp[j-1]+a[i][j]) ;
    for(int i=0;i<=n;i++) if(dp[i]>=k)
        { printf("%d\n",i) ; return 0 ; }
    printf("-1\n");
}
