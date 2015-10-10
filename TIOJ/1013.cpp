#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
char G[20][20]=
{
    "*****************" ,
    "*...*.......**..*" ,
    "**..*....*.*.*..*" ,
    "*......*.**.**.**" ,
    "*..**...**..**.**" ,
    "**.....**..*.*..*" ,
    "*....*..........*" ,
    "*.....****.*...**" ,
    "****.*.*........*" ,
    "*****************"
} ;

int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n=10 , m=17 ;
int d[20][20] ;

void BFS(int x0,int y0,int edx,int edy)
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        d[i][j]=INF ;
    d[x0][y0]=0 ;
    queue<int> q ; q.push(x0) , q.push(y0) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(G[nx][ny]!='.' || d[nx][ny]!=INF) continue ;
            if(nx==edx && ny==edy) continue ;
            d[nx][ny]=d[x][y]+1 ;
            q.push(nx) , q.push(ny) ;
        }
    }
}

int d2[20][20],T ;
int BFS2(int x0,int y0,int edx,int edy)
{
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        d2[i][j]=INF ;
    d2[x0][y0]=0 ;
    queue<int> q ; q.push(x0) , q.push(y0) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(G[nx][ny]!='.' || d2[nx][ny]!=INF) continue ;
            if(d[nx][ny] <= T+d2[x][y]) continue ;
            d2[nx][ny]=d2[x][y]+1 ;
            q.push(nx) , q.push(ny) ;
        }
    }
    return d2[edx][edy] ;
}

main()
{
    int fx,fy ; scanf("%d%d%d",&fx,&fy,&T) ;
    int stx,sty,edx,edy ; scanf("%d%d%d%d",&stx,&sty,&edx,&edy) ;
    BFS(fx,fy,edx,edy) ;
    if(d[stx][sty]+1 <= T) { printf("Help!\n") ; return 0 ; }
    int res=BFS2(stx,sty,edx,edy) ;
    if(res==INF) printf("Help!\n") ;
    else printf("%d\n",res) ;
}
