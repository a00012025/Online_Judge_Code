#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;

int d[51][51][51][51] ;
int a[51][51],sum[51][51] ;

int cal(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1] ;
}

int dp(int x1,int y1,int x2,int y2)
{
    if(d[x1][y1][x2][y2]!=-1) return d[x1][y1][x2][y2] ;
    if(x1==x2 && y1==y2) return 0 ;
    int &ans=d[x1][y1][x2][y2] ; ans=INF ;
    int s=cal(x1,y1,x2,y2) ;
    for(int i=x1;i<x2;i++) ans=min(ans,s+dp(x1,y1,i,y2)+dp(i+1,y1,x2,y2)) ;
    for(int i=y1;i<y2;i++) ans=min(ans,s+dp(x1,y1,x2,i)+dp(x1,i+1,x2,y2)) ;
    return ans ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]) ,
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j] ;
    memset(d,-1,sizeof(d)) ;
    printf("%d\n",dp(1,1,n,m)) ;
}
