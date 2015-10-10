#include<stdio.h>
int a[200][200],n,m,dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
int check(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i] ;
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[x][y]<=a[nx][ny]) return 0 ;
    }
    return 1 ;
}
main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(check(i,j)) printf("%d\n",a[i][j]) ;
}
