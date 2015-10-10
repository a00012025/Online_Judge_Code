#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

char G[maxn][maxn] ;
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;
queue<int> q ;
bool vis[maxn][maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int sx,sy,ex,ey ; scanf("%d%d%d%d",&sx,&sy,&ex,&ey) ;
    sx-- ; sy-- ; ex-- ; ey-- ;

    q.push(sx) ; q.push(sy) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(G[nx][ny]=='X' || vis[nx][ny]) continue ;
            vis[nx][ny]=1 ; q.push(nx) ; q.push(ny) ;
        }
    }

    if(G[ex][ey]=='X') for(int i=0;i<4;i++)
    {
        int nx=ex+dx[i] , ny=ey+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(vis[nx][ny] || (nx==sx&&ny==sy)) {printf("YES\n") ; return 0;}
    }
    else if(vis[ex][ey])
    {
        int cnt=0 ;
        for(int i=0;i<4;i++)
        {
            int nx=ex+dx[i] , ny=ey+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=m) continue ;
            if(vis[nx][ny] || (nx==sx&&ny==sy)) cnt++ ;
        }
        printf("%s\n",cnt>=2?"YES":"NO") ;
        return 0 ;
    }
    printf("NO\n") ;
}
