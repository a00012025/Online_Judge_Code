#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
char G[70][70] ;
char s[4000] ;
bool vis[65][65][3605] ;
int n,m,lev[65][65][3605],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;

int solve()
{
    memset(vis,0,sizeof(vis)) ;
    queue<int> q ;
    q.push(0) ; q.push(0) ; q.push(0) ;
    lev[0][0][0]=0 ; vis[0][0][0]=1 ;
    if(s[1]==G[0][0])
    {
        q.push(0) ; q.push(0) ; q.push(1) ;
        lev[0][0][1]=0 ; vis[0][0][1]=1 ;
    }
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        int z=q.front() ; q.pop() ;
        if(s[z+1]=='\0') return lev[x][y][z]+1 ;
        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k] , ny=y+dy[k] ;
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue ;
            if(s[z+1]==' ' && G[nx][ny]==s[z+2] && (!vis[nx][ny][z+2] || lev[nx][ny][z+2]>lev[x][y][z]+1))
            {
                lev[nx][ny][z+2]=lev[x][y][z]+1 ;
                vis[nx][ny][z+2]=1 ;
                q.push(nx) ; q.push(ny) ; q.push(z+2) ;
            }

            if((G[nx][ny]==s[z+1] || s[z+1]==' ') && (!vis[nx][ny][z+1] || lev[nx][ny][z+1]>lev[x][y][z]+1) )
            {
                lev[nx][ny][z+1]=lev[x][y][z]+1 ;
                vis[nx][ny][z+1]=1 ;
                q.push(nx) ; q.push(ny) ; q.push(z+1) ;
            }

            if(s[z]==' ' && (!vis[nx][ny][z] || lev[nx][ny][z]>lev[x][y][z]+1))
            {
                lev[nx][ny][z]=lev[x][y][z]+1 ;
                vis[nx][ny][z]=1 ;
                q.push(nx) ; q.push(ny) ; q.push(z) ;
            }
        }
    }
    return -1 ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        int num ;
        scanf("%d%d%d",&n,&m,&num) ;
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        int now=0 ;
        for(int i=0;i<num;i++)
        {
            s[now]=' ' ;
            char tmp[100] ; scanf("%s",tmp) ;
            for(int j=0;j<strlen(tmp);j++) s[now+1+j]=tmp[j] ;
            s[now+1+strlen(tmp)]='\0' ;
            now += 1+strlen(tmp) ;
        }
        int ans=solve() ;
        if(ans==-1) printf("Betrayal!\n") ;
        else printf("%d\n",ans) ;
    }
}
