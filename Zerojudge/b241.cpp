#include<stdio.h>
#include<queue>
#include<string.h>
#define INF 1000000000
using namespace std;
char G[20][60] ;
int lev[60][2000],dx[]={0,1,-1},dlev[]={1,2,2} ;
bool vis[60][2000] ;

bool ok(int col,int x,int y,int z)
{
    if(G[x][col]=='#' || G[y][col]=='#' || G[z][col]=='#') return 0 ;
    if(x==y || y==z || z==x) return 0 ;
    if(!(x<y && y<z)) return 0 ;
    return 1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        int st=0 ;
        for(int i=0;i<n;i++) if(G[i][m-1]=='C') {st*=10 ; st+=i ;}
        for(int i=0;i<m;i++) for(int j=0;j<1000;j++) lev[i][j]=INF ;
        memset(vis,0,sizeof(vis)) ;
        lev[m-1][st]=3 ; vis[m-1][st]=1 ;
        queue<int> q ; q.push(m-1) ; q.push(st) ;
        int ans=INF ;
        while(!q.empty())
        {
            int col=q.front() ; q.pop() ;
            int now=q.front() ; int nnow=now ; q.pop() ;
                //printf("%d , %03d\n",col,now) ;
            if(col==0) {ans=min(ans,lev[col][now]) ; continue ;}
            int z=nnow%10 ; nnow/=10 ;
            int y=nnow%10 ; nnow/=10 ;
            int x=nnow%10 ;
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++)
            {
                int nx=x+dx[i] , ny=y+dx[j] , nz=z+dx[k] ;
                if(nx<0 || ny<0 || nz<0 || nx>=n || ny>=n || nz>=n) continue ;
                if(!ok(col-1,nx,ny,nz)) continue ;
                int N=100*nx+10*ny+nz , add=dlev[i]+dlev[j]+dlev[k] ;
                if(!vis[col-1][N] || lev[col-1][N]>lev[col][now]+add)
                {
                    vis[col-1][N]=1 ;
                    lev[col-1][N]=lev[col][now]+add ;
                    q.push(col-1) ; q.push(N) ;
                }
            }
        }
        if(ans==INF) printf("Impossible\n") ;
        else printf("%d\n",ans) ;
    }
}
