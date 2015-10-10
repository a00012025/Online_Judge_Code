#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int G1[501][501],G2[501][501],d1[501][501],d2[501][501] ;

struct P
{
    int x,y,val ;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
};


int find_in_v(int val,const vector<int> &v)
{
    int l=0 , r=v.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[mid]>=val) r=mid ;
        else l=mid ;
    }
    return r ;
}

int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;
bool done[501][501] ;
void dijkstra(int G[501][501],int h,int w,int stx,int sty,int d[501][501])
{
    memset(done,0,sizeof(done)) ;
    for(int i=1;i<=w;i++) for(int j=1;j<=h;j++) d[i][j]=INF ;
    d[stx][sty]=1 ;
    priority_queue<P> pq ; pq.push((P){stx,sty,1}) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ;
        int x=u.x , y=u.y , val=u.val ;
        if(done[x][y]) continue ;
        done[x][y]=1 ;
        for(int z=0;z<4;z++)
        {
            int nx=x+dx[z] , ny=y+dy[z] ;
            if(nx<1 || nx>w || ny<1 || ny>h) continue ;
            if(max(d[x][y],G[nx][ny])<d[nx][ny])
            {
                d[nx][ny]=max(d[x][y],G[nx][ny]) ;
                pq.push((P){nx,ny,d[nx][ny]}) ;
            }
        }
    }
}

vector<int> tmp1,tmp2 ;
int cnt1[250001],cnt2[250001] ;

main()
{
    int n ; scanf("%d",&n) ;
    int h1,w1,st1x,st1y ; scanf("%d%d%d%d",&h1,&w1,&st1x,&st1y) ;
    for(int i=1;i<=w1;i++) for(int j=1;j<=h1;j++) scanf("%d",&G1[i][j]) ;
    int h2,w2,st2x,st2y ; scanf("%d%d%d%d",&h2,&w2,&st2x,&st2y) ;
    for(int i=1;i<=w2;i++) for(int j=1;j<=h2;j++) scanf("%d",&G2[i][j]) ;
    dijkstra(G1,h1,w1,st1y,st1x,d1) ;
    dijkstra(G2,h2,w2,st2y,st2x,d2) ;

    tmp1.push_back(0) ;
    for(int i=1;i<=w1;i++) for(int j=1;j<=h1;j++) tmp1.push_back(d1[i][j]) ;
    sort(tmp1.begin(),tmp1.end()) ;
    tmp1.resize(unique(tmp1.begin(),tmp1.end())-tmp1.begin()) ;

    tmp2.push_back(0) ;
    for(int i=1;i<=w2;i++) for(int j=1;j<=h2;j++) tmp2.push_back(d2[i][j]) ;
    sort(tmp2.begin(),tmp2.end()) ;
    tmp2.resize(unique(tmp2.begin(),tmp2.end())-tmp2.begin()) ;

    int n1=tmp1.size() , n2=tmp2.size() ;
    cnt1[0]=0 ;
    for(int i=1;i<=w1;i++) for(int j=1;j<=h1;j++)
        cnt1[find_in_v(d1[i][j],tmp1)]++ ;
    for(int i=1;i<n1;i++) cnt1[i]+=cnt1[i-1] ;

    cnt2[0]=0 ;
    for(int i=1;i<=w2;i++) for(int j=1;j<=h2;j++)
        cnt2[find_in_v(d2[i][j],tmp2)]++ ;
    for(int i=1;i<n2;i++) cnt2[i]+=cnt2[i-1] ;


    int ans=INF,j=n2-1 ;
    for(int i=0;i<n1;i++)
    {
        if(cnt1[i]+cnt2[n2-1]<n) continue ;
        while(j>0 && cnt1[i]+cnt2[j]>=n) ans=min(ans,tmp1[i]+tmp2[j]) , j-- ;
        if(j==0 && cnt1[i]>=n) ans=min(ans,tmp1[i]) ;
    }
    printf("%d\n",ans) ;
}
