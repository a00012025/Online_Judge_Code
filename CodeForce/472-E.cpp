#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<cassert>
#define ABS(x) ((x)>0?(x):(-(x)))
using namespace std;
const int maxn=30+10 ;

struct P{int x,y;};

int n,m,x0,y0 ; /// now position
int G[maxn][maxn],H[maxn][maxn] ;
vector<P> ans ;
inline void push(int x,int y)
{
    ans.push_back((P){x,y}) ;
    swap(G[x0][y0],G[x][y]) ;
    x0=x ; y0=y ;
}

bool done[maxn][maxn] ;
int dx[]={0,1,1,1,0,-1,-1,-1} , dy[]={1,1,0,-1,-1,-1,0,1} ;
int gx , gy , ax , ay ;
bool vis[maxn][maxn] ;
bool dfs(int x,int y,vector<P> &v)
{
    vis[x][y]=1 ;
    if(x==gx&&y==gy) {vis[x][y]=0 ; return 1 ;}
    int val=1e5 ;
    vector<P> son ;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m||(nx==ax&&ny==ay)) continue ;
        if(done[nx][ny]||vis[nx][ny]) continue ;
        int nval=ABS(nx-gx)+ABS(ny-gy) ;
        if(nval<val)
            val=nval , son.clear() , son.push_back((P){nx,ny}) ;
        else if(nval==val) son.push_back((P){nx,ny}) ;
    }
    for(auto i : son)
    {
        v.push_back(i) ;
        if(dfs(i.x,i.y,v)){vis[x][y]=0 ; return 1 ;}
        v.pop_back() ;
    }
    vis[x][y]=0 ;
    return 0 ;
}

void getpath(int x1,int y1,int x2,int y2,int avx,int avy,vector<P> &v)
{ /// (x1,y1) -> (x2,y2) , avoid (avx,avy)
    v.clear() ;
    gx=x2 ; gy=y2 ;
    ax=avx ; ay=avy ;
    dfs(x1,y1,v) ;
    return ;
}

vector<P> pth ;
void Goto(int x,int y,int avx,int avy)
{ /// now position go to (x,y) , avoid (avx,avy)
    getpath(x0,y0,x,y,avx,avy,pth) ;
    for(auto i : pth) push(i.x,i.y) ;
}

vector<P> tmp ;
void Moveto(int x1,int y1,int x2,int y2)
{ /// move the orb at (x1,y1) to (x2,y2)
    getpath(x1,y1,x2,y2,-1,-1,tmp) ;
    for(auto i : tmp)
    {
        Goto(i.x,i.y,x1,y1) ;
        push(x1,y1) ;
        x1=i.x ; y1=i.y ;
    }
}

int a[maxn],b[maxn],num[maxn*maxn] ;
void solve1()
{
    if(n==1&&m==1){printf("-1\n") ; return ;}
    if(n==1) for(int i=0;i<m;i++) a[i]=G[0][i] , b[i]=H[0][i] ;
    else for(int i=0;i<n;i++) a[i]=G[i][0] , b[i]=H[i][0] ;
    int w=n*m ;
    for(int i=0;i<w;i++) for(int j=0;j<w;j++) if(i!=j)
    {
        int d=(i<j ? 1 : -1) ;
        for(int k=i;k!=j;k+=d) swap(a[k],a[k+d]) ;
        bool ok=1 ;
        for(int k=0;k<w;k++) if(a[k]!=b[k]){ok=0 ; break ;}
        if(!ok)
        {
            for(int k=j-d;k!=i-d;k-=d) swap(a[k],a[k+d]) ;
            continue ;
        }
        printf("%d\n",(j-i)/d) ;
        for(int k=i;;k+=d)
        {
            printf("%d %d\n",n==1?1:k+1,m==1?1:k+1) ;
            if(k==j) return ;
        }
    }
    printf("-1\n") ; return ;
}

bool check()
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        num[G[i][j]]++ , num[H[i][j]]-- ;
    for(int i=0;i<=900;i++) if(num[i]) return 0 ;
    return 1 ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        scanf("%d",&G[i][j]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        scanf("%d",&H[i][j]) ;
    if(n==1 || m==1){solve1() ; return 0 ;}
    if(!check()){printf("-1\n") ; return 0 ;}

    for(int i=0;i<n*m;i++) if(G[i/m][i%m]==H[n-1][m-1])
        {x0=i/m ; y0=i%m ; break ;}
    push(x0,y0) ;

    for(int i=0;i<n-2;i++) for(int j=0;j<m;j++)
    {
        if(G[i][j]==H[i][j] && (x0!=i || y0!=j))
            {done[i][j]=1 ; continue ;}
        for(int x=i,y=j;;)
        {
            y++ ;
            if(y==m) x++ , y=0 ;
            if(G[x][y]==H[i][j] && (x0!=x||y0!=y))
                {Moveto(x,y,i,j) ; break ;}
        }
        done[i][j]=1 ;
    }
    for(int j=0;j<m;j++) for(int i=n-2;i<n;i++)
    {
        if(i==n-1&&j==m-1) break ;
        if(G[i][j]==H[i][j] && (x0!=i || y0!=j))
            {done[i][j]=1 ; continue ;}
        for(int x=i,y=j;;)
        {
            x++ ;
            if(x==n) y++ , x=n-2 ;
            if(G[x][y]==H[i][j] && (x0!=x||y0!=y))
                {Moveto(x,y,i,j) ; break ;}
        }
        done[i][j]=1 ;
    }

    printf("%d\n",ans.size()-1) ;
    for(auto i : ans) printf("%d %d\n",i.x+1,i.y+1) ;
}
