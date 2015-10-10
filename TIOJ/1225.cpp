#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
};

int a[maxn],ri[maxn],le[maxn] ;
priority_queue<P> pq ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) ,
        le[i]=i-1 , ri[i]=i+1 ,
        pq.push((P){i,a[i]}) ;
    LL ans=0LL ;
    while(pq.size()>1)
    {
        P u=pq.top() ; pq.pop() ;
        if(!le[u.id]) { ans+=a[ri[u.id]] ; le[ri[u.id]]=0 ; continue ; }
        if(ri[u.id]==n+1) { ans+=a[le[u.id]] ; ri[le[u.id]]=n+1 ; continue ; }
        ans+=min(a[le[u.id]],a[ri[u.id]]) ;
        le[ri[u.id]]=le[u.id] ;
        ri[le[u.id]]=ri[u.id] ;
    }
    printf("%lld\n",ans) ;
}
