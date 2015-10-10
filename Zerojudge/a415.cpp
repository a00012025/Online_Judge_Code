#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define MKP(x,y) make_pair(x,y)
using namespace std;

struct P
{
    int ed,dis ;
    bool operator < (const P &rhs) const
    {
        return dis>rhs.dis ;
    }
};

vector<P> v[300] ;
map<pair<int,int>,int> mp ;
int inv[200],cnt ;
int tlst[300],tled[300],trst[300],tred[300] ;
int d[300] ;
const int INF=10000000 ;

bool done[300] ;
int dijkstra(int t0,int st,int ed)
{
    memset(done,0,sizeof(done)) ;
    for(int i=0;i<300;i++) d[i]=INF ;
    priority_queue<P> pq ;
    pq.push((P){st,t0}) ; d[st]=t0 ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ; debugf("u : %d , %d\n",u.ed,u.dis) ;
        if(u.ed==ed) return u.dis ;
        if(done[u.ed]) continue ;
        done[u.ed]=1 ;
        for(int i=0;i<v[u.ed].size();i++)
        {
            int u2=v[u.ed][i].ed , dis2=v[u.ed][i].dis ;
            debugf("u2=%d , dis2=%d\n",u2,dis2) ;
            if(u2==u.ed+1 && dis2!=0)
            {
                int t2= u.dis<=trst[u.ed]-5 ?
                    trst[u.ed] : trst[u.ed]+((u.dis+5-trst[u.ed]-1)/5)*5 ;
                if(t2>tred[u.ed]) continue ;
                if(d[u2] > t2+1+dis2)
                {
                    d[u2]=t2+1+dis2 ;
                    pq.push((P){u2,t2+1+dis2}) ;
                }
            }
            else if(u2==u.ed-1 && dis2!=0)
            {
                int t2= u.dis<=tlst[u.ed]-5 ?
                    tlst[u.ed] : tlst[u.ed]+((u.dis+5-tlst[u.ed]-1)/5)*5 ;
                if(t2>tled[u.ed]) continue ;
                if(d[u2] > t2+1+dis2)
                {
                    d[u2]=t2+1+dis2 ;
                    pq.push((P){u2,t2+1+dis2}) ;
                }
            }
            else if(dis2==0)
            {
                if(d[u2] > d[u.ed])
                {
                    d[u2]=d[u.ed] ;
                    pq.push((P){u2,d[u.ed]}) ;
                }
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
                trst[mp[MKP(i,j)]]= j==1 ? 360 : trst[mp[MKP(i,j-1)]]+tmp[j]+1 ;
                tred[mp[MKP(i,j)]]= j==1 ? 1435 : tred[mp[MKP(i,j-1)]]+tmp[j]+1 ;
                if(j!=k) v[mp[MKP(i,j)]].push_back((P){mp[MKP(i,j+1)],tmp[j+1]}) ;
                if(j!=1) v[mp[MKP(i,j)]].push_back((P){mp[MKP(i,j-1)],tmp[j]}) ;
            }
            for(int j=k;j>=1;j--)
            {
                tlst[mp[MKP(i,j)]]= j==k ? 360 : tlst[mp[MKP(i,j+1)]]+tmp[j+1]+1 ;
                tled[mp[MKP(i,j)]]= j==k ? 1435 : tled[mp[MKP(i,j+1)]]+tmp[j+1]+1 ;
            }
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c,d ; scanf("%d%d%d%d",&a,&b,&c,&d) ;
            a=inv[a] ; c=inv[c] ;
            v[mp[MKP(a,b)]].push_back((P){mp[MKP(c,d)],0}) ;
            v[mp[MKP(c,d)]].push_back((P){mp[MKP(a,b)],0}) ;
            debugf("dis=0 : %d <-> %d\n",mp[MKP(a,b)],mp[MKP(c,d)]) ;
        }
        for(int i=1;i<=5;i++)
        {
            int h,m,st1,st2,ed1,ed2 ;
            scanf("%d%d%d%d%d%d",&h,&m,&st1,&st2,&ed1,&ed2) ;
            int st=mp[MKP(inv[st1],st2)] , ed=mp[MKP(inv[ed1],ed2)] ;
            int t0=60*h+m ;
            debugf("st=%d , ed=%d\n",st,ed) ;
            printf("%d\n",dijkstra(t0,st,ed)-t0) ;
        }
    }
}
