#include<bits/stdc++.h>
#define MAX(x,y,z) max(x,max(y,z))
using namespace std;
int a[1502][1502],sum[1502][1502] ;
int G[6][1502][1502] ;

void cal(int n,int m)
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        G[0][i][j]=MAX(a[i][j],G[0][i-1][j],G[0][i][j-1]) ;
    for(int i=1;i<=n;i++) for(int j=m;j>=1;j--)
        G[1][i][j]=MAX(a[i][j],G[1][i-1][j],G[1][i][j+1]) ;
    for(int i=n;i>=1;i--) for(int j=m;j>=1;j--)
        G[2][i][j]=MAX(a[i][j],G[2][i+1][j],G[2][i][j+1]) ;
    for(int i=n;i>=1;i--) for(int j=1;j<=m;j++)
        G[3][i][j]=MAX(a[i][j],G[3][i+1][j],G[3][i][j-1]) ;
    for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
    {
        if(i==j)
        {
            G[4][i][i]=0 ;
            for(int z=1;z<=m;z++) G[4][i][i]=max(G[4][i][i],a[i][z]) ;
        }
        else G[4][i][j]=max(G[4][i][j-1],G[4][i+1][j]) ;
    }
    for(int i=m;i>=1;i--) for(int j=i;j<=m;j++)
    {
        if(i==j)
        {
            G[5][i][i]=0 ;
            for(int z=1;z<=n;z++) G[5][i][i]=max(G[5][i][i],a[z][i]) ;
        }
        else G[5][i][j]=max(G[5][i][j-1],G[5][i+1][j]) ;
    }
}

main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=0;i<=n;i++) sum[i][0]=0 ;
    for(int i=0;i<=m;i++) sum[0][i]=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        int x ; scanf("%d",&x) ;
        sum[i][j]=(sum[i-1][j]-sum[i-1][j-1])+sum[i][j-1]+x ;
    }
    for(int i=1;i<=n-k+1;i++) for(int j=1;j<=m-k+1;j++)
        a[i][j]=(sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1])+sum[i-1][j-1] ;

    cal(n-k+1,m-k+1) ;

    int ans=0 ;
    for(int i=k;i<=n-k;i++) for(int j=k;j<=m-k;j++)
    {
        ans=max(ans,G[0][i-k+1][j-k+1]+G[1][i-k+1][j+1]+G[2][i+1][1]) ;
        ans=max(ans,G[1][i-k+1][j+1]+G[2][i+1][j+1]+G[0][n-k+1][j-k+1]) ;
        ans=max(ans,G[2][i+1][j+1]+G[3][i+1][j-k+1]+G[0][i-k+1][m-k+1]) ;
        ans=max(ans,G[3][i+1][j-k+1]+G[0][i-k+1][j-k+1]+G[2][1][j+1]) ;
    }
    for(int i=k;i+2*k<=n;i++) for(int j=i+k;j+k<=n;j++)
        ans=max(ans,G[4][1][i-k+1]+G[4][i+1][j-k+1]+G[4][j+1][n-k+1]) ;
    for(int i=k;i+2*k<=m;i++) for(int j=i+k;j+k<=m;j++)
        ans=max(ans,G[5][1][i-k+1]+G[5][i+1][j-k+1]+G[5][j+1][m-k+1]) ;
    printf("%d\n",ans) ;
}
