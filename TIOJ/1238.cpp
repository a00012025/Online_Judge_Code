#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

char G[maxn][maxn] ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n ;
bool vis[maxn][maxn] ;

bool solve()
{
    int x0=-1,y0=-1 ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        if(G[i][j]=='x') x0=i , y0=j ;
    if(x0==-1) return 1 ;

    queue<int> q ;
    q.push(x0) ; q.push(y0) ; vis[x0][y0]=1 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<0||nx>=n||ny<0||ny>=n) continue ;
            if(G[nx][ny]=='#' || vis[nx][ny]) continue ;
            vis[nx][ny]=1 ;
            q.push(nx) ; q.push(ny) ;
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        if(G[i][j]=='x' && !vis[i][j]) return 0 ;
    return 1 ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    if(solve()) printf("Strong!\n") ;
    else printf("Weak!\n") ;
}
