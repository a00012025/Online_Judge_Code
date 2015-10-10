#include<stdio.h>
#include<string.h>
int n,m,goal,st1,st2 ;
int g[20][20],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1} ;
bool vis[20][20] ;

bool dfs(int x,int y,int len)
{
    if(len==goal-1) return true ;
    for(int i=0;i<4;i++)
    {
        int nx=(x+dx[i])%n , ny=(y+dy[i])%m ;
        if(nx<0) nx+=n ;
        if(ny<0) ny+=m ;
        if(vis[nx][ny]) continue ;
        else if(g[nx][ny]==0) continue ;
        else
        {
            vis[nx][ny]=1 ;
            if(g[nx][ny]==1)
            {
                if(dfs(nx,ny,len+1)) return true ;
            }
            else if(g[nx][ny]==100)
            {
                if(dfs(nx,ny,len)) return true ;
            }
            vis[nx][ny]=0 ;
        }
    }
    return false ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&goal) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            char c;
            scanf("%c",&c) ;
            while(c!='#' && c!='.' && c!='x' && c!='o') scanf("%c",&c);
            if(c=='#') g[i][j]=0 ;
            else if(c=='.') g[i][j]=1 ;
            else if(c=='o') g[i][j]=100 ;
            else if(c=='x') {g[i][j]=1 ; st1=i ; st2=j ;}
        }
        vis[st1][st2]=1 ;
        if(dfs(st1,st2,0)) printf("Case #%d: Fits perfectly!\n",++tc) ;
        else printf("Case #%d: Oh no, snake's too fat!\n",++tc) ;
    }
}
