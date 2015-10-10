#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
vector<int> pos ;
int sum[3000] ;
int w[3000],cost[3000] ;
LL dp[3000] ;

bool cmp(int x,int y)
{
    return x>y ;
}

main()
{
    int n,num=1 ; LL ans=0LL ;
    int cnt=0 ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x==0 && y>0) pos.push_back(y) ;
        if(x>0 && y>0) ans+=(LL)y , num+=x-1 ;
        if(x>=2 && y<=0) {cnt++ ; w[cnt]=x-1 ; cost[cnt]=-y ; }
    }
    sort(pos.begin(),pos.end(),cmp) ;
    sum[0]=0 ; for(int i=1;i<=pos.size();i++) sum[i]=sum[i-1]+pos[i-1] ;
    if(num>=pos.size()) { printf("%lld\n",ans+sum[pos.size()]) ; return 0 ; }
    for(int i=0;i<=num-1;i++) dp[i]=0LL ;
    for(int i=num;i<=pos.size();i++) dp[i]=INF ;
    for(int i=1;i<=cnt;i++) for(int j=pos.size()-1;j>=0;j--)
    {
        dp[j]=min(dp[j],dp[j+1]) ;
        if(j<=w[i]) dp[j]=min(dp[j],(LL)cost[i]) ;
        if(j>=w[i]) dp[j]=min(dp[j],(LL)dp[j-w[i]]+cost[i]) ;
        //printf("dp[%d]=%I64d\n",j,dp[j]) ;
    }
    LL add=0LL ;
    for(int i=0;i<pos.size();i++) add=max(add,sum[i+1]-dp[i]) ;
    printf("%lld\n",ans+add) ;
}
