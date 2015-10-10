#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=300000+10 ;

struct P{int x,y,dis ;};
vector<P> E ;
vector<int> v[maxn] ;

struct Q
{
    int id ; LL val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};

priority_queue<Q> pq ;
LL d[maxn] ;
bool done[maxn] ;
int n ;
void Dijkstra(int st)
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id])
        {
            P &e=E[i] ;
            int to= e.x==u.id ? e.y : e.x ;
            if(d[to]>d[u.id]+e.dis)
                d[to]=d[u.id]+e.dis , pq.push((Q){to,d[to]}) ;
        }
    }
}

bool ok[maxn] ;
vector<int> ans ;
main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        E.push_back((P){x,y,dis}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    int st ; scanf("%d",&st) ;
    Dijkstra(st) ;

    LL tot=0LL ;
    for(int i=1;i<=n;i++) if(i!=st)
    {
        LL mi=INF ;
        int id ;
        for(auto j : v[i])
        {
            P &e=E[j] ;
            int from=(e.x==i ? e.y : e.x) ;
            if(d[i]==d[from]+e.dis && e.dis<mi) mi=e.dis , id=j ;
        }
        ans.push_back(id) ;
        tot+=mi ;
    }

    printf("%I64d\n",tot) ;
    for(int i=0;i<n-1;i++) printf("%d%c",ans[i]+1,i+2==n?'\n':' ') ;
}
