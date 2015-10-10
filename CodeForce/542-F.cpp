#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

struct P
{
    int x,val ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? val<rhs.val : x>rhs.x ;
    }
};

priority_queue<P> pq ;

main()
{
    int n,T ; scanf("%d%d",&n,&T) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        pq.push((P){x,y}) ;
    }

    int ans=0 ;
    while(pq.size()>1)
    {
        P p=pq.top() ; pq.pop() ;
        P q=pq.top() ; pq.pop() ;
        if(p.x!=q.x)
        {
            pq.push((P){q.x,p.val}) ;
            pq.push(q) ;
            continue ;
        }
        ans=max(ans,max(p.val,q.val)) ;
        if(p.x==T || q.x==T) break ;
        pq.push((P){p.x+1,p.val+q.val}) ;
    }
    while(!pq.empty()) ans=max(ans,pq.top().val) , pq.pop() ;
    printf("%d\n",ans) ;
}
