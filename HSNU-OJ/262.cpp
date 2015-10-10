#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=100000+10 ;
struct P{int to,dis;};
vector<P> v[maxn] ;
int n ;

struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        if(val!=rhs.val) return val>rhs.val ;
        else return id>rhs.id ;
    }
};
priority_queue<Q> pq ;
int d[maxn],sec[maxn] ;
bool done[maxn] ;
void Dijkstra()
{
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        if(u.id==0) return ;

        for(int i=0;i<v[u.id].size();i++)
        {
            int newd=sec[u.id] + v[u.id][i].dis ;
            if(newd<=d[v[u.id][i].to])
            {
                sec[v[u.id][i].to]=d[v[u.id][i].to] ;
                d[v[u.id][i].to]=newd ;
                if(sec[v[u.id][i].to]!=INF)
                    pq.push((Q){v[u.id][i].to,sec[v[u.id][i].to]}) ;
            }
            else if(newd<=sec[v[u.id][i].to])
            {
                sec[v[u.id][i].to]=newd ;
                pq.push((Q){v[u.id][i].to,sec[v[u.id][i].to]}) ;
            }
        }
    }
}

main()
{
    int m,k ;
    scanf("%d%d%d",&n,&m,&k) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    for(int i=0;i<n;i++) d[i]=sec[i]=INF ;
    while(k--)
    {
        int x ; scanf("%d",&x) ;
        d[x]=sec[x]=0 ;
        pq.push((Q){x,0}) ;
    }
    Dijkstra() ;
    printf("%d\n",sec[0]) ;
}
