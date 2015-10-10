#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
char G[maxn][maxn] ;
int d[maxn][maxn],n,m ;

void place(int x1,int y1,int x2,int y2)
{
    if(x1==x2)
    {
        if(y1>y2) G[x1][y1]='>' , G[x2][y2]='<' ;
        else G[x1][y1]='<' , G[x2][y2]='>' ;
    }
    else if(x1>x2) G[x1][y1]='v' , G[x2][y2]='^' ;
    else G[x1][y1]='^' , G[x2][y2]='v' ;
}

queue<int> q ;

void remove(int x,int y)
{
    for(int z=0;z<4;z++)
    {
        int nx=x+dx[z]  , ny=y+dy[z] ;
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue ;
        if(G[nx][ny]!='.') continue ;
        if((--d[nx][ny])==1) q.push(nx) , q.push(ny) ;
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    bool no=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]=='.')
    {
        for(int z=0;z<4;z++)
        {
            int nx=i+dx[z]  , ny=j+dy[z] ;
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue ;
            if(G[nx][ny]=='.') d[i][j]++ ;
        }
        if(d[i][j]==1) q.push(i) , q.push(j) ;
        if(!d[i][j]) no=1 ;
    }
    while(!no && !q.empty())
    {
        int x=q.front() ; q.pop() ;
        int y=q.front() ; q.pop() ;
        if(G[x][y]!='.') continue ;

        bool found=0 ;
        for(int z=0;z<4;z++)
        {
            int nx=x+dx[z]  , ny=y+dy[z] ;
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue ;
            if(G[nx][ny]=='.')
            {
                place(x,y,nx,ny) ;
                remove(nx,ny) ;
                found=1 ;
                break ;
            }
        }
        if(!found) no=1 ;
    }

    if(no) { printf("Not unique\n") ; return 0 ; }

    bool uni=1 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(G[i][j]=='.') uni=0 ;
    if(!uni) printf("Not unique\n") ;
    else for(int i=0;i<n;i++) printf("%s\n",G[i]) ;
}
