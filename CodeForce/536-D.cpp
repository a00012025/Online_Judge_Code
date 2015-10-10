#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=2000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;

struct Q
{
    int id ; LL dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};

priority_queue<Q> pq ;
bool done[maxn] ;
void Dijkstra(int st,LL *d)
{
    fill(d,d+maxn,INF) ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    memset(done,0,sizeof(done)) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto i : v[u.id]) if(d[i.to]>d[u.id]+i.dis)
            d[i.to]=d[u.id]+i.dis , pq.push((Q){i.to,d[i.to]}) ;
    }
}

LL d1[maxn],d2[maxn] ;
vector<LL> vx,vy ;

LL S(int x1,int y1,int x2,int y2,LL a[maxn][maxn])
{
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1] ;
}

int w[maxn] ;
LL sum[maxn][maxn] ;
LL dp1[maxn][maxn],dp2[maxn][maxn],val[maxn][maxn] ;
LL mix[maxn] ;
int nowx[maxn] ;

main()
{
    int n,m,s,e ; scanf("%d%d%d%d",&n,&m,&s,&e) ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    Dijkstra(s,d1) ;
    Dijkstra(e,d2) ;
    for(int i=1;i<=n;i++) vx.push_back(d1[i]) , vy.push_back(d2[i]) ;
    sort(vx.begin(),vx.end()) ;
    sort(vy.begin(),vy.end()) ;
    vx.resize(unique(vx.begin(),vx.end())-vx.begin()) ;
    vy.resize(unique(vy.begin(),vy.end())-vy.begin()) ;
    int sx=vy.size() , sy=vx.size() ;

    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(vx.begin(),vx.end(),d1[i])-vx.begin()+1 ;
        int y=lower_bound(vy.begin(),vy.end(),d2[i])-vy.begin()+1 ;
        val[y][x]=1 ; sum[y][x]+=w[i] ;
    }
    for(int i=1;i<=sx;i++) for(int j=1;j<=sy;j++)
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j] ,
        val[i][j]=val[i-1][j]+val[i][j-1]-val[i-1][j-1]+val[i][j] ;

    for(int i=1;i<=sy;i++) mix[i]=INF , nowx[i]=sx ;

    LL miy=INF ;
    for(int i=sx;i>=1;i--) for(int j=sy,nowy=sy;j>=1;j--)
    {
        if(j==sy) miy=INF ;
        if(S(i,j,sx,j,val)) while(nowy>=j)
        {
            miy=min(miy,dp2[i][nowy+1]) ;
            nowy-- ;
        }
        if(S(i,j,i,sy,val)) while(nowx[j]>=i)
        {
            mix[j]=min(mix[j],dp1[nowx[j]+1][j]) ;
            nowx[j]-- ;
        }

        if(miy!=INF) dp1[i][j]=S(i,j,sx,sy,sum)-miy ;
        if(mix[j]!=INF) dp2[i][j]=S(i,j,sx,sy,sum)-mix[j] ;
    }

    LL ans=dp1[1][1] , all=S(1,1,sx,sy,sum) ;
    if(2*ans==all) printf("Flowers\n") ;
    else if(2*ans<all) printf("Cry\n") ;
    else printf("Break a heart\n") ;
}
