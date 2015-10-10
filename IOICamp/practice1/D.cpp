#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=50000+10 ;

LL dp[maxn],dp2[maxn] ;
int num[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,V ; scanf("%d%d",&n,&V) ;
        memset(dp,0,sizeof(dp)) ;
        while(n--)
        {
            int w,p,k ; scanf("%d%d%d",&w,&p,&k) ;
            if(k==1) continue ;
            if(k==2)
            {
                for(int z=V-2*w;z>=0;z--) dp[z+2*w]=max(dp[z+2*w],dp[z]+2*p) ;
                continue ;
            }

            fill(num,num+V+1,0) ;
            int x=1 ;
            while(x<=k) x=x*2+1 ; x=(x-1)/2 ;

            vector<int> tmp ;
            if(x<k) tmp.push_back(k-x) ;
            for(int j=2;j<x;j*=2) tmp.push_back(j) ;
            sort(tmp.begin(),tmp.end()) ;

            fill(dp2,dp2+V+1,-INF) ;
            for(auto j : tmp)
            {
                int w2=j*w , p2=j*p ;
                for(int z=V-w2;z>=0;z--)
                {
                    if(dp2[z]+p2 >= dp2[z+w2])
                    {
                        dp2[z+w2]=dp2[z]+p2 ;
                        num[z+w2]=num[z]+j ;
                    }
                    if(dp[z]+p2 >= dp2[z+w2])
                    {
                        dp2[z+w2]=dp[z]+p2 ;
                        num[z+w2]=j ;
                    }
                }
            }

            for(int i=V-w;i>=0;i--)
            {
                if(num[i+w]>1) dp[i+w]=max(dp[i+w],dp2[i+w]) ;
                if(num[i]>1) dp[i+w]=max(dp[i+w],dp2[i]+p) ;
            }
        }

        LL ans=0LL ;
        for(int i=0;i<=V;i++) ans=max(ans,dp[i]) ;
        printf("%lld\n",ans) ;
    }
}

