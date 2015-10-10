#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=1000+10 ;

int a[maxn],b[maxn],dp[4000] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]) , a[i]/=1000 ;
        for(int i=0;i<=2*n;i++) dp[i]=INF ; dp[0]=0 ;
        for(int i=1;i<=n;i++) for(int j=2*n;j>=0;j--)
            dp[j]= j>=a[i] ? min(dp[j]+b[i],dp[j-a[i]]) : dp[j]+b[i] ;

        for(int i=1;;i++) if(dp[i]<=1000*i)
            { printf("%d\n",1000*i) ; break ; }
    }
}
