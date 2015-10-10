#include<bits/stdc++.h>
#define LL long long
using namespace std;

map<LL,LL> mp ;
vector<LL> v ;
main()
{
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        LL x,y,k ;
        scanf("%lld%lld%lld",&x,&y,&k) ;
        mp[x*x+y*y]+=k ;
    }
    for(auto it : mp) v.push_back(it.second) ;
    LL ans=0LL,mi=0LL,sum=0LL ;
    for(auto i : v)
    {
        sum+=i ;
        ans=max(ans,sum-mi) ;
        mi=min(mi,sum) ;
    }
    printf("%lld\n",ans) ;
}
