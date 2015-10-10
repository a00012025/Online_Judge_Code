#include<stdio.h>
#include<queue>
using namespace std ;
int h[501][501]={0},n ;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0} ;
bool vis[501][501]={0} ;
queue<int> q ;
void height(int x,int y)
{
    h[x][y]=1 ; int cnt=0,x0=x,y0=y ;
    for(int i=2;i<=n*n;i++)
    {
        cnt++ ; y0+=cnt ;
        if(y0>=n) {x0+=y0/n ; y0=y0%n ;}
        if(x0>=n) x0=x0%n ;
        while(h[x0][y0]!=0)
        {
            y0++ ;
            if(y0>=n) {x0+=y0/n ; y0=y0%n ;}
            if(x0>=n) x0=x0%n ;
        }
        h[x0][y0]=cnt+1 ;
    }
}
bool low(int x,int y)
{
    if(y<n-1 && h[x][y+1]<h[x][y]) return false ;
    if(y>0 && h[x][y-1]<h[x][y]) return false ;
    if(x<n-1 && h[x+1][y]<h[x][y]) return false ;
    if(x>0 && h[x-1][y]<h[x][y]) return false ;
    return true ;
}
bool go(int x1,int y1,int x2,int y2)
{ // (x1,y1) ¬O§_¬y¨ì (x2,y2)
    if(h[x1][y1]<h[x2][y2]) return false ;
    if(x1>1 && h[x1-1][y1]<h[x2][y2]) return false ;
    if(x1<n-1 && h[x1+1][y1]<h[x2][y2]) return false ;
    if(y1>1 && h[x1][y1-1]<h[x2][y2]) return false ;
    if(y1<n-1 && h[x1][y1+1]<h[x2][y2]) return false ;
    return true ;
}
main()
{
    int r,c,num,ans=0,ansnum=0 ;
    scanf("%d %d %d",&n,&r,&c) ;
    height(r,c) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        if(!low(i,j)) continue ;
        vis[i][j]=1 ; num=0 ;
        while(!q.empty()) q.pop() ;
        q.push(i) ; q.push(j) ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            int y=q.front() ; q.pop() ; num++ ;
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k],ny=y+dy[k] ;
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue ;
                if(go(nx,ny,x,y) && !vis[nx][ny])
                    {q.push(nx) ; q.push(ny) ; vis[nx][ny]=1 ;}
            }
        }
        ans++ ; if(num>ansnum) ansnum=num ;
    }
    printf("%d %d\n",ans,ansnum) ;
}
