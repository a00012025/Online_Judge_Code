#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define MKP(x,y) make_pair(x,y)
using namespace std;

struct P{int ed,dis ;};
struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

vector<P> v[300] ;
map<pair<int,int>,int> mp ;
int inv[200],cnt ;
int d[300] ;
const int INF=10000000 ;

bool done[300] ;
int dijkstra(int st,int ed)
{
    memset(done,0,sizeof(done)) ;
    for(int i=0;i<300;i++) d[i]=INF ;
    priority_queue<Q> pq ;
    pq.push((Q){st,0}) ; d[st]=0 ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id == ed) return u.dis ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].ed] > d[u.id] + v[u.id][i].dis)
            {
                d[v[u.id][i].ed] = d[u.id] + v[u.id][i].dis ;
                pq.push((Q){v[u.id][i].ed,d[u.id] + v[u.id][i].dis}) ;
            }
        }
    }
}

main()
{
    int n,m;
    int tmp[30] ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<300;i++) v[i].clear() ;
        mp.clear() ; cnt=0 ;
        for(int i=1;i<=n;i++)
        {
            int id ; scanf("%d",&id) ; inv[id]=i ;
            int k ; scanf("%d",&k) ;
            for(int j=1;j<=k;j++) mp[MKP(i,j)]=++cnt ;
            for(int j=1;j<=k;j++) scanf("%d",&tmp[j]) ;
            for(int j=1;j<=k;j++)
            {
                if(j!=k) v[mp[MKP(i,j)]].push_back((P){mp[MKP(i,j+1)],tmp[j+1]+1}) ;
                if(j!=1) v[mp[MKP(i,j)]].push_back((P){mp[MKP(i,j-1)],tmp[j]+1}) ;
            }
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c,d ; scanf("%d%d%d%d",&a,&b,&c,&d) ;
            a=inv[a] ; c=inv[c] ;
            v[mp[MKP(a,b)]].push_back((P){mp[MKP(c,d)],0}) ;
            v[mp[MKP(c,d)]].push_back((P){mp[MKP(a,b)],0}) ;
        }
        for(int i=1;i<=5;i++)
        {
            int h,m,st1,st2,ed1,ed2 ;
            scanf("%d%d%d%d%d%d",&h,&m,&st1,&st2,&ed1,&ed2) ;
            int st=mp[MKP(inv[st1],st2)] , ed=mp[MKP(inv[ed1],ed2)] ;
            printf("%d\n",dijkstra(st,ed)) ;
        }
    }
}
