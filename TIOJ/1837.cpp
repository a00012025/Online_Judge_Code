#include<bits/stdc++.h>
#define DB double
#define MAX(x,y,z) max(x,max(y,z))
#define ADD(x,y,z) (x+y+z)
using namespace std;
const int maxn=1000 ;

int ABS(int x)
{
    return x>0 ? x : -x ;
}

int a[maxn][maxn][3] ;
bool same(int x1,int y1,int x2,int y2)
{
    int x=0 ;
    for(int i=0;i<3;i++)
    {
        x+=ABS(a[x1][y1][i]-a[x2][y2][i]) ;
        if(ABS(a[x1][y1][i]-a[x2][y2][i])>10) return 0 ;
    }
    return 1 ;
}

int dif(int x1,int y1,int x2,int y2)
{
    return ADD(ABS(a[x1][y1][0]-a[x2][y2][0]),
               ABS(a[x1][y1][1]-a[x2][y2][1]),
               ABS(a[x1][y1][2]-a[x2][y2][2])) ;
}

int n,m ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;

int solve()
{
    int cnt=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        for(int k=0;k<4;k++)
    {
        int nx=i+dx[k] , ny=j+dy[k] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(!same(i,j,nx,ny)) cnt++ ;
    }

    DB ans=cnt*100.0/4.0/n/m ;
    if(ans>=64.0) return 3 ;
    if(ans>=21.0) return 2 ;

    cnt=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        for(int k=0;k<4;k++)
    {
        int nx=i+dx[k] , ny=j+dy[k] ;
        if(nx<0||nx>=n||ny<0||ny>=m) continue ;
        if(dif(i,j,nx,ny)>180) cnt++ ;
    }
    if(cnt>7000) return 1 ;
    return 4 ;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            scanf("%d%d%d",&a[i][j][0],&a[i][j][1],&a[i][j][2]) ;
        printf("%d\n",solve()) ;
    }
}
