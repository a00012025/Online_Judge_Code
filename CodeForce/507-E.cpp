#include<bits/stdc++.h>
#define INF 10000000
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 ;
struct P{int from,to,tp;};
vector<P> edge ;
vector<int> v[maxn] ;

struct Q
{
    int id ;
    pii dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
} ;
priority_queue<Q> pq ;
int fa[maxn] ;
pii d[maxn] ;
bool done[maxn],used[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++)
    {
        int x,y,tp ; scanf("%d%d%d",&x,&y,&tp) ;
        edge.push_back((P){x,y,tp}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }

    for(int i=2;i<=n;i++) d[i]=mkp(INF,INF) ;
    d[1]=mkp(0,0) ; pq.push((Q){1,d[1]}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            int to= edge[v[u.id][i]].to==u.id ?
                edge[v[u.id][i]].from : edge[v[u.id][i]].to ;
            int sec= edge[v[u.id][i]].tp ? d[u.id].S-1 : d[u.id].S+1 ;
            if(d[to] > mkp(d[u.id].F+1,sec))
            {
                d[to] = mkp(d[u.id].F+1,sec) ;
                pq.push((Q){to,d[to]}) ;
                fa[to]=v[u.id][i] ;
            }
        }
    }

    int cnt=0 ;
    for(int i=0;i<m;i++) if(edge[i].tp) cnt++ ;
    printf("%d\n",cnt+d[n].S) ;

    for(int i=n;i!=1;)
    {
        used[fa[i]]=1 ;
        i= edge[fa[i]].to==i ? edge[fa[i]].from : edge[fa[i]].to ;
    }
    for(int i=0;i<m;i++)
    {
        if(used[i] && !edge[i].tp) printf("%d %d 1\n",edge[i].from,edge[i].to) ;
        if(!used[i] && edge[i].tp) printf("%d %d 0\n",edge[i].from,edge[i].to) ;
    }
}
