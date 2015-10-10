#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int to,dis;
    bool operator < (const P &rhs) const
    {
        return to==rhs.to ? dis<rhs.dis : to<rhs.to ;
    }
};
vector<P> v[maxn],v0[maxn] ;

struct Q
{
    int id ; LL dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};
priority_queue<Q> pq ;
LL d[maxn] ;
bool done[maxn] ;

void Dijkstra(int st)
{
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i.to]>d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[y].push_back((P){x,dis}) ;
        v0[x].push_back((P){y,dis}) ;
    }
    fill(d+1,d+n+2,INF) ;
    Dijkstra(n+1) ;
    if(d[1]==INF) printf("fuck\n") ;
    else
    {
        printf("%lld\n",d[1]) ;
        printf("1") ;
        for(int i=1;i!=n+1;)
        {
            sort(v0[i].begin(),v0[i].end()) ;
            for(auto j : v0[i]) if(d[j.to]+j.dis==d[i])
                { printf("-%d",j.to) ; i=j.to ; break ; }
        }
    }
    printf("\n") ;
}
