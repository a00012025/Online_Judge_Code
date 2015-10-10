#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;

int dx[12][2]={{-1,-1},{0,-1},{0,1},{1,1},{1,1},{0,1},{0,-1},{-1,-1},{-1,0},{0,1},{1,0},{0,-1}} ;
int dy[12][2]={{0,-1},{-1,-1},{-1,-1},{0,-1},{0,1},{1,1},{1,1},{0,1},{0,-1},{-1,0},{0,1},{1,0}} ;

int n,m ;
char G[maxn][maxn] ;
bool check(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m && G[x][y]=='.' ;
}

bool vis[maxn][maxn] ;

queue<int> q ;

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++)
    {
        scanf("%s",G[i]) ;
        for(int j=0;j<m;j++) if(G[i][j]=='.')
            vis[i][j]=1 , q.push(i) , q.push(j) ;
    }
    while(!q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        for(int i=0;i<12;i++)
        {
            int x1=x+dx[i][0] , y1=y+dy[i][0] ;
            int x2=x+dx[i][1] , y2=y+dy[i][1] ;
            if(!check(x1,y1) || !check(x2,y2)) continue ;
            int x3,y3 ;
            if(i<8) x3=x+x2-x1 , y3=y+y2-y1 ;
            else x3=x1+x2-x , y3=y1+y2-y ;
            if(!vis[x3][y3])
                vis[x3][y3]=1 , G[x3][y3]='.' ,
                q.push(x3) , q.push(y3) ;
        }
    }
    for(int i=0;i<n;i++) printf("%s\n",G[i]) ;
}
