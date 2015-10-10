#include<stdio.h>

int n,m,G[110][110] ;
int getnum(int x,int y)
{
    if(x==-1) return 2*m+n-1-y ;
    if(y==-1) return x+2*m+n ;
    if(x==n) return y ;
    return n+m-1-x ;
}

int x,y,dir ;
void getxy(int num)
{
    if(num<m) x=n , y=num , dir=2 ;
    else if(num<n+m) x=n+m-1-num , y=m , dir=1 ;
    else if(num<n+2*m) x=-1 , y=2*m+n-1-num , dir=0 ;
    else x=num-2*m-n , y=-1 , dir=3 ; 
}

int dx[]={1,0,-1,0},dy[]={0,-1,0,1} ;
main()
{
    scanf("%d%d",&m,&n) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&G[i][j]) ;
    for(int i=0;i<2*(m+n);i++)
    {
        getxy(i) ;
        do x+=dx[dir] , y+=dy[dir] , dir^=G[x][y] ;
        while(x>=0&&x<n&&y>=0&&y<m) ;
        printf("%d\n",getnum(x,y)) ;
    }
}
