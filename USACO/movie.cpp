#include<bits/stdc++.h>
using namespace std;
const int maxn=20+1 ;

vector<int> v[maxn] ;
int t[maxn],dp[1<<maxn] ;
main()
{
    if(fopen("movie.in","r"))
    {
        freopen("movie.in","r",stdin) ;
        freopen("movie.out","w",stdout) ;
    }

    int n,L ; scanf("%d%d",&n,&L) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]) ;
        int k ; scanf("%d",&k) ;
        while(k--)
        {
            int x ; scanf("%d",&x) ;
            v[i].push_back(x) ;
        }
    }

    int ans=n+1 ;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++) if(i&(1<<j))
        {
            int id=upper_bound(v[j].begin(),v[j].end(),dp[i^(1<<j)])
                    -v[j].begin()-1 ;
            if(id>=0) dp[i]=max(dp[i],max(dp[i^(1<<j)],v[j][id]+t[j])) ;
        }
        if(dp[i]>=L) ans=min(ans,__builtin_popcount(i)) ;
    }
    printf("%d\n",ans==n+1?-1:ans) ;
}
