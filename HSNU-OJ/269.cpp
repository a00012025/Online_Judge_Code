//#define NDEBUG
#ifdef NDEBUG
#define debugf(...) (void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=801 ;
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;
char G[maxn][maxn] ;
int S,n ;

queue<int> q ;
int lev[maxn][maxn] ;
bool vis[maxn][maxn] ;
void pre_BFS()
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        if(G[i][j]=='H') q.push(i*n+j) , vis[i][j]=1 ;
        if(G[i][j]=='T' || G[i][j]=='D') lev[i][j]=INF ;
    }
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        int x=u/n , y=u%n ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny]) continue ;
            char c=G[nx][ny] ;
            if(c=='T' || c=='D') continue ;
            vis[nx][ny]=1 ; lev[nx][ny]=lev[x][y]+1 ;
            q.push(nx*n+ny) ;
        }
    }
}

vector<int> v[maxn*maxn] ;
void build_graph()
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(G[i][j]!='T')
    {
        int x=i*n+j ;
        for(int z=0;z<4;z++)
        {
            int ni=i+dx[z] , nj=j+dy[z] ;
            if(ni<0 || ni>=n || nj<0 || nj>=n || G[ni][nj]=='T') continue ;
            v[x].push_back(n*ni+nj) ;
        }
    }
}

struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        if(dis!=rhs.dis) return dis>rhs.dis ;
        else return id>rhs.id ;
    }
};
priority_queue<Q> pq ;
int d[maxn*maxn] ;
bool done[maxn*maxn] ;
bool check(int t,int st,int ed)
{
    if(t>=lev[st/n][st%n]) return 0 ;
    for(int i=0;i<n*n;i++) d[i]=INF ; d[st]=0 ;
    while(!pq.empty()) pq.pop() ;
    memset(done,0,sizeof(done)) ;
    pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id==ed) return 1 ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            int to=v[u.id][i] ;
            if( (d[u.id]+1)/S + t >= lev[to/n][to%n] ) continue ;
            if(d[to]>d[u.id]+1)
            {
                d[to]=d[u.id]+1 ;
                pq.push((Q){to,d[to]}) ;
            }
        }
    }
    return 0 ;
}

main()
{
    scanf("%d%d",&n,&S) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;

    pre_BFS() ;
    build_graph() ;

    int st,ed ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        if(G[i][j]=='M') st=i*n+j ;
        else if(G[i][j]=='D') ed=i*n+j ;
    }

    int l=-1 , r=n*n ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid,st,ed)) l=mid ;
        else r=mid ;
    }
    printf("%d\n",l) ;
}
