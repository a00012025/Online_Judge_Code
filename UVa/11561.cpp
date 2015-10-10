#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int> q ;
int G[51][51] ;
int dx[5]={1,-1,0,0} , dy[5]={0,0,1,-1} , n,m ;
bool vis[51][51] ;

bool trap(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx>n || nx<1 || ny>m || ny<1) continue ;
        if(G[nx][ny]==-1) return 1 ;
    }
    return 0 ;
}

main()
{
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        memset(vis,0,sizeof(vis)) ;
        int st1,st2 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c;
            scanf("%c",&c) ;
            while(c!='.' && c!='#' && c!='P' && c!='G' && c!='T')
                scanf("%c",&c) ;
            if(c=='#') G[i][j]=0 ;
            else if(c=='P') {st1=i ; st2=j ; G[i][j]=1 ;}
            else if(c=='.') G[i][j]=1 ;
            else if(c=='G') G[i][j]=100 ;
            else if(c=='T') G[i][j]=-1 ;
        }
        while(!q.empty()) q.pop() ;
        q.push(st1) ; q.push(st2) ; vis[st1][st2]=1 ;
        int ans=0 ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            if(G[x][y]==100) ans++ ;
            if(trap(x,y)) continue ;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx>n || nx<1 || ny>m || ny<1) continue ;
                if(G[nx][ny] && !vis[nx][ny])
                {
                    vis[nx][ny]=1 ;
                    q.push(nx) ;
                    q.push(ny) ;
                }
            }
        }
        printf("%d\n",ans) ;
    }
}
