#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

int n,a[4001] ;
int ans[100][100] ;
int dis[100][100] ;

int Floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
    int ret=0 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        ret=max(ret,dis[i][j]) ;
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1) ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=n;k++) for(int l=1;l<=n;l++)
                dis[k][l]= (k==l ? 0 : INF) ;
            for(int k=1;k<n;k++)
                dis[k][k+1]=dis[k+1][k]=a[k+1]-a[k] ;
            dis[i][j]=dis[j][i]=0 ;
            ans[i][j]=Floyd() ;
//            printf("ans[%d][%d]=%d\n",i,j,ans[i][j]) ;
        }

        int i0,j0,M=INF ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            if(ans[i][j]<M)
        {
            M=ans[i][j] ;
            i0=i ; j0=j ;
        }
        printf("build %d~%d , val=%d\n",i0,j0,M) ;
    }
}
