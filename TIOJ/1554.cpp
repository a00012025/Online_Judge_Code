#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;
const int maxn=20+2 ;

DB dp[1<<maxn] ;
int a[maxn] ;
vector<int> v[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<(1<<n);i++)
        v[__builtin_popcount(i)].push_back(i) ;
    dp[0]=1LL ;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++) scanf("%d",&a[j]) ;
        for(auto j : v[i]) for(int k=0;k<n;k++)
            if(j&(1<<k)) dp[j]=max(dp[j],dp[j^(1<<k)]*a[k]/100.0) ;
    }
    DB ans=(dp[(1<<n)-1])*100.0 ;
    printf("%.2f\n",ans+1e-5) ;
}
