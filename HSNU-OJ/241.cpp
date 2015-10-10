#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100001 ;

priority_queue<int> pq[maxn] ;
vector<int> v[maxn] ;
int id[maxn],cost[maxn],val[maxn] ;
LL sum[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d%d%d",&x,&cost[i],&val[i]) ;
        if(x) v[x].push_back(i) ;
    }
    for(int i=1;i<=n;i++)
    {
        id[i]=i ;
        if(cost[i]<=m) pq[i].push(cost[i]) , sum[i]=cost[i] ;
    }

    LL ans=0LL ;
    for(int i=n;i>=1;i--)
    {
        if(v[i].empty()) { ans=max(ans,(LL)val[i]) ; continue ; }
        int M=0,Mid ;
        for(int j=0;j<v[i].size();j++) if(pq[id[v[i][j]]].size()>M)
            M=pq[Mid=id[v[i][j]]].size() ;
        id[i]=Mid ;

        pq[id[i]].push(cost[i]) ; sum[id[i]]+=cost[i] ;
        if(sum[id[i]]>m) sum[id[i]]-=pq[id[i]].top() , pq[id[i]].pop() ;
        for(int j=0;j<v[i].size();j++) if(id[v[i][j]]!=Mid)
        {
            while(!pq[id[v[i][j]]].empty())
            {
                pq[id[i]].push(pq[id[v[i][j]]].top()) ;
                sum[id[i]]+=pq[id[v[i][j]]].top() ;
                pq[id[v[i][j]]].pop() ;
                if(sum[id[i]]>m) { sum[id[i]]-=pq[id[i]].top() ; pq[id[i]].pop() ; }
            }
        }
        ans=max(ans,((LL)val[i])*((LL)pq[id[i]].size())) ;
    }
    printf("%lld\n",ans) ;
}
