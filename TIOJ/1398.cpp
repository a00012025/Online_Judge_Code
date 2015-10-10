#include<bits/stdc++.h>
#define LL long long
using namespace std;

priority_queue<LL,vector<LL>,greater<LL> > pq ;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        while(!pq.empty()) pq.pop() ;
        while(n--)
        {
            LL x ; scanf("%lld",&x) ;
            pq.push(x) ;
        }
        LL ans=0LL ;
        while(pq.size()>=4)
        {
            if(pq.size()%2==0)
            {
                LL x=pq.top() ; pq.pop() ;
                LL y=pq.top() ; pq.pop() ;
                ans+=x+y ; pq.push(x+y) ;
                continue ;
            }

            LL x=pq.top() ; pq.pop() ;
            LL y=pq.top() ; pq.pop() ;
            LL z=pq.top() ; pq.pop() ;
            ans+=x+y+z ; pq.push(x+y+z) ;
        }
        while(!pq.empty()) ans+=pq.top() , pq.pop() ;
        printf("%lld\n",ans) ;
    }
}
