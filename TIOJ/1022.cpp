#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=200 ;
int G[maxn][maxn] ;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
vector<int> v[maxn*maxn] ;

struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

priority_queue<Q> pq ;
int d[maxn*maxn],n,m ;
bool done[maxn*maxn] ;
int Dijkstra(int st,int ed)
{
    while(!pq.empty()) pq.pop() ;
    for(int i=0;i<m*n;i++) d[i]=INF ;
    memset(done,0,sizeof(done)) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id==ed) return u.dis ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i]>d[u.id]+1)
        {
            d[i]=d[u.id]+1 ;
            pq.push((Q){i,d[i]}) ;
        }
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            scanf("%d",&G[i][j]) ;
        for(int i=0;i<m*n;i++) v[i].clear() ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            int x=m*i+j ;
            for(int z=0;z<4;z++)
            {
                int nx=i+dx[z] , ny=j+dy[z] ;
                if(nx<0||nx>=n||ny<0||ny>=m) continue ;
                if(G[nx][ny]>G[i][j]+5 || G[i][j]>G[nx][ny]+5) continue ;
                v[x].push_back(nx*m+ny) ;
            }
        }
        printf("%d\n",Dijkstra(0,m*n-1)) ;
    }
}
