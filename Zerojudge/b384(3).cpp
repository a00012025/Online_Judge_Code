#include<bits/stdc++.h>
#define LL long long
#define INF 100000000000LL
using namespace std;
const int maxn=1000000+10 ;
struct P
{
    int id ; LL val ;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
};

LL c[60] ;
LL d[maxn] ;
bool done[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,Q ; LL C=INF ;
        scanf("%d%d",&n,&Q) ;
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]) , C=min(C,c[i]) ;

        fill(d,d+C,INF);
        memset(done,0,sizeof(done)) ;
        d[0]=0 ;
        priority_queue<P> pq ;
        pq.push((P){0,0}) ;
        while(!pq.empty())
        {
            P u=pq.top() ; pq.pop() ;
            if(done[u.id]) continue ;
            done[u.id]=1 ;
            for(int i=1;i<=n;i++)
            {
                LL val= d[u.id]+c[i] ;
                int id=val%C ;
                if(val < d[id])
                {
                    d[id]=val ;
                    pq.push((P){id,val}) ;
                }
            }
        }

        while(Q--)
        {
            LL p ; scanf("%lld",&p) ;
            if(d[p%C] > p) putchar('N') ;
            else putchar('Y') ;
        }
        printf("\n") ;
    }
}
