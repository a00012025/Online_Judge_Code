#include<bits/stdc++.h>
using namespace std;
struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};
priority_queue<P> pq ;
main()
{
    int n ; scanf("%d",&n) ;
    int ans=0 , L=0 ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        while(!pq.empty() && pq.top().val>y)
        {
            L=max(L,pq.top().id) ;
            pq.pop() ;
        }
        ans=max(ans,i-L) ;
        pq.push((P){i,x}) ;
    }
    printf("%d\n",ans) ;
}
