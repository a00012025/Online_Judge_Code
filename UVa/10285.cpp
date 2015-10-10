#include<stdio.h>
#include<algorithm>
#include<queue>
const int INF=100000000 ;
using namespace std;
int G[101][101],n,m ;
int dx[5]={1,-1,0,0} , dy[5]={0,0,1,-1} ;

bool high(int x,int y)
{
    if(x>1 && G[x][y]<G[x-1][y]) return 0;
    if(x<n && G[x][y]<G[x+1][y]) return 0;
    if(y>1 && G[x][y]<G[x][y-1]) return 0;
    if(y<m && G[x][y]<G[x][y+1]) return 0;
    return 1 ;
}

int find_far(int st1,int st2)
{
    queue<int> q ;
    int d[101][101],vis[101][101]={{0}} ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) d[i][j]=-INF ;
    d[st1][st2]=1 ; q.push(st1) ; q.push(st2) ; vis[st1][st2]=1 ;
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i] , ny=y+dy[i] ;
            if(nx<1 || nx>n || ny<1 || ny>m) continue ;
            if(d[nx][ny]<d[x][y]+1 && G[nx][ny]<G[x][y])
                {vis[nx][ny]=1 ; d[nx][ny]=d[x][y]+1 ; q.push(nx) ; q.push(ny) ;}
        }
    }
    int ret=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(d[i][j]!=-INF) ret=max(ret,d[i][j]) ;
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[100] ;
        int ans=0 ;
        scanf("%s%d%d",s,&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&G[i][j]) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            if(high(i,j)) ans=max(ans,find_far(i,j)) ;
        printf("%s: %d\n",s,ans) ;
    }
}
