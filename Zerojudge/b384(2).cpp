#include<bits/stdc++.h>
#define LL long long
#define INF 100000000000LL
using namespace std;
const int maxn=1000000+10 ;

deque<int> dq ;
LL c[60] ;
LL d[maxn] ;
bool done[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,Q ; LL C=-1 ;
        scanf("%d%d",&n,&Q) ;
        for(int i=1;i<=n;i++) scanf("%lld",&c[i]) , C=max(C,c[i]) ;

        for(int i=0;i<C;i++) d[i]=INF , done[i]=0 ;
        d[0]=0LL ;
        while(!dq.empty()) dq.pop_front() ; dq.push_front(0) ;
        while(!dq.empty())
        {
            int u=dq.front() ; dq.pop_front() ;
            if(done[u]) continue ;
            done[u]=1 ;
            for(int i=1;i<=n;i++)
            {
                LL val=C*d[u]+u+c[i] ;
                int id=val%C ;
                if(d[id] > (val/C))
                {
                    d[id]=val/C ;
                    if(val/C > d[u]) dq.push_back(id) ;
                    else dq.push_front(id) ;
                }
            }
        }
        while(Q--)
        {
            LL p ; scanf("%lld",&p) ;
            if(d[p%C]==INF || (d[p%C]*C+(p%C) > p)) printf("N") ;
            else printf("Y") ;
        }
        printf("\n") ;
    }
}

