#include<bits/stdc++.h>
using namespace std;
struct P{int x,y;};

int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
char G[1000][1000] ;
bool vis[1000][1000] ;

P operator - (const P &a,const P &b) { return (P){a.x-b.x,a.y-b.y} ; }
int cross(P a,P b){ return a.x*b.y - a.y*b.x ; }
int cross(P a,P b,P c){ return cross(b-a,c-a) ; }

int area(const vector<P> &p)
{
    int ret=0 ;
    for(int i=1;i+1<p.size();i++) ret+=cross(p[0],p[i],p[i+1]) ;
    return ret>0 ? ret/2 : -ret/2 ;
}

vector<P> p ;
main()
{
    int n=0,m ;
    while(scanf("%s",G[n++])!=EOF) ;
    m=strlen(G[0]) ;
    int sx=-1,sy=-1 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(G[i][j]=='+') sx=i , sy=j ;
    if(sx==-1) { printf("0\n") ; return 0 ; }
    vis[sx][sy]=1 ; p.push_back((P){sx,sy}) ;
    for(int x=sx,y=sy;;)
    {
        int dir ;
        for(dir=0;dir<4;dir++)
        {
            int nx=x+dx[dir] , ny=y+dy[dir] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(G[nx][ny]=='.') continue ;
            while(G[nx][ny]!='+')
            {
                nx+=dx[dir] , ny+=dy[dir] ;
                if(nx<0||nx>=n||ny<0||ny>=m) break ;
            }
            if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]) continue ;
            vis[nx][ny]=1 ;
            x=nx ; y=ny ;
            break ;
        }
        if(dir==4) break ;
        p.push_back((P){x,y}) ;
    }
    printf("%d\n",area(p)) ;
}
