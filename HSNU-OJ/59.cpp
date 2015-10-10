#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
struct P{int ed,dis ;};
struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};

vector<P> v[5001] ;
int n,d1[5001],d2[5001],done[5001] ;
void dijkstra(int st)
{
    priority_queue<Q> pq ;
    for(int i=1;i<=n;i++) d1[i]=d2[i]=INF ;
    d1[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]>=2) continue ;
        done[u.id]++ ;
        for(int i=0;i<v[u.id].size();i++)
        {
            int newd1=d1[u.id]+v[u.id][i].dis ;
            int newd2=d2[u.id]+v[u.id][i].dis ;
            if(newd1<d1[v[u.id][i].ed])
            {
                d1[v[u.id][i].ed]=newd1 ;
                pq.push((Q){v[u.id][i].ed,newd1}) ;
            }
            else if(newd1>d1[v[u.id][i].ed] && newd1<d2[v[u.id][i].ed])
            {
                d2[v[u.id][i].ed]=newd1 ;
                pq.push((Q){v[u.id][i].ed,newd1}) ;
            }
            if(newd2<d2[v[u.id][i].ed])
            {
                d2[v[u.id][i].ed]=newd2 ;
                pq.push((Q){v[u.id][i].ed,newd2}) ;
            }
        }
    }
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y,z ; scanf("%d%d%d",&x,&y,&z) ;
        v[x].push_back((P){y,z}) ;
        v[y].push_back((P){x,z}) ;
    }
    dijkstra(1) ;
    printf("%d\n",d2[n]==INF ? 0 : d2[n]) ;
}
