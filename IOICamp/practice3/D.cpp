#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

priority_queue<int> q[maxn] ;
int sum[maxn],id[maxn] ;
vector<int> v[maxn] ;
LL cost[maxn],val[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int p ; scanf("%d%lld%lld",&p,&cost[i],&val[i]) ;
            if(p) v[p].push_back(i) ;
            while(!q[i].empty()) q[i].pop() ;
            sum[i]=0 ;
        }

        LL ans=0LL ;
        for(int i=n;i>=1;i--)
        {
            if(v[i].empty())
            {
                if(cost[i]<=m)
                {
                    q[i].push(cost[i]) ;
                    sum[i]=cost[i] ;
                    ans=max(ans,val[i]) ;
                }
                id[i]=i ;
                continue ;
            }

            int ma=0 , mid ;
            for(auto j : v[i]) if((int)q[id[j]].size() > ma)
                ma = q[id[mid=j]].size() ;

            id[i]=id[mid] ;
            q[id[i]].push(cost[i]) ; sum[id[i]]+=cost[i] ;
            if(sum[id[i]]>m) sum[id[i]]-=q[id[i]].top() , q[id[i]].pop() ;

            for(auto j : v[i]) if(mid!=j)
            {
                while(!q[id[j]].empty())
                {
                    q[id[i]].push(q[id[j]].top()) ;
                    sum[id[i]]+= q[id[j]].top() ;
                    q[id[j]].pop() ;
                    if(sum[id[i]]>m)
                    {
                        sum[id[i]]-=q[id[i]].top() ;
                        q[id[i]].pop() ;
                    }
                }
            }
            ans=max(ans,((LL)q[id[i]].size()) * val[i] ) ;
        }
        printf("%lld\n",ans) ;
    }
}
