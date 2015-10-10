#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=5000+10 ;

LL dp[maxn],sum[maxn] ;
vector<int> v ;
map<LL,int> mp ;
main()
{
    int n,k,MOD ;
    while(scanf("%d%d%d",&n,&k,&MOD)!=EOF)
    {
        mp.clear() ; v.clear() ;
        while(n--)
        {
            LL x ; scanf("%lld",&x) ;
            mp[x]++ ;
        }
        for(auto it : mp) v.push_back(it.second) ;
        memset(dp,0,sizeof(dp)) ; dp[0]=1LL ;
        for(auto i : v)
        {
            for(int j=0;j<=k;j++) sum[j]= j ? (sum[j-1]+dp[j])%MOD : dp[0] ;
            for(int j=0;j<=k;j++)
            {
                int lo=max(0,j-i) ;
                int hi=j ;
                if(lo==0) dp[j]=sum[hi] ;
                else dp[j]=(((sum[hi]-sum[lo-1])%MOD)+MOD)%MOD ;
            }
        }
        printf("%lld\n",dp[k]) ;
    }
}
