#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int vis[1001][1001] ;
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;

bool solve()
{
    queue<int> q ;
    for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) if(vis[i][j]==3)
    {
        int num2=0 , num3=0 ;
        while(!q.empty()) q.pop() ;
        q.push(i) ; q.push(j) ; vis[i][j]=1 ; num3++ ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k] , ny=y+dy[k] ;
                if(nx<0 || nx>1000 || ny<0 || ny>1000) continue ;
                if(vis[nx][ny]!=1)
                {
                    if(vis[nx][ny]==3) num3++ ;
                    if(vis[nx][ny]==2) num2++ ;
                    vis[nx][ny]=1 ;
                    q.push(nx) ; q.push(ny) ;
                }
            }
        }
        if(num3>num2) return 0 ;
    }
    return 1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        memset(vis,0,sizeof(vis)) ;
        int n,p,q,d ; scanf("%d%d%d%d",&n,&p,&q,&d) ;
        bool no=0 ;
        for(int i=1;i<=n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ; vis[x][y]=3 ;
        }
        for(int i=1;i<=p;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ; vis[x][y]=2 ;
        }
        for(int i=1;i<=q;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            for(int j=-d;j<=d;j++) for(int k=-d;k<=d;k++)
            {
                if(abs(j)+abs(k)>d || x+j<0 || x+j>1000 || y+k<0 || y+k>1000)
                    continue ;
                if(vis[x+j][y+k]==3) no=1 ;
                vis[x+j][y+k]=1 ;
            }
        }
        if(no) printf("no\n") ;
        else if(solve()) printf("yes\n") ;
        else printf("no\n") ;
    }
}
