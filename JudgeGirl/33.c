#include<stdio.h>
int a[200][200] ;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1} ;
int num[5] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j])
    {
        int cnt=0,x=0 ;
        for(int d=0;d<4;d++)
        {
            int nx=i+dx[d],ny=j+dy[d] ;
            if(nx<0||nx>=n||ny<0||ny>=n||!a[nx][ny]) continue ;
            cnt++ , x|=(1<<d) ;
        }
        if(x!=5 && x!=10) num[cnt]++ ;
    }
    for(int i=4;i>0;i--) printf("%d\n",num[i]) ;
}
