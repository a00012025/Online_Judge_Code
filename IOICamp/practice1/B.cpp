#include<bits/stdc++.h>
using namespace std;

char s[200] ;
bool G[300][300] ;
int d[300][300],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;

main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s",s) ;
        int n=strlen(s) ;
        memset(G,0,sizeof(G)) ;
        int nowx=150 , nowy=150 ;
        G[nowx][nowy]=1 ;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') nowx-- ;
            if(s[i]=='R') nowx++ ;
            if(s[i]=='D') nowy-- ;
            if(s[i]=='U') nowy++ ;
            G[nowx][nowy]=1 ;
        }

        int edx=nowx , edy=nowy ;
        queue<int> q ; q.push(150) ; q.push(150) ;
        memset(d,-1,sizeof(d)) ; d[150][150]=0 ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(G[nx][ny] && d[nx][ny]==-1)
                {
                    d[nx][ny]=d[x][y]+1 ;
                    q.push(nx) ; q.push(ny) ;
                }
            }
        }
        if(d[edx][edy]==n) printf("worshik<(_ _)>\n") ;
        else printf("MADA0\n") ;
    }
}
