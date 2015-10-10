#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

inline void norm(vector<int> &u)
{
    sort(u.begin(),u.end()) ;
    u.resize(unique(u.begin(),u.end())-u.begin()) ;
}
inline int id(const vector<int> &u,int x)
{
    return lower_bound(u.begin(),u.end(),x)-u.begin() ;
}

vector<int> v[maxn],vx,vy ;
inline void join(int x,int y)
{
    v[x].push_back(y) ;
    v[y].push_back(x) ;
}

int sx,sy ;
bool vis[maxn] ;
void dfs(int x)
{
    vis[x]=1 ;
    for(auto i : v[x]) if(!vis[i]) dfs(i) ;
}

int n ;
struct ret{int x1,x2,y1,y2 ;}r[maxn];

bool ri[100][100],up[100][100] ;
void solve()
{
    for(int i=0;i<maxn;i++) v[i].clear() ;
    vx.clear() ; vy.clear() ;
    memset(vis,0,sizeof(vis)) ;
    memset(ri,0,sizeof(ri)) ;
    memset(up,0,sizeof(up)) ;
    for(int i=0;i<n;i++)
    {
        int x1,x2,y1,y2 ; scanf("%d%d%d%d",&x1,&y2,&x2,&y1) ;
        r[i]=(ret){x1,x2,y1,y2} ;
        vx.push_back(x1) ;
        vx.push_back(x2) ;
        vy.push_back(y1) ;
        vy.push_back(y2) ;
    }
    norm(vx) ; norm(vy) ;
    sx=vx.size() , sy=vy.size() ;
    int m=(sx-1)*(sy-1)+1 ;
    for(int i=0;i<n;i++)
    {
        int x1,x2,y1,y2 ;
        x1=id(vx,r[i].x1) ; x2=id(vx,r[i].x2) ;
        y1=id(vy,r[i].y1) ; y2=id(vy,r[i].y2) ;
        for(int j=x1;j<x2;j++) ri[j][y1]=ri[j][y2]=1 ;
        for(int j=y1;j<y2;j++) up[x1][j]=up[x2][j]=1 ;
    }

    for(int i=0;i<sx-2;i++) for(int j=0;j<sy-1;j++)
        if(!up[i+1][j]) join(j*(sx-1)+i+1,j*(sx-1)+i+2) ;
    for(int i=0;i<sx-1;i++) for(int j=0;j<sy-2;j++)
        if(!ri[i][j+1]) join(j*(sx-1)+i+1,j*(sx-1)+i+sx) ;
    for(int i=0;i<sx-1;i++)
    {
        if(!ri[i][0]) join(i+1,0) ;
        if(!ri[i][sy-1]) join((sy-2)*(sx-1)+i+1,0) ;
    }
    for(int i=0;i<sy-1;i++)
    {
        if(!up[0][i]) join(i*(sx-1)+1,0) ;
        if(!up[sx-1][i]) join(i*(sx-1)+sx-1,0) ;
    }

    int ans=0 ;
    for(int i=0;i<m;i++) if(!vis[i])
        ans++ , dfs(i) ;
    printf("%d\n",ans) ;
}

main()
{
    while(scanf("%d",&n)==1 && n) solve() ;
}
