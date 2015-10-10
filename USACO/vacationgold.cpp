#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
using namespace std;
const int maxn=20000+10,maxk=200+10 ;

struct P{int to,dis;};
struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};

priority_queue<Q> pq ;
vector<P> v[maxn] ;
int n ;
bool done[maxn] ;

void Dijkstra(int st,int *d)
{
    while(!pq.empty()) pq.pop() ;
    memset(done,0,sizeof(done)) ;
    fill(d+1,d+n+1,INF) ; d[st]=0 ;
    pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i.to] > d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

int d[maxk][maxn] ;
vector<int> K ;
bool hub[maxn] ;

main()
{
    freopen("vacationgold.in","r",stdin) ;
    freopen("vacationgold.out","w",stdout) ;
    int m,k,Q ; scanf("%d%d%d%d",&n,&m,&k,&Q) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
    }
    while(k--)
    {
        int x ; scanf("%d",&x) ;
        hub[x]=1 ; K.push_back(x) ;
    }
    sort(K.begin(),K.end()) ;

    for(int i=0;i<K.size();i++) Dijkstra(K[i],d[i]) ;

    LL ans1=0LL , ans2=0LL ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(hub[x])
        {
            int id=lower_bound(K.begin(),K.end(),x)-K.begin() ;
            if(d[id][y]!=INF) ans1++ , ans2+=d[id][y] ;
        }
        else
        {
            int ans=INF ;
            for(auto i : v[x])
            {
                int id=lower_bound(K.begin(),K.end(),i.to)-K.begin() ;
                ans=min(ans,i.dis+d[id][y]) ;
            }
            if(ans!=INF) ans1++ , ans2+=ans ;
        }
    }
    printf("%lld\n%lld\n",ans1,ans2) ;
}
