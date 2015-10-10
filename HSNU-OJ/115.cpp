#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=100000+10 ;
struct P{int ed,dis;};
vector<P> v[maxn] ;

int d[maxn],n ;

void SPFA(int st)
{
    for(int i=1;i<=n;i++) d[i]=INF ;
    d[st]=0 ;
    queue<int> q ; q.push(st) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(int i=0;i<v[u].size();i++) if(d[v[u][i].ed] > d[u]+v[u][i].dis)
        {
            d[v[u][i].ed] = d[u]+v[u][i].dis ;
            q.push(v[u][i].ed) ;
        }
    }
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    SPFA(1) ;
    int M=-1 , id ;
    for(int i=1;i<=n;i++) if(d[i]>M) M=d[id=i] ;

    SPFA(id) ;
    double N=-1.0 ;
    for(int i=1;i<=n;i++) if(d[i]>N) N=d[id=i] ;
    printf("%.1f\n",N/2) ;
}
