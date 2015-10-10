#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101][101],sum[101][101] ;

int SUM(int x,int y,int z,int w)
{
    return sum[z][w]-sum[z][y-1]-sum[x-1][w]+sum[x-1][y-1] ;
}

int cal(int *b,int n)
{
    int sum=0 , minsum=0 ,ans=-2147483647 ;
    for(int i=0;i<n;i++)
    {
        sum+=b[i] ;
        ans=max(ans,sum-minsum) ;
        minsum=min(minsum,sum) ;
    }
    return ans ;
}

main()
{
    int n;
    scanf("%d",&n) ;
    memset(sum,0,sizeof(sum)) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]) ;
        sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
    }
    int ans=-2147483647,b[101] ;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
    {
        for(int k=0;k<n;k++) b[k]=SUM(i,k+1,j,k+1) ;
        ans=max(ans,cal(b,n)) ;
    }
    printf("%d\n",ans) ;
}
