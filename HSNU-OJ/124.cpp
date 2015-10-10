#include<bits/stdc++.h>
using namespace std;
int G[105][105],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int n,m ;

queue<int> q ;
bool can[105][105],vis[105][105] ;

int BFS(int x0,int y0)
{
    while(!q.empty()) q.pop() ;
    vis[x0][y0]=1 ; q.push(x0) ; q.push(y0) ;
    vector<int> tmp ;
    int minh=10001 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        tmp.push_back(G[x][y]) ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m) continue ;
            if(can[nx][ny])
            {
                minh=min(minh,G[nx][ny]) ;
                continue ;
            }
            if(vis[nx][ny]) continue ;
            vis[nx][ny]=1 ; q.push(nx) ; q.push(ny) ;
        }
    }

    int ret=0 ;
    for(auto i : tmp) ret+=max(minh-i,0) ;
    return ret ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&G[i][j]) ;
    for(int i=1;i<=n;i++) q.push(i) , q.push(1) , q.push(i) , q.push(m) ;
    for(int i=2;i<m;i++) q.push(1) , q.push(i) , q.push(n) , q.push(i) ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        can[x][y]=1 ; vis[x][y]=1 ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m || G[nx][ny]<G[x][y]) continue ;
            if(can[nx][ny]) continue ;
            can[nx][ny]=1 ; q.push(nx) ; q.push(ny) ;
        }
    }

    int ans=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j])
        ans+=BFS(i,j) ;
    printf("%d\n",ans) ;
}
