#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100+10 ;

DB dp[2][maxn][maxn] ;
DB s[maxn][maxn],s2[maxn][maxn] ;
inline DB S(int x1,int y1,int x2,int y2)
{
    return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1] ;
}
inline DB S2(int x1,int y1,int x2,int y2)
{
    return s2[x2][y2]-s2[x1-1][y1-1] ;
}

int a[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    k=min(k,1000) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int m=1;m<=k;m++)
    {
        for(int i=1;i<=n+1;i++) for(int j=1;j<=n+1;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+dp[(m+1)%2][i][j] ,
            s2[i][j]=s2[i-1][j-1]+dp[(m+1)%2][i][j] ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            DB &d=dp[m%2][i][j] ; d=0 ;
            for(int x=1;x<=i;x++)
                d+=S(x,j,x+j-i-1,j)+(n-j+1-S2(x,x+j-i,x+n-j,x+n-i)) ;
            for(int x=i+1;x<=j;x++)
                d+=S(i,x,i,x+n-j) ;
            int mul=(n-j+1)*(n-j)/2+i*(i-1)/2+(j-i)*(j-i-1)/2 ;
            d+=mul*dp[(m+1)%2][i][j] ;
            d/=(n*(n+1)/2) ;
        }
    }

    DB ans=0 ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        ans+=(a[i]>a[j] ? (1-dp[k%2][i][j]) : dp[k%2][i][j]) ;
    printf("%.10f\n",ans) ;
}

