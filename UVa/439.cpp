#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int> q ;
int dx[10]={2,1,-1,-2,-2,-1,1,2},dy[10]={1,2,2,1,-1,-2,-2,-1} ;
main()
{
    int lev[10][10] ;
    bool vis[10][10] ;
    char s[5],t[5] ;
    while(scanf("%s%s",s,t)!=EOF)
    {
        memset(vis,0,sizeof(vis)) ;
        while(!q.empty()) q.pop() ;
        int st1=s[0]-'a'+1 , st2=s[1]-'0' , ed1=t[0]-'a'+1 , ed2=t[1]-'0' ;
        vis[st1][st2]=1 ; lev[st1][st2]=0 ; q.push(st1) ; q.push(st2) ;
        int ans ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            if(x==ed1 && y==ed2) break ;
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx<1 || nx>8 || ny<1 || ny>8) continue ;
                if(!vis[nx][ny])
                {
                    vis[nx][ny]=1 ;
                    lev[nx][ny]=lev[x][y]+1 ;
                    q.push(nx) ; q.push(ny) ;
                }
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n",s,t,lev[ed1][ed2]);
    }
}
